#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	topImage.loadImage("tubes.jpg");
	botImage.loadImage("bark.jpg");

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	int width = topImage.getWidth();
	int height = topImage.getHeight();
	
	int slices = 10;
	int spacing = width / 10.0;
	
	ofTranslate(ofGetWidth()/2-width/2,ofGetHeight()/2-height/2);
	
	botImage.draw(0,0);
	
	for( int i = 0; i < slices; i++){
		float segW = ofMap( sin( ofGetElapsedTimef()*(i+1) ), -1,1,0,spacing);
		int x = i*spacing;
		topImage.getTextureReference().drawSubsection( x, 0, segW, height,x, 0, segW, height);  
	}
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