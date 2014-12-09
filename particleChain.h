
#include "ofMain.h"
#include "particle.h"

class ParticleChain{

public:
	ParticleChain();
	ParticleChain(ofVec3f color, ofVec2f start_speed, ofVec2f starting_pos);
	
	void update();
	void draw();



	void addParticle(ofVec2f pos);
	void addNewLocation();
	double distance(ParticleChain other);

private:

	ofVec3f color;
	std::list<Particle> particles;

	ofVec2f speed;

	ofVec2f current_pos;

};