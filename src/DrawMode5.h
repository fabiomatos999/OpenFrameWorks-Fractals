#pragma once

#include "FractalMode.h"
#include "Line.h"

class DrawMode5 : public FractalMode
{
private:
    int x = 0;
    int y = 0;
    int size = 0;
    int n = 0;
    bool Activate = false;
public:
    void draw();
    void drawMode5(int x, int y, int size, int n);
    DrawMode5(int x, int y, int size, int n);
    ~DrawMode5();
    int tickR = 0;
    int tickG = 0;
    int tickB = 0;
    int rotateTick = 0;
    bool plusplus = true;
    void colorTicks();
};