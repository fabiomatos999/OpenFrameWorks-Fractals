#pragma once

#include "ofMain.h"
#include "FractalMode.h"

class DrawMode1 : public FractalMode
{
    private:
    bool Activate = false;
    int x,y,n;
    
    public:
    DrawMode1(int x, int y, int n);
    ~DrawMode1();
    void draw();
    void drawMode1(int x,int y,int n, int dec);
};