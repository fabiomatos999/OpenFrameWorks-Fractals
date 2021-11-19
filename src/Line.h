#pragma once

#include "ofMain.h"

class Line
{
    private:
    float Length = 0;
    ofPoint Start;
    ofPoint End;
    float dispX = 0;
    float dispY = 0;

    public:
    Line(ofPoint Start,ofPoint End);
    ~Line();
    float getLength();
    void setLength(float Length);
    ofPoint getStart();
    void setStart(ofPoint Start);
    ofPoint getEnd();
    void setEnd(ofPoint End);
    void drawLine();
    void lineScalar(float scaler);
    float getdispX();
    float getdispY();
};