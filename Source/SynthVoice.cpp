/*
  ==============================================================================

    SynthVoice.cpp
    Created: 29 Mar 2021 7:38:18pm
    Author:  Pedram Valiani

  ==============================================================================
*/

#include "SynthVoice.h"

// will return true if we have a sound loaded up

bool SynthVoice::canPlaySound (juce::SynthesiserSound* sound){
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
};

void SynthVoice::startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) {
    
    adsr.noteOn();
    osc.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    
};

void SynthVoice::stopNote (float velocity, bool allowTailOff) {
    adsr.noteOff();
};


void SynthVoice::controllerMoved (int controllerNumber, int newControllerValue) {
    
};

void SynthVoice::renderNextBlock (juce::AudioBuffer < float > &outputBuffer, int startSample, int numSamples) {
    jassert(isPrepared);
    
//    audio in the audioBlock is also in the outputBuffer
//    audioBlock IS THE outputBuffer and the outputBuffer is just a reference
    
    juce::dsp::AudioBlock<float> audioBlock { outputBuffer };
    osc.process((juce::dsp::ProcessContextReplacing<float>) (audioBlock));
    gain.process((juce::dsp::ProcessContextReplacing<float>) (audioBlock));
    
    adsr.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);
    
};

void SynthVoice::pitchWheelMoved (int newPitchWheelValue) {
    
};

void SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels) {
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
//  declare spec as an object under the dsp::ProcessSpec namespace which defines
//  max samples per block, sample rate for processing and the number of output channels
// the prepare method is then invoked on the spec in relation to the oscillator
    adsr.setSampleRate(sampleRate);
    
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    
    osc.prepare(spec);
    gain.prepare(spec);
    
//  set the frequency and gain of the oscillator here using their object parameters. The osc
//  and gain are initialised in the header file
    
   
    gain.setGainLinear(0.01f);
    
    isPrepared = true;
};
