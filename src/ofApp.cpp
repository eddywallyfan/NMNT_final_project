#include "ofApp.h"

GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};
float Y = 35;
float X = 75;
int num = rand() % 5;
bool test = false;
//--------------------------------------------------------------
void ofApp::setup(){	
	video1.load("spaceship/video1.mp4");
	video2.load("spaceship/video2.mp4");
	video3.load("spaceship/video3.mp4");
	video4.load("spaceship/video4.mp4");
	video5.load("spaceship/video5.mp4");
	endmovie.load("spaceship/endmovie.mp4");
	space.load("spaceship/space.jpg");
	spaceMusic.load("spaceship/takeoff.wav");
	spaceMusic.play();
	ofSetVerticalSync(true);
    //some model / light stuff
    ofEnableDepthTest();
    glShadeModel (GL_SMOOTH);
	
    /* initialize lighting */
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);
    glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);
    glColorMaterial (GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
	GLfloat kantel = 90;
    //load the spaceship model - the 3ds and the texture file need to be in the same folder
    spaceshipModel.loadModel("spaceship/globe.3DS", 20);
	spaceshipModel.setScale(2, 2, 2);
	spaceshipModel.setPosition(ofGetWidth()/2, ofGetHeight()/2, kantel);
	spaceshipModel.setRotation(0, 90, 90, 1, 0);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	spaceshipModel.setRotation(1, 10 + ofGetElapsedTimef() * 20, 0, 0, 1);
	video1.update();
	video2.update();
	video3.update();
	video4.update();
	video5.update();
	space.update();
	endmovie.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (test == false) {
		space.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
	

	switch (num) {
	case 0:
		video1.draw(0, 0, ofGetWidth(), ofGetHeight());
		break;
	case 1:
		video2.draw(0, 0, ofGetWidth(), ofGetHeight());
		break;
	case 2:
		video3.draw(0, 0, ofGetWidth(), ofGetHeight());
		break;
	case 3:
		video4.draw(0, 0, ofGetWidth(), ofGetHeight());
		break;
	case 4:
		video5.draw(0, 0, ofGetWidth(), ofGetHeight());
		break;
	case 5:
		endmovie.draw(0, 0, ofGetWidth(), ofGetHeight());
		break;
	}
	if (spaceMusic.getPosition() >= 0.9) {
		spaceMusic.stop();
		spaceMusic.load("spaceship/takeoff.wav");
		std::printf("%s", "music");
		spaceMusic.play();
	}
	if ( test == true) {
		spaceMusic.stop();
		spaceMusic.load("spaceship/takeoff.wav");
		std::printf("%s", "music stop");

	}
	if (video1.getPosition() >= 0.99 && test == true) {
		video1.close();
		video1.load("spaceship/video1.mp4");
		num = rand() %5;
		test = false;
		std::printf("%s", "vid1");
		spaceMusic.play();

	}
	if (video2.getPosition() >= 0.99 && test == true) {
		video2.close();
		video2.load("spaceship/video2.mp4");
		num = rand() % 5;
		test = false;
		std::printf("%s", "vid2");
		spaceMusic.play();

	}
	if (video3.getPosition() >= 0.99 && test == true) {
		video3.close();
		video3.load("spaceship/video3.mp4");
		num = rand() % 5;
		test = false;
		std::printf("%s", "vid3");
		spaceMusic.play();

	}
	if (video4.getPosition() >= 0.99 && test == true) {
		video4.close();
		video4.load("spaceship/video4.mp4");
		num = rand() % 5;
		test = false;
		std::printf("%s", "vid4");
		spaceMusic.play();

	}
	if (video5.getPosition() >= 0.99 && test == true) {
		video5.close();
		video5.load("spaceship/video5.mp4");
		num = rand() % 5;
		test = false;
		std::printf("%s", "vid5");
		spaceMusic.play();

	}
	if (endmovie.getPosition() >= 0.99 && test == true) {
		endmovie.close();
		endmovie.load("spaceship/endmovie.mp4");
		num = rand() % 5;
		test = false;
		std::printf("%s", "endmov");
		spaceMusic.play();

	}


	glPushMatrix();

        //draw in middle of the screen
        glTranslatef(ofGetWidth()/2,ofGetHeight()/2,0);
        //tumble according to mouse
        glRotatef(-Y,1,0,0);
        glRotatef(X,0,1,0);
        glTranslatef(-ofGetWidth()/2,-ofGetHeight()/2,0);

        ofSetColor(255, 255, 255, 255);
		                   spaceshipModel.drawFaces();

    glPopMatrix();
	
   // ofSetHexColor(0x000000);
   // ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 10, 15);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ 
	if (key == OF_KEY_DOWN){
	}
	if (key == OF_KEY_UP) {	
		if (Y > -70) {
			Y = Y - 5;
		}
	}

	if (key == OF_KEY_LEFT) {	
		if (X > 40) {
			X = X - 5;
		}
	}
	if (key == OF_KEY_RIGHT) {
		
		if (X < 140) {
			X = X + 5;
		}
	}
	if (key == GLFW_KEY_SPACE) {
		switch (num) {
			case 0:
				test = true;
				video1.play();
				break;
		
			case 1:
				test = true;
				video2.play();	
				break;
		
			case 2:
				test = true;
				video3.play();
				break;
		
			case 3:
				test = true;
				video4.play();
				break;
		
			case 4:
				test = true;
				video5.play();
				break;
			case 5:
				break;
		
			default:
				test = false;
				space.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	if (key == 's') {
	}
}	

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	if (key == OF_KEY_DOWN && test == false) {
		test = true;
		num = 5;
		endmovie.play();
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
