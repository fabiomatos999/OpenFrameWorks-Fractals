#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    createNewDrawModes();
    ofSetWindowTitle("Fractals");
}

//--------------------------------------------------------------
void ofApp::update()
{
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0, 0, 0);
    modechartoint();

    waitTime = ofGetElapsedTimeMillis();

    if (PressedSpace == true && counter == 0)
    {

        currentTime = ofGetElapsedTimeMillis();
        counter++;
    }

    if (PressedSpace == true)
    {
        if ((waitTime - currentTime) > 500 && counter >= 1)
        {
            counter = 0;
            if (level == 0)
            {
                ForwardDirection = true;
                LeftDirection = false;
            }
            if (ForwardDirection)
            {
                level++;
                modes.clear();
                createNewDrawModes();
            }
            if (level == 10)
            {
                ForwardDirection = false;
                LeftDirection = true;
            }
            if (LeftDirection)
            {
                level--;
                modes.clear();
                createNewDrawModes();
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();
    activateMode();
}

void ofApp::DrawMode0(){
    
    ofSetColor(255,0,0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofDrawBitmapString("Menu", -100, -350);
    ofDrawBitmapString("For circle draw mode press \"1\" ", -100, -300);
    ofDrawBitmapString("For branches draw mode press \"2\" ", -100, -250);
    ofDrawBitmapString("For Sierpiński triangle draw mode press \"3\" ", -100, -200);
    ofDrawBitmapString("For clock draw mode press \"4\" ", -100, -150);
    ofDrawBitmapString("For circle square draw mode press \"5\" ", -100, -100);
    ofDrawBitmapString("For overlay draw mode press \"6\" ", -100, -50);
    ofDrawBitmapString("Press \'U\' for circle draw mode", -75, 0);
    ofDrawBitmapString("Press \'I\' for branches draw mode", -75, 50);
    ofDrawBitmapString("Press \'O\' for Sierpiński triangle draw mode", -75, 100);
    ofDrawBitmapString("Press \'P\' for custom draw mode", -75, 150);
    ofDrawBitmapString("Press \'Y\' for clock draw mode", -75, 200);
    ofDrawBitmapString("Press \'R\' to reset overlay mode", -75, 250);
    ofDrawBitmapString("Press \'0\' to go back to the menu", -100, 300);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    // This method is called automatically when any key is pressed
    switch (key)
    {
    case '0':
        mode = '0';
        break;
    case '1':
        mode = '1';
        break;
    case '2':
        mode = '2';
        break;
    case '3':
        mode = '3';
        break;
    case '4':
        mode = '4';
        break;
    case '5':
        mode = '5';
        break;
    case '6':
        mode = '6';
        break;
    case 'u':
        pressedU = true;
        break;
    case 'i':
        pressedI = true;
        break;
    case 'o':
        pressedO = true;
        break;
    case 'p':
        pressedP = true;
        break;
    case 'y':
        pressedY = true;
        break;
    case 'r':
        if (mode != 1 || mode != 2 || mode != 3 || mode != 4)
        {
            resetDrawMode5();
        }
        break;
    case '=':
        if (level < 10)
        {
            level++;
            modes.clear();
            createNewDrawModes();
        }
        break;
    case '-':
        if (level > 0)
        {
            level--;
            modes.clear();
            createNewDrawModes();
        }
        break;
    case ' ':
        if (PressedSpace == false && SpaceCounter == 0)
        {
            PressedSpace = true;
            level = 0;
            SpaceCounter++;
        }
        else if (SpaceCounter >= 1 && PressedSpace == true)
        {
            PressedSpace = false;
            SpaceCounter = 0;
        }
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

void ofApp::resetDrawMode5()
{
    pressedO = false;
    pressedU = false;
    pressedI = false;
    pressedP = false;
    pressedY = false;
}

void ofApp::setColorReset()
{
    ofSetColor(256, 256, 256);
}

void ofApp::modechartoint()
{
    modeint = int(mode) - 48;
}

void ofApp::activateMode()
{
    if(mode == '0'){
        DrawMode0();
    }
    else if(mode == '6')
    {
        if (pressedU == true)
        {
            modes[0]->setActive(true);
            modes[0]->draw();
        }
        if (pressedI == true)
        {
            modes[1]->setActive(true);
            modes[1]->draw();
        }
        if (pressedO == true)
        {
            modes[2]->setActive(true);
            modes[2]->draw();
        }
        if(pressedY == true){
            modes[3]->setActive(true);
            modes[3]->draw();
        }
        if(pressedP == true){
            modes[4]->setActive(true);
            modes[4]->draw();
        }
    }
    else
    {
        modes[modeint - 1]->setActive(true);
        modes[modeint - 1]->draw();
    }
}

void ofApp::createNewDrawModes()
{
    DrawMode1 *dm1 = new DrawMode1(ofGetWidth() / 2, ofGetHeight() / 2, level);
    DrawMode2 *dm2 = new DrawMode2(200, level, ofGetWidth() / 2, ofGetHeight() - 50, ofRandom(30, 71));
    DrawMode3 *dm3 = new DrawMode3(ofGetWidth() / 3, 10, ofGetHeight() / 2, level);
    DrawMode4 *dm4 = new DrawMode4(ofGetWidth() / 3, ofGetHeight() / 2 - 100, ofGetHeight() / 2, level);
    DrawMode5 *dm5 = new DrawMode5(0,0,ofGetWidth()/3,level);
    modes.push_back(dm1);
    modes.push_back(dm2);
    modes.push_back(dm3);
    modes.push_back(dm4);
    modes.push_back(dm5);
}
