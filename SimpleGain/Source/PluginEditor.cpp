/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleGainAudioProcessorEditor::SimpleGainAudioProcessorEditor (SimpleGainAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(gainFader);
    gainFader.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);

    gainAttachment.reset(
        new juce::AudioProcessorValueTreeState::SliderAttachment(
        vts, "gain", gainFader)
    );

    gainFader.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 30);
    gainFader.setRange(-24.0, 24.0, 0.5);
    gainFader.setColour(juce::Slider::ColourIds::rotarySliderFillColourId ,juce::Colour::fromRGB(171, 55, 48));
    gainFader.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::white);
    gainFader.setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::white);
    gainFader.setColour(juce::Slider::ColourIds::textBoxTextColourId, juce::Colours::white);
    gainFader.setDoubleClickReturnValue(true, 0);
    DBG("init UI");




    addAndMakeVisible(gainText);
    gainText.setText("Gain", juce::dontSendNotification);
    gainText.attachToComponent(&gainFader, false);
    gainText.setJustificationType(juce::Justification::centred);
    gainText.setBorderSize(juce::BorderSize(10));
    gainText.setFont(juce::Font(20));

    addAndMakeVisible(border);
    border.setBounds(10, 10, 280, 280);

    setSize (300, 300);


}

SimpleGainAudioProcessorEditor::~SimpleGainAudioProcessorEditor()
{
}

//==============================================================================
void SimpleGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black.brighter(0.32));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void SimpleGainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    gainFader.setBounds(75, 85, 150, 150);
}

