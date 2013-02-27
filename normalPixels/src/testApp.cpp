#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	// load images
	myImage.loadImage("chagall.jpg");
	//myImage.loadImage("http://www.viajejet.com/wp-content/viajes/parque-escultorico-de-a-coru%C3%B1a.jpg");
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	int step = ofMap(mouseX,0,ofGetWidth(),2,50);
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofColor c;
	
	for(int x = 0; x < myImage.getWidth(); x+=step){
		for(int y = 0; y < myImage.getHeight(); y+=step){
			 c = myImage.getColor(x, y);
			ofSetColor(c);
			ofRect(x,y,step,step);
		}
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