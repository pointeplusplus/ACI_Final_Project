#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	mousePressX = 0;
	mousePressY = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

	// Draw all of the particles
    for(unsigned int p = 0; p < particleSystem.size(); p++){
    	particleSystem[p].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

	// Update each particle (within each chain)
    //std::cout << "Drawing all particles" << std::endl;
    for(unsigned int p = 0; p < particleSystem.size(); p++){
    	particleSystem[p].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	/*
	if (key == keycode_Esc || key == keycode_Q || key == keycode_q) {
        exit();
    }*/
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

	for(int p = 0; p < particleSystem.size(); p++){
        //if(particleSystem.size() >= i+1){
            particleSystem[p].addParticle(ofVec2f(x,y));
        //}
        
    }
	/*
	//FOR TESTING
    for(int i = 0; i < 10; i++){
        if(particleSystem.size() >= i+1){
            particleSystem[i].addParticle(ofVec2f(x+(i*40),y+(i*40)));
        }
        
    }
    */
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	mousePressX = x;
	mousePressY = y;
	/*
	//FOR TESTING
    for(int i = 0; i < 10; i++){
        ofVec3f color = ofVec3f(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
        //std::cout << "color for chain: " << color.x << " " << color.y << " " << color.z << std::endl;
        particleSystem.push_back(ParticleChain(color));
    }
    */
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	ofVec3f color = ofVec3f(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	particleSystem.push_back(ParticleChain(color));
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
