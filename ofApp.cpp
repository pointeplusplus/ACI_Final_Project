#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	mousePressX = 0;
	mousePressY = 0;

	ofSetFullscreen(true);

}

//--------------------------------------------------------------
void ofApp::update(){

	// Update all of the particles
    for(unsigned int p = 0; p < particleSystem.size(); p++){
    	particleSystem[p].update();
    }

    // Check for collisions
    for(unsigned int p = 0; p < particleSystem.size(); p++){
    	// Check against all other particles (that weren't already checked)
    	for(unsigned int p2 = p+1; p2 < particleSystem.size(); p2++){
    		if(particleSystem[p].distance(particleSystem[p2]) < 2 * STARTING_RADIUS_SIZE){

    		}
    	}
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

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	int x_diff = x - mousePressX;
	int y_diff = y - mousePressY;

	double speedX = x_diff / SPEED_CONSTANT;
	double speedY = y_diff / SPEED_CONSTANT;

	ofVec3f color = ofVec3f(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	particleSystem.push_back(ParticleChain(color, ofVec2f(speedX, speedY), ofVec2f(x, y)));
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
