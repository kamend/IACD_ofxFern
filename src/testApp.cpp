#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	int camW = 640;
	int camH = 480;
	
	eye.initGrabber(camW, camH);
	
	fern.initTracker("8bit.jpg",camW, camH);
	
	img.allocate(camW, camH);
	colorImg.allocate(camW, camH);

	rect.setMode(OF_PRIMITIVE_TRIANGLES);
	
	rect.addVertex(ofVec2f(0,0));
	rect.addVertex(ofVec2f(1,0));
	rect.addVertex(ofVec2f(1,1));
	rect.addVertex(ofVec2f(0,1));
	
	rect.addTriangle(0, 1, 2);
	rect.addTriangle(0, 2, 3);
	
	cover.loadImage("cover.png");
	
	rect.addTexCoord(ofVec2f(0,0));
	rect.addTexCoord(ofVec2f(cover.getWidth(),0));
	rect.addTexCoord(ofVec2f(cover.getWidth(), cover.getHeight()));
	rect.addTexCoord(ofVec2f(0, cover.getHeight()));
	
	video.setUseTexture(true);
	video.loadMovie("8bit.mov");
	video.play();
}

//--------------------------------------------------------------
void testApp::update(){
	
	video.update();
	eye.update();
	if(eye.isFrameNew()) {
		colorImg.setFromPixels(eye.getPixels(), 640, 480);
		img = colorImg;
		fern.update(img);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0,0,0);
	eye.draw(0,0,640,480);
   
	rect.setVertex(0,ofVec2f(0,0));
	rect.setVertex(1,ofVec2f(0,0));
	rect.setVertex(2,ofVec2f(0,0));
	rect.setVertex(3,ofVec2f(0,0));
	
	
	if(fern.getDetector()->pattern_is_detected) {
		ofLog() << "Patteern here!";
		ofVec2f corners[4];
		for(int i=0;i<4;i++) {
			corners[i].x = fern.getDetector()->detected_u_corner[i];
			corners[i].y = fern.getDetector()->detected_v_corner[i];
			
			rect.setVertex(i, corners[i]);
		}
		
		

	}
	
	video.getTextureReference().bind();
	rect.drawFaces();
	video.getTextureReference().unbind();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}