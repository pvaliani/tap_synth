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
    
    bool canPlaysound (juce::SynthesiserSound* sound);
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) override;
    void stopNote (float velocity, bool allowTailOff) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    void renderNextBlock (juce::AudioBuffer < float > &outputBuffer, int startSample, int numSamples) override;
    
    
private:
    
};
