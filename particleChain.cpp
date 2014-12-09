
#include "particleChain.h"

ParticleChain::ParticleChain(){

}

ParticleChain::ParticleChain(ofVec3f color, double x, double y, ofVec2f starting_pos){
	this->color = color;
	
	speedX = x;
	speedY = y;

	current_pos = starting_pos;

	//FOR TESTING
	speedX = 10;
	speedY = 4;

	addParticle(starting_pos);

}

void ParticleChain::update(){

	std::cout << "Particle chain update.  Length" << particles.size() << std::endl;
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
//		std::cout << "    Done updating single particle" << std::endl;
	}
}

void ParticleChain::draw(){
//	std::cout << "Num particles: " << particles.size() << endl;

	//std::cout << "curr chain color: " << color.x << " " << color.y << " " << color.z << std::endl;
	for(list<Particle>::iterator p = particles.begin(); p != particles.end(); p++){
//		std::cout << "    draw a particle:" << std::endl;		
		p->draw(color);
	}
}

void ParticleChain::addParticle(ofVec2f pos){

	particles.push_back(Particle(pos));
}

void ParticleChain::addNewLocations(){

	ofVec2f new_pos = ofVec2f(current_pos.x + speedX, current_pos.y + speedY);
	current_pos = new_pos;
	addParticle(new_pos);
}