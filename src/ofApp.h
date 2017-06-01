#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

		ofImage space;
		ofSoundPlayer spaceMusic;
        ofxAssimpModelLoader spaceshipModel;

		ofVideoPlayer video1;
		ofVideoPlayer video2;
		ofVideoPlayer video3;
		ofVideoPlayer video4;
		ofVideoPlayer video5;
		ofVideoPlayer endmovie;
		
		
};
	
