/*
  ==============================================================================

    SynthSound.h
    Created: 29 Mar 2021 7:38:38pm
    Author:  Pedram Valiani

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
    
public:
    
//  need to implement these pure virtual functions for this juce class
    
    bool appliesToNote (int midiNoteNumber) override{ return true;}
    
    bool appliesToChannel (int midiChannel) override {return true;}
    
};

