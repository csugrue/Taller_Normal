/*
 *  particle.h
 *  normalClassObjects
 *
 *  Created by Chris on 2/25/13.
 *  Copyright 2013 csugrue. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

class Particle{

	public:
		Particle(){};
		
		void setup();
		void update();
		
		ofVec3f vel;
		ofPoint pos;
		float size;
		
};