#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	// set up for sound input
	int bufferSize = 128;
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	
	bufferCounter	= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
	
	soundStream.setup(this, 0, 2, 44100, bufferSize, 2);
	
	// setup visuals
	for( int i = 0; i < bufferSize; i++){
		
		// get random postions on a sphere
		float theta1=ofRandom(0, TWO_PI);
		float theta2=ofRandom(0, TWO_PI);
		ofVec3f p;
		p.x = cos( theta1 ) * cos( theta2 );
		p.y = sin( theta1 );
		p.z = cos( theta1 ) * sin( theta2 );
		
		dirs.push_back(p);
		orig_pts.push_back( ofVec3f(0,0,0) );
		pts.push_back( ofVec3f(0,0,0)  );		
	}
	
	
	glowImg.loadImage("dot.png");
	ofEnableAlphaBlending();
	
	//cam.setDrag(.99);
}

//--------------------------------------------------------------
void testApp::update(){
	
	// scale the vol up to a 0-1 range 
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
	
	// record the volume into an array
	volHistory.push_back( scaledVol );
	
	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
	
	// update audio reactions based on volume and channel input
	for( int i = 0; i < pts.size(); i++){
		
		float radius = 200;
		
		orig_pts[i] = dirs[i] * radius;
		
		ofVec3f p;
		if(i%2 == 0) p = orig_pts[i] * ( 1 + (100*(left[i]) ) );
		else p = orig_pts[i] * ( 1 + (100*(right[i]) ) );
		
		pts[i] = .99 * pts[i] + .01 * p;
		
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){

	
	ofBackgroundGradient(ofColor(175,252,242),ofColor(0,16,27),  OF_GRADIENT_BAR);

	float rotationAmount;
	ofVec3f rotationAngle;
	ofQuaternion rotation;
	
	float radius = ofMap(scaledVol,0,1,10,200);
		
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	cam.begin();
	
	ofPushMatrix();
	for( int i = 0; i < pts.size(); i++){
		
		ofSetColor(255, 100);
		ofLine(orig_pts[i].x,orig_pts[i].y,orig_pts[i].z,pts[i].x,pts[i].y,pts[i].z);
		
		ofPushMatrix();
		
		ofTranslate(pts[i]);
		
		ofVec3f normal = pts[i]-orig_pts[i];
		normal.normalize();		
		ofVec3f axis(0, 0, 1);
		rotation.makeRotate(axis, normal);
		rotation.getRotate(rotationAmount, rotationAngle);
		ofRotate(rotationAmount, rotationAngle.x, rotationAngle.y, rotationAngle.z);
		
		ofSetColor(255, 100, 90);
		glowImg.draw(-radius*.5,-radius*.5,radius,radius);
		
		ofPopMatrix();
	}
	ofPopMatrix();
	
	cam.end();
	ofDisableBlendMode();

}
//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){	
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;	
	
	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;
		
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :) 
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
	bufferCounter++;
	
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