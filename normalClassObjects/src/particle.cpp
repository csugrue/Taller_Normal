/*
 *  particle.cpp
 *  normalClassObjects
 *
 *  Created by Chris on 2/25/13.
 *  Copyright 2013 csugrue. All rights reserved.
 *
 */

#include "particle.h"

void Particle::setup(){
	size = ofRandom(10,20);
	vel.set(ofRandom(-5,5),ofRandom(-1,-10),0);
	pos.set(0,0,0);
}

void Particle::update(){
	pos += vel;
	vel += ofVec3f(0,.1,0);
	
}


