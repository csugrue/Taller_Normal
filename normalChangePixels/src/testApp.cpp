#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	imgA.loadImage("chagall.jpg");
	imgB.loadImage("geometric_bw.jpg");
	origPix.setFromPixels(imgA.getPixels(),imgA.getWidth(),imgA.getHeight(),OF_IMAGE_COLOR);
	
	imgC.loadImage("chagall.jpg");
	
	string shaderProgram = "#version 120\n \
    #extension GL_ARB_texture_rectangle : enable\n \
    \
    uniform sampler2DRect tex0;\
    uniform sampler2DRect blendTex;\
	uniform float mouseMap = 1.0;\
    \
    void main (void){\
    vec2 pos = gl_TexCoord[0].st;\
    \
    vec3 srcA = texture2DRect(tex0, pos).rgb;\
    vec3 srcB = texture2DRect(blendTex, pos).rgb;\
	srcA.x = mouseMap*srcA.x + (1-mouseMap)*srcB.x;\
	srcA.y = .5*srcA.y + .5*srcB.y;\
	srcA.z = .25*srcA.z + .75*srcB.z;\
    \
    gl_FragColor = vec4(srcA,1);\
    }";
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    shader.linkProgram();
	
	mode = 1;
}

//--------------------------------------------------------------
void testApp::update(){
	
	if( mode == 0){
	
		float mouseMap = ofMap(mouseX,0,ofGetWidth(),0,1);
		unsigned char * pixelsA = imgA.getPixels();
		unsigned char * pixelsB = imgB.getPixels();
		unsigned char * pixelsC = origPix.getPixels();

		for(int i = 0; i < imgA.getWidth()*imgA.getHeight(); i++){
				pixelsA[i*3] = mouseMap*pixelsB[i*3]+(1-mouseMap)*pixelsC[i*3];
				pixelsA[(i*3+1)] = .5*pixelsB[(i*3+1)]+.5*pixelsC[(i*3+1)];
				pixelsA[(i*3+2)] = .25*pixelsB[(i*3+2)]+.75*pixelsC[(i*3+2)];
		}
		
		imgA.update();
	}
	
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	if(mode == 0){
		imgA.draw(0,0);
	}else if(mode == 1){
	
		shader.begin();
		shader.setUniformTexture("blendTex", imgC.getTextureReference(), 1 );
		shader.setUniform1f("mouseMap",ofMap(mouseX,0,ofGetWidth(),0,1));
		imgB.draw(0,0);
	
		shader.end();
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if(key == ' '){
		mode++;
		if(mode >1)mode = 0;
	}
	
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