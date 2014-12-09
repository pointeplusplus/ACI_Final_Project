
#include "ofMain.h"
#include "particle.h"

class ParticleChain{

public:
	ParticleChain();
	ParticleChain(ofVec3f color, double x, double y, ofVec2f starting_pos);
	
	void update();
	void draw();

	void addParticle(ofVec2f pos);
	void addNewLocations();

private:

	ofVec3f color;
	std::list<Particle> particles;

	double speedX;
	double speedY;

	ofVec2f current_pos;

};