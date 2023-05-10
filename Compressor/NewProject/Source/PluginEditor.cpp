/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(gain);
    addAndMakeVisible(gainText);
    gain.setRange(-12.0f, 12.0f, 0.1f);
    buildSlider(gain, gainText);
    gainText.setText("Gain", juce::dontSendNotification);
    gainAttachment.reset(
        new juce::AudioProcessorValueTreeState::SliderAttachment(
            vts, "gain", gain)
    );


    addAndMakeVisible(treshold);
    addAndMakeVisible(tresholdText);
    treshold.setRange(-60.0f, 10.0f, 0.1f);
    buildSlider(treshold, tresholdText);
    tresholdText.setText("Treshold", juce::dontSendNotification);
    tresholdAttachment.reset(
        new juce::AudioProcessorValueTreeState::SliderAttachment(
            vts, "treshold", treshold)
    );


    addAndMakeVisible(attack);
    addAndMakeVisible(attackText);
    attack.setRange(1.0f, 200.0f, 1.0f);
    buildSlider(attack, attackText);
    attackText.setText("Attack", juce::dontSendNotification);
    attackAttachment.reset(
        new juce::AudioProcessorValueTreeState::SliderAttachment(
            vts, "attack", attack)
    );


    addAndMakeVisible(release);
    addAndMakeVisible(releaseText);
    release.setRange(1.0f, 200.0f, 1.0f);
    buildSlider(release, releaseText);
    releaseText.setText("Release", juce::dontSendNotification);
    releaseAttachment.reset(
        new juce::AudioProcessorValueTreeState::SliderAttachment(
            vts, "release", release)
    );

   
    setSize (600, 400);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::black.brighter(0.32));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void NewProjectAudioProcessorEditor::buildSlider(juce::Slider& slider, juce::Label& label) {
    slider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    slider.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colour::fromRGB(171, 55, 48));
    slider.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::white);
    slider.setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::white);
    slider.setColour(juce::Slider::ColourIds::textBoxTextColourId, juce::Colours::white);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);


    label.attachToComponent(&slider, false);
    label.setJustificationType(juce::Justification::centred);
    label.setBorderSize(juce::BorderSize(5));
    label.setFont(juce::Font(20));
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    int sliderSize = 125;
    gain.setBounds(50,50,sliderSize, sliderSize);
    treshold.setBounds(sliderSize + 50, 50, sliderSize, sliderSize);
    attack.setBounds(50, sliderSize + 100, sliderSize, sliderSize);
    release.setBounds(sliderSize + 50, sliderSize + 100, sliderSize, sliderSize);
}
