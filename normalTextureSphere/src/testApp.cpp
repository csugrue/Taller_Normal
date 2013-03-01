#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	glEnable(GL_DEPTH_TEST); //enable depth comparisons and update the depth buffer
	//ofDisableArbTex(); //for power of 2 textures
	ofEnableNormalizedTexCoords(); // for other size textures

	// texture is power of 2 size (2048x1024) or (1024x512) for example
	texImage.loadImage("dog-9.jpg");
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	//ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 200);
	//ofRotateY(ofGetFrameNum()*.2);
	easyCam.begin();
	texImage.getTextureReference().bind();
	ofSphere(0, 0, 0, 400);
	texImage.getTextureReference().unbind();
	easyCam.end();
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