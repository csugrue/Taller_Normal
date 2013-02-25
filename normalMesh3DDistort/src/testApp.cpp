#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	image.loadImage("Colored_light.jpg");
	image.resize(640,640);
	
	//mesh.setMode(OF_PRIMITIVE_POINTS );

	int width = image.getWidth() / 10.f;
	int height = image.getHeight() / 10.f;
	
	for (int y = 0; y < height; y++){
		for (int x = 0; x<width; x++){
			mesh.addVertex(ofPoint(x*10,y*10,ofRandom(0,10) ));
			mesh.addTexCoord(ofPoint(x*10,y*10));
		}
	}
	
	int w = width;
	for (int y = 0; y<height-1; y++){
		for (int x=0; x<width-1; x++){
			
			mesh.addIndex(x+y*w);				
			mesh.addIndex(x+(y+1)*w);
			mesh.addIndex((x+1)+(y+1)*w);
			
			mesh.addIndex(x+y*w);
			mesh.addIndex((x+1)+(y+1)*w);
			mesh.addIndex((x+1)+y*w);			
						
		}
	}
	
	glEnable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void testApp::update(){
	
	float scaledTime = ofGetElapsedTimef()*.75;
	
	for( int i = 0; i < mesh.getNumVertices(); i++){
		
		ofPoint p = mesh.getVertex(i);
		p.z = 100 * ofNoise( (p.x*.001)+scaledTime,(p.y*.001)+scaledTime);
		mesh.setVertex(i, p);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(0);
	
	ofSetColor(255);
	
	cam.begin();
	
	ofPushMatrix();
	ofTranslate(-image.getWidth()*.5,-image.getHeight()*.5);
	
	image.getTextureReference().bind();
	mesh.drawFaces();
	image.getTextureReference().unbind();
	
	ofTranslate(0,0,1);
	mesh.drawWireframe();
	ofPopMatrix();
	
	
	
	ofNoFill();
	ofBox(0,0,0,image.getWidth());
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