
#include "particleChain.h"
#include <cmath>

ParticleChain::ParticleChain(){

}

ParticleChain::ParticleChain(ofVec3f color, ofVec2f start_speed, ofVec2f starting_pos){
	
	this->color = color;
	speed = start_speed;
	current_radius = STARTING_RADIUS_SIZE;

	// Make sure it doesn't 'get stuck' at the side
	if(starting_pos.x < current_radius){
		starting_pos.x = current_radius;
	}
	if(starting_pos.x > ofGetWidth() - current_radius){
		starting_pos.x = ofGetWidth() -current_radius;
	}
	if(starting_pos.y < current_radius){
		starting_pos.y = current_radius;
	}
	if(starting_pos.y > ofGetHeight() - current_radius){
		starting_pos.y = ofGetHeight() -current_radius;
	}

	current_pos = starting_pos;
	addParticle(starting_pos);

}

void ParticleChain::update(){

	addNewLocation();

	// Have it bounce off of the walls
	if (current_pos.x <= current_radius || current_pos.x >= ofGetWidth() - current_radius ){
		speed.x *= -1;
	}
	if (current_pos.y <= current_radius  || current_pos.y >= ofGetHeight() - current_radius ){
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

ofVec2f ParticleChain::getSpeed(){
	return speed;
}

void ParticleChain::setSpeed(ofVec2f new_speed){
	speed = new_speed;
}

double ParticleChain::getMass(){
	return PI * pow(current_radius, 2);
}

ofVec3f ParticleChain::getColor(){
	return color;
}

double ParticleChain::getRadius(){
	return current_radius;
}

void ParticleChain::setRadius(double new_radius){
	current_radius = new_radius;
}

void ParticleChain::addParticle(ofVec2f pos){

	
	particles.push_back(Particle(pos, current_radius));
}

void ParticleChain::addNewLocation(){
	ofVec2f new_pos = ofVec2f(current_pos.x + speed.x, current_pos.y + speed.y);
	current_pos = new_pos;
	addParticle(new_pos);
}

double ParticleChain::distance(ParticleChain other){

	//return sqrt( pow(current_pos.x - other.current_pos.x , 2) + pow (current_pos.y - other.current_pos.y , 2) );
	return distance(other.current_pos);
}

double ParticleChain::distance(ofVec2f other){

	return sqrt( pow(current_pos.x - other.x, 2) + pow (current_pos.y - other.y, 2) );
}