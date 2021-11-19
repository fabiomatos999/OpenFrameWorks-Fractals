#pragma once

#include "ofMain.h"

class FractalMode{

    private:
        bool Active = false;
    
    public:
        virtual void draw() = 0;
        FractalMode();
        ~FractalMode();
        bool getActive();
        void setActive(bool Active);
        void setColorReset();
};