#include "DrawMode3.h"

DrawMode3::DrawMode3(float x, float y, float size, int n)
{
    this->x = x;
    this->y = y;
    this->size = size;
    this->n = n;
}

void DrawMode3::draw()
{
    if (getActive() == true)
    {
        drawMode3(this->x, this->y, this->size, this->n);
    }
}

void DrawMode3::drawMode3(float x, float y, float size, int n)
{
    if (n == 0)
    {
        return;
    }
    ofSetLineWidth(1);
    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    ofSetColor(247, 2, 55);
    drawMode3(x, y, size / 2, n - 1);
    ofSetColor(235, 2, 247);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    ofSetColor(2,231,247);
    drawMode3((c.x + a.x) / 2, (c.y + a.y) / 2, size / 2, n - 1);
}

DrawMode3::~DrawMode3()
{
}