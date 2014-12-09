
#include "particleChain.h"
#include <cmath>

ParticleChain::ParticleChain(){

}

ParticleChain::ParticleChain(ofVec3f color, ofVec2f start_speed, ofVec2f starting_pos){
	
	this->color = color;
	
	speed = start_speed;

	current_pos = starting_pos;

	addParticle(starting_pos);

}

void ParticleChain::update(){

	addNewLocation();

	// Have it bounce off of the walls
	if (current_pos.x <= STARTING_RADIUS_SIZE/2.0 || current_pos.x >= ofGetWidth() - STARTING_RADIUS_SIZE/2.0){
		speed.x *= -1;
	}
	if (current_pos.y <= STARTING_RADIUS_SIZE/2.0 || current_pos.y >= ofGetHeight() - STARTING_RADIUS_SIZE/2.0){
		speed.y *= -1;
	}

	bool to_delete = false;
	for(list<Particle>::iterator p = particles.begin(); p != particles.end(); ){

		to_delete = p->update();
		
		if(to_delete){
			p = particles.erase(p);
		}
		else { //increment if not erasing
			if(p != particles.end()){
				p++;	
			}	
		}
	}
}

void ParticleChain::draw(){

	for(list<Particle>::iterator p = particles.begin(); p != particles.end(); p++){	
		p->draw(color);
	}
}

void ParticleChain::addParticle(ofVec2f pos){

	particles.push_back(Particle(pos));
}

void ParticleChain::addNewLocation(){
	ofVec2f new_pos = ofVec2f(current_pos.x + speed.x, current_pos.y + speed.y);
	current_pos = new_pos;
	addParticle(new_pos);
}

double ParticleChain::distance(ParticleChain other){

	return sqrt( pow(current_pos.x - other.current_pos.x , 2) + pow (current_pos.y - other.current_pos.y , 2) );
}