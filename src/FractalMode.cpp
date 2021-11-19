#include "FractalMode.h"

FractalMode::FractalMode(){

}

bool FractalMode::getActive(){
    return Active;
}

void FractalMode::setActive(bool Active){
    this->Active = Active;
}

void FractalMode::draw(){

}

void FractalMode::setColorReset()
{
    ofSetColor(256,256,256);
}

FractalMode::~FractalMode(){
    
}