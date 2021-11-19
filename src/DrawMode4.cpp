#include "DrawMode4.h"

DrawMode4::DrawMode4(int x, int y, int size, int n)
{
    this->x = x;
    this->y = y;
    this->size = size;
    this->n = n;
}

void DrawMode4::draw()
{
    if (getActive() == true)
    {
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
        drawMode4(this->x, this->y, this->size, this->n, this->ringcounter);
    }
}

void DrawMode4::drawMode4(int x, int y, int size, int n,int ringcounter)
{
    if( n <= 0)
    {
        return;
    }
    ofSetLineWidth(4);
    ofSetColor(256,256,256);
    ofPoint center(0,0);
    ofSetColor(0,128,128);
    ofDrawCircle(center,size);
    ofRotateDeg(30*ringcounter);
    ofSetColor(128,0,128);
    ofPoint ring(size,0);
    ofDrawLine(center,ring);
    ofRotateDeg(.2*tick);
    tick++;

    drawMode4(x,y,size/1.3,n-1,ringcounter+1);
}

DrawMode4::~DrawMode4()
{
}