#include "DrawMode1.h"

DrawMode1::DrawMode1(int x, int y, int n) 
{
    this->x = x;
    this->y = y;
    this->n = n;
}

void DrawMode1::draw()
{
    if(getActive())
    {
        drawMode1(this->x,this->y,this->n, 0);
    }
}

void DrawMode1::drawMode1(int x,int y,int n,int dec)
{
    if (n != 0)
    {
        ofSetLineWidth(1);
        ofDrawCircle(x, y, 100 - 10*(dec));
        dec++;
        ofSetColor(235, 2, 247);
        drawMode1(x + 100, y, n - 1,dec);
        ofSetColor(2, 206, 247);
        drawMode1(x - 100, y, n - 1,dec);
        ofSetColor(247, 2, 55);
        drawMode1(x, y + 100, n - 1,dec);
        setColorReset();
        ofSetColor(255.254, 253);
        drawMode1(x, y - 100, n - 1,dec);
        setColorReset();
    }
}

DrawMode1::~DrawMode1()
{

}