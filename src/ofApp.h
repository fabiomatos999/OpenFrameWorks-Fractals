#pragma once
#include<cmath>

#include "ofMain.h"
#include "FractalMode.h"
#include "DrawMode1.h"
#include "DrawMode2.h"
#include "DrawMode3.h"
#include "DrawMode4.h"
#include "DrawMode5.h"
#include <string>

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void resetDrawMode5();
		void setColorReset();
		int level = 4;
		std::vector<FractalMode*> modes;
		int modeint = 1;
		void modechartoint ();
		void createNewDrawModes();
		float waitTime = 0;
		int counter = 0;
		float currentTime = 0;
		int SpaceCounter = 0;
		void activateMode();
		void DrawMode0();
	private:
		char mode = '0';
		bool ForwardDirection = false;
		bool LeftDirection = false;
		bool PressedSpace = false;
		bool pressedU = false;
		bool pressedI = false;
		bool pressedO = false;
		bool pressedP = false;
		bool pressedY = false;
};
