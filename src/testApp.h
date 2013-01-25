#pragma once

#include "ofMain.h"
#include "ofxFern.h"
#include "ofxMacamPs3Eye.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	ofxFern fern;
	ofxCvColorImage colorImg;
	ofxCvGrayscaleImage img;
	ofImage loadimg;
	
	ofxMacamPs3Eye eye;
	
	ofMesh rect;
	ofImage cover;
	ofVideoPlayer video;
		
};
