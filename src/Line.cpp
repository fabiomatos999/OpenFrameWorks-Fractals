#include "Line.h"

Line::Line(ofPoint Start,ofPoint End)
{
    this->Start = Start;
    this->End = End;
}

float Line::getLength()
{
    return Length;
}

void Line::setLength(float Length)
{
    this->Length = Length;
}

ofPoint Line::getStart()
{
    return Start;
}

void Line::setStart(ofPoint Start)
{
    this->Start = Start;
}

ofPoint Line::getEnd()
{
    return End;
}

void Line::setEnd(ofPoint End)
{
    this->End = End;
}

void Line::drawLine()
{
    ofDrawLine(Start,End);
}

void Line::lineScalar(float scaler)
{
    this->dispX = (End.x - Start.x)/scaler + Start.x;
    this->dispY = (End.y - Start.y)/scaler + Start.y;
}

float Line::getdispX()
{
    return dispX;
}

float Line::getdispY()
{
    return dispY;
}

Line::~Line()
{

}