
#include "ofMain.h"
#include "particle.h"

class ParticleChain{

public:
	ParticleChain();
	ParticleChain(ofVec3f color, ofVec2f start_speed, ofVec2f starting_pos);
	
	void update();
	void draw();

	ofVec2f getSpeed();
	void setSpeed(ofVec2f new_speed);
	double getMass();
	ofVec3f getColor();
	double getRadius();
	void setRadius(double new_radius);

	void addParticle(ofVec2f pos);
	void addNewLocation();
	double distance(ParticleChain other);
	double distance(ofVec2f other);

private:

	ofVec3f color;
	std::list<Particle> particles;

	ofVec2f speed;

	ofVec2f current_pos;

	double current_radius;

};