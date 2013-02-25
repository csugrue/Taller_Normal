#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofEnableSmoothing();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	float ang = ofMap(mouseX,0,ofGetWidth(),.1,.4);
	float amp = ofMap(mouseY,0,ofGetHeight(),1,5);
	
	ofBackgroundGradient(ofColor(79,198,255), ofColor(15,83,149), OF_GRADIENT_CIRCULAR);
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofPushMatrix();
	ofTranslate(0,ofGetHeight()/2);
	for( int i = 0; i < 360; i++){
	
		float y = (i*amp)*sin(i*ang);
		
		ofSetColor(255);
		ofLine( i*10, 0,i*10,y);
		
		ofNoFill();
		ofEllipse( i*10,y,15,15);
		
		ofSetColor(255,0,150);
		ofFill();
		ofRect(i*10,y,4,4);

	}
	ofPopMatrix();
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