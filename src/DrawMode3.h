#pragma once

#include "FractalMode.h"
#include "ofMain.h"

class DrawMode3: public FractalMode{
    private:
        bool Activate = false;
        float x;
        float y;
        int n;
        float size;
    
    public:
        void draw();
        void drawMode3(float x, float y, float size, int n);
        DrawMode3(float x, float y, float size, int n);
        ~DrawMode3();
};