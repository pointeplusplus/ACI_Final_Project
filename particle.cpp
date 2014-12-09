
#include "particle.h"

Particle::Particle(){
	std::cout << "Initialize your parcticles, please!!" << std::endl;
}

Particle::Particle(ofVec2f loc, double radius){

	location = loc;
	frameNumber = 0;
	currentSize = radius;
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