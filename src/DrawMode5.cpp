#include "DrawMode5.h"

DrawMode5::DrawMode5(int x, int y, int size, int n)
{
    this->x = x;
    this->y = y;
    this->size = size;
    this->n = n;
}

void DrawMode5::draw()
{
    if(getActive())
    {
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
        drawMode5(this->x, this->y, this->size, this->n);
    }
}

void DrawMode5::drawMode5(int x, int y, int size, int n)
{
    ofSetLineWidth(1);
    if(n <= 0)
    {
        return;
    }
    
    rotateTick += 2;
    if(n%2 == 0 || n == 0)
    {
        ofRotateDeg(.5*rotateTick);
    }

    colorTicks();
    ofSetColor(tickR,tickB,tickG);
    ofDrawCircle(x,y,size);
    ofPoint a(0,size);
    ofPoint b(size,0);
    ofPoint c(0,-1*size);
    ofPoint d(-1*size,0);
    ofDrawLine(a,b);
    ofDrawLine(b,c);
    ofDrawLine(c,d);
    ofDrawLine(d,a);
    drawMode5(x,y,size/2,n-1);
}

void DrawMode5::colorTicks(){
    
    if(tickR < 256 && plusplus == true)
    {
        tickR++;
    }
    else if (tickG < 256 && plusplus == true)
    {
        tickG++;
    }
    else if(tickB < 256 && plusplus == true)
    {
        tickB++;
    }
    else if(tickR >= 256 && tickG >= 256 && tickB >= 256 && plusplus == true)
    {
        plusplus = false;
    }
    else if(plusplus == false && tickR >= 0)
    {
        tickR--;
    }
    else if(plusplus == false && tickG >= 0)
    {
        tickG--;
    }
    else if(plusplus == false && tickB >= 0)
    {
        tickB--;
    }
    else if(tickR <= 0 && tickB <= 0 && tickG <= 0)
    {
        tickR = 0;
        tickB = 0;
        tickG = 0;
        plusplus = true;
    }
}

DrawMode5::~DrawMode5()
{

}