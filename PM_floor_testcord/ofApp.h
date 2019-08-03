/*
* Tokyo Metropolitan University
* Code of the projection show at Miyako fest.
*
* Test Code of the floor.
* Written by Masashi Seki
*
* 2019.2.6 Wed.
*/

#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	ofSerial serial;
	int getData;
};