#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	image.loadImage("Colored_light.jpg");
	image.resize(640,480);
	
	// set up mesh
	// 0 ------------ 3
	// |              |
	// |              |
	// |              |
	// 1 ------------ 2

	mesh.addVertex(ofPoint(0,0,0));
	mesh.addVertex(ofPoint(0,image.getHeight(),0));
	mesh.addVertex(ofPoint(image.getWidth(),image.getHeight(),0));
	mesh.addVertex(ofPoint(image.getWidth(),0,0));
	
	mesh.addTexCoord(ofPoint(0,0));
	mesh.addTexCoord(ofPoint(0,image.getHeight()));
	mesh.addTexCoord(ofPoint(image.getWidth(),image.getHeight()));
	mesh.addTexCoord(ofPoint(image.getWidth(),0));
	
	mesh.addTriangle(0,1,2);
	mesh.addTriangle(0,2,3);
	
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	ofSetColor(255);
	
	cam.begin();
	
	ofTranslate(-image.getWidth()*.5,-image.getHeight()*.5);
	
	image.getTextureReference().bind();
	mesh.drawFaces();
	image.getTextureReference().unbind();
	
	mesh.drawWireframe();
	
	cam.end();
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