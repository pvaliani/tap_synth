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
    
};

void SynthVoice::stopNote (float velocity, bool allowTailOff) {
    
};


void SynthVoice::controllerMoved (int controllerNumber, int newControllerValue) {
    
};

void SynthVoice::renderNextBlock (juce::AudioBuffer < float > &outputBuffer, int startSample, int numSamples) {
    
};

void SynthVoice::pitchWheelMoved (int newPitchWheelValue) {
    
};
