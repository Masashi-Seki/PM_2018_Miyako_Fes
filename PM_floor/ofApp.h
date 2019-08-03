/*
* Tokyo Metropolitan University
* Code of the projection show at Miyako fest.
*
* Code of the floor.
* Written by Masashi Seki
*
* 2018.10.31 Wed.
*
* -----
* Code of floor.
* -----
*/

//----------------- common --------------------

#pragma once

#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

//----------------- ripple --------------------

class CustomBall {
	;
public:
	CustomBall();

	int r;
	int g;
	int b;
	int a;

	int x;
	int y;


	int radius;
	int lineWidth;
	int expandRate;
	int timer;

	bool dead;


	void update();
	void draw();

};

class ofApp : public ofBaseApp{

	public:
		//----------------- common --------------------
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
		int circleState[16];
		int circle_a[16];
		int circle_flag;
		bool circle_reset;

		int radius;
		int getData;

		ofSerial serial;
		

		bool open;
		int counter;

		int endingScene;

		ofImage mess1;
		ofImage mess2;
		ofImage mess2_2;
		ofImage mess3;
		ofImage mess4;
		ofImage mess4_2;

		int width;
		int height;

		int messType;

		float charRate;
		bool black;

		int scene;

		//----------------- circle --------------------


		//----------------- ripple --------------------
		vector <CustomBall> circles;
		int counter2;
};

//----------------- circle --------------------

#define posi1_x 961
#define posi1_y 229
#define posi2_x 806
#define posi2_y 333
#define posi3_x 653
#define posi3_y 438
#define posi4_x 491
#define posi4_y 548

#define posi5_x 1128
#define posi5_y 325
#define posi6_x 973
#define posi6_y 436
#define posi7_x 815
#define posi7_y 548
#define posi8_x 656
#define posi8_y 662

#define posi9_x 1300
#define posi9_y 425
#define posi10_x 1144
#define posi10_y 543
#define posi11_x 985
#define posi11_y 662
#define posi12_x 826
#define posi12_y 784

#define posi13_x 1468
#define posi13_y 522
#define posi14_x 1311
#define posi14_y 647
#define posi15_x 1153
#define posi15_y 775
#define posi16_x 995
#define posi16_y 905

#define vertex1_x 953
#define vertex1_y 128
#define vertex2_x 1634
#define vertex2_y 504
#define vertex3_x 1000
#define vertex3_y 1036
#define vertex4_x 307
#define vertex4_y 538

#endif


