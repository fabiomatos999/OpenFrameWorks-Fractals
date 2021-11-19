#pragma once

#include "ofMain.h"
#include "FractalMode.h"

class DrawMode2 : public FractalMode
{
    private:
    bool Activate = false;
    int length = 0;
    int n = 0;
    int x = 0;
    int y = 0;
    int d = 0;
    int e = 0;
    public:
    DrawMode2(int length, int n, int x, int y, int d);
    ~DrawMode2();
    void draw();
    void drawMode2(int length, int n, int x, int y, int d, int e);
};