#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	savePDF = false;
	//ofSetFrameRate(1);
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofBackground(255);
	ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	if(savePDF){
		ofBeginSaveScreenAsPDF("screen-"+ofGetTimestampString()+".pdf", false);
	}
	
	int minR = 100;
	int maxR = 300;
	for(int i = 0; i < 100; i++){
		
		ofFill();
		ofSetColor( ofRandom(0,255), ofRandom(0,255), ofRandom(0,255), ofRandom(10,255) );
		ofPoint p = ofPoint( ofRandom(0,ofGetWidth()+minR),ofRandom(0,ofGetHeight()) );
		ofPoint p1 = ofPoint(p.x-ofRandom(minR,maxR), p.y-ofRandom(minR,maxR));
		ofPoint p2 = ofPoint(p.x, p.y+ofRandom(minR,maxR));
		ofPoint p3 = ofPoint(p.x-ofRandom(minR,maxR), p.y+ofRandom(minR,maxR));
		
		ofTriangle(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
		
		ofNoFill();
		ofSetColor(0,ofRandom(100,255));
		ofTriangle(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);

	}
	
	
	
	if(savePDF){
		ofEndSaveScreenAsPDF();
		savePDF = false;
	}
	
	if(ofGetFrameNum() > 1 ) ofSleepMillis(600);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if( key == ' ' ) savePDF = true;
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