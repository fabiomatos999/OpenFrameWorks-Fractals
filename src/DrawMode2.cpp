#include "DrawMode2.h"

DrawMode2::DrawMode2(int length, int n, int x, int y, int d)
{
    this->length = length;
    this->n = n;
    this->x = x;
    this->y = y;
    this->d = d;
    this->e = ofRandom(30,71);
}

void DrawMode2::draw()
{
    if(getActive())
    {
        drawMode2(this->length,this->n,this->x,this->y,this->d, this->e);
    }
}

void DrawMode2::drawMode2(int length, int n, int x, int y, int d, int e)
{
    if (n != 0)
    {
        ofSetLineWidth(1);
        int middleY = y - length;
        int leftBranchX = x - length * cos(PI / 180 * d);
        int leftBranchY = middleY - length * sin(PI / 180 * d);
        int rightBranchX = x + length * cos(PI / 180 * e);
        int rightBranchY = middleY - length * sin(PI / 180 * e);

        ofDrawLine(x, y, x, y - length);
        ofDrawLine(x, y - length, rightBranchX, rightBranchY);
        ofDrawLine(x, y - length, leftBranchX, leftBranchY);
        ofSetColor(235, 2, 247);
        drawMode2(length / 2, n - 1, rightBranchX, rightBranchY, d, e);
        ofSetColor(2, 206, 247);
        drawMode2(length / 2, n - 1, leftBranchX, leftBranchY, d, e);
    }
}

DrawMode2::~DrawMode2()
{

}