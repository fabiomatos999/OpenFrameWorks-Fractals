#pragma once

#include "FractalMode.h"
#include "ofMain.h"
#include "Line.h"
#include <vector>

class DrawMode4 : public FractalMode
{
private:
    int x = 0;
    int y = 0;
    int size = 0;
    int n = 0;
    bool Activate = false;
    int ringcounter = 0;
    int tick = 0;

public:
    void draw();
    void drawMode4(int x, int y, int size, int n,int ringcounter);
    DrawMode4(int x, int y, int size, int n);
    ~DrawMode4();
};