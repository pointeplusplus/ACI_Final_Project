
#include "particle.h"

#define STARTING_RADIUS_SIZE 40
#define ALPHA_STEP_SIZE .93
#define RADIUS_REDUCTION .96


Particle::Particle(){
	std::cout << "Initialize your parcticles, please!!" << std::endl;
}

Particle::Particle(ofVec2f loc){

	location = loc;
	frameNumber = 0;
	currentSize = STARTING_RADIUS_SIZE;
	currentAlpha = 255;
}

void Particle::draw(ofVec3f color){

	//Store current color to restore it afterwards
	float currentColor[4];
	glGetFloatv(GL_CURRENT_COLOR,currentColor);

	//Draw circle
	ofSetColor(color.x, color.y, color.z, currentAlpha);
	ofCircle(location, currentSize);

	//Restore Previous Color
	ofSetColor(currentColor[0], currentColor[1], currentColor[2], currentColor[3]);
}

bool Particle::update(){

	// Change the size an opacity
	frameNumber++;
	currentSize *= RADIUS_REDUCTION;
	currentAlpha *= ALPHA_STEP_SIZE;

	//Delete the particle if its size <= 0
	if(currentSize <= 1){
		return true;
	}

	return false;
}