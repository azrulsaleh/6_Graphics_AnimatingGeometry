/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
    setFramesPerSecond (60);
        //setFramesPerSecond (24);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::update()
{
    // This function is called at the frequency specified by the setFramesPerSecond() call
    // in the constructor. You can use it to update counters, animate values, etc.
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    //Circular motion
        //g.setColour (getLookAndFeel().findColour (Slider::thumbColourId));
        //int radius = 150;
        //Point<float> p ((getWidth()  / 2.0f) + (1.0f * radius) * std::sin (getFrameCounter() * 0.04f),
                        //(getHeight() / 2.0f) + (1.0f * radius) * std::cos (getFrameCounter() * 0.04f));
        //g.fillEllipse(p.x, p.y, 30.0f, 30.0f);
    
    g.setColour (getLookAndFeel().findColour (Slider::thumbColourId));
    auto numberOfDots = 15;
    Path spinePath;
    for (auto i = 0; i < numberOfDots; ++i)
    {
        int radius = 150;
        Point<float> p ((getWidth()  / 2.0f) + (1.0f * radius) * std::sin ((getFrameCounter() * 0.04f) + (i * 0.12f)),
                        (getHeight() / 2.0f) + (1.0f * radius) * std::cos ((getFrameCounter() * 0.04f) + (i * 0.12f)));
        if (i == 0)
            spinePath.startNewSubPath(p);
        else
            spinePath.lineTo(p);
    }
    g.strokePath(spinePath, PathStrokeType(4.0f));
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
