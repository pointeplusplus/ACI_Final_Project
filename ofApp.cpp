#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	mousePressX = 0;
	mousePressY = 0;
	add_new_particle = false;

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
    		if(particleSystem[p].distance(particleSystem[p2]) < particleSystem[p].getRadius() + particleSystem[p2].getRadius()){

    			ofVec2f p_speed = particleSystem[p].getSpeed();
    			ofVec2f p2_speed = particleSystem[p2].getSpeed();
    			double m1 = particleSystem[p].getMass();
    			double m2 = particleSystem[p2].getMass();

    			double new_x1 = (p_speed.x * (m1 - m2) + (2 * m2 * p2_speed.x)) / (m1 + m2);
				double new_y1 = (p_speed.y * (m1 - m2) + (2 * m2 * p2_speed.y)) / (m1 + m2);
				double new_x2 = (p2_speed.x * (m2 - m1) + (2 * m1 * p_speed.x)) / (m1 + m2);
				double new_y2 = (p2_speed.y * (m2 - m1) + (2 * m1 * p_speed.y)) / (m1 + m2);

				particleSystem[p].setSpeed(ofVec2f(new_x1,new_y1));
				particleSystem[p2].setSpeed(ofVec2f(new_x2,new_y2));
    			
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
	
	// Add wind
	if(key == OF_KEY_LEFT){
		for(unsigned int p = 0; p < particleSystem.size(); p++){
			particleSystem[p].setSpeed(ofVec2f(particleSystem[p].getSpeed().x - 10, particleSystem[p].getSpeed().y));
		}
	}
	else if (key == OF_KEY_RIGHT){
		for(unsigned int p = 0; p < particleSystem.size(); p++){
			particleSystem[p].setSpeed(ofVec2f(particleSystem[p].getSpeed().x + 10, particleSystem[p].getSpeed().y));
		}
	} 
	else if(key == OF_KEY_UP){
		for(unsigned int p = 0; p < particleSystem.size(); p++){
			particleSystem[p].setSpeed(ofVec2f(particleSystem[p].getSpeed().x, particleSystem[p].getSpeed().y - 10));
		}
	}
	else if(key == OF_KEY_DOWN){
		for(unsigned int p = 0; p < particleSystem.size(); p++){
			particleSystem[p].setSpeed(ofVec2f(particleSystem[p].getSpeed().x, particleSystem[p].getSpeed().y + 10));
		}
	}
	else if(key == 's'){
		for(unsigned int p = 0; p < particleSystem.size(); p++){
			particleSystem[p].setSpeed(ofVec2f(particleSystem[p].getSpeed().x/2.0, particleSystem[p].getSpeed().y/2.0));
		}
	}
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

	// If we are in a current particle, divide it
	add_new_particle = true;
	for(unsigned int p = 0; p < particleSystem.size(); p++){
		// If the click was inside a circle
		if (particleSystem[p].distance(ofVec2f(x,y)) < particleSystem[p].getRadius()){
			
			add_new_particle = false;
			ofVec2f old_speed = particleSystem[p].getSpeed();
			ofVec2f new_speed = ofVec2f(old_speed.x * -1, old_speed.y * -1);
			ofVec3f color = particleSystem[p].getColor();
			particleSystem.push_back(ParticleChain(color, new_speed, ofVec2f(x + particleSystem[p].getRadius(), y + particleSystem[p].getRadius())));
			particleSystem[particleSystem.size()-1].setRadius(particleSystem[p].getRadius()/2.0);
			particleSystem[p].setRadius(particleSystem[p].getRadius()/2.0);

			break;
		}
	}

	mousePressX = x;
	mousePressY = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	if(add_new_particle){
		int x_diff = x - mousePressX;
		int y_diff = y - mousePressY;

		double speedX = x_diff / SPEED_CONSTANT;
		double speedY = y_diff / SPEED_CONSTANT;
		// TODO: keep from edges
		ofVec3f color = ofVec3f(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		particleSystem.push_back(ParticleChain(color, ofVec2f(speedX, speedY), ofVec2f(x, y)));
	}
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
