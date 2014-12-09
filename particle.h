
#include "ofMain.h"

#define STARTING_RADIUS_SIZE 40
#define ALPHA_STEP_SIZE .93
#define RADIUS_REDUCTION .96
#define SPEED_CONSTANT 50

class Particle{

public:
	Particle();
	Particle(ofVec2f loc, double radius);

	void draw(ofVec3f color);
	bool update();

private:
	
	ofVec2f location;
	int frameNumber; //how many frames this particle has been around for
	double currentSize;
	double currentAlpha;

};