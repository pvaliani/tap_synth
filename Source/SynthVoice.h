/*
  ==============================================================================

    SynthVoice.h
    Created: 29 Mar 2021 7:38:18pm
    Author:  Pedram Valiani

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice {
    
public:
    
    bool canPlaySound (juce::SynthesiserSound* sound) override;
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) override;
    void stopNote (float velocity, bool allowTailOff) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    
    void renderNextBlock (juce::AudioBuffer < float > &outputBuffer, int startSample, int numSamples) override;
    void pitchWheelMoved (int newPitchWheelValue) override;
    
    
    
private:
    
    //    declare an oscillator in the dsp namespace
//    declare a gain controller with a gain value to adjust the overall signal volume
    
//    standard sin wave equation
//    juce::dsp::Oscillator<float> osc { [](float x) {return std::sin(x);}};
    
//    saw wave equation
//    juce::dsp::Oscillator<float> osc { [](float x) {return x / juce::MathConstants<float>::pi;}};
    
//    square wave equation
    
    juce::ADSR adsr;
    juce::ADSR::Parameters adsrParams;
    
    juce::dsp::Oscillator<float> osc { [](float x) {return x < 0.0f ? -1.0f : 1.0f;}, 200};
    
    juce::dsp::Gain<float> gain;
    
    bool isPrepared {false};
    
};

