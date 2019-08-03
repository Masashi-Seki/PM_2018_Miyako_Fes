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

#include "ofApp.h"

//----------------- ripple --------------------

CustomBall::CustomBall() {

	r = ofRandom(0, 250);
	g = ofRandom(0, 250);
	b = ofRandom(0, 250);
	a = 250;

	radius = ofRandom(10, 50);
	lineWidth = ofRandom(5, 15);
	expandRate = 2;

	dead = false;
	timer = 250;

}

void CustomBall::update() {
	radius += expandRate;

	r += 1;
	g += 1;
	b += 1;

	timer -= 1;
	a -= 1;

	if (timer < 0) {
		dead = true;
	}

}

void CustomBall::draw() {
	ofSetColor(r, g, b, a);
	ofNoFill();
	ofSetLineWidth(lineWidth);
	ofCircle(x, y, radius);
}

//--------------------------------------------------------------
void ofApp::setup(){
	
	//----------------- common --------------------
	ofHideCursor();
	//CGDisplayHideCursor(NULL);

	width = ofGetScreenWidth();
	height = ofGetScreenHeight();

	mess1.load("mess1_.png");
	mess2.load("mess2.png");
	mess2_2.load("mess2_2.png");
	mess3.load("mess3.png");
	mess4.load("mess4.png");
	mess4_2.load("mess4_2.png");

	ofSetFrameRate(60);
	//ofSetCircleResolution(64);  //円の解像度
	ofSetCircleResolution(150);  //円の解像度
	

	radius = 70;
	circle_flag = 0;

	for (int i = 0; i < 16; i++) {
		circleState[i] = 0;
		circle_a[i] = 255;
	}

	serial.setup("COM3", 9600); //Windows
	//serial.setup("/dev/tty.usbmodem1411",9600); //Mac

	serial.writeByte(0xFF);

	scene = 1;

	//----------------- coicle --------------------
	messType = 1;
	circle_reset = false;

	//----------------- ripple --------------------
	ofEnableSmoothing();
	counter2 = 0;


}

//--------------------------------------------------------------
void ofApp::update(){

	//----------------- common --------------------
	circle_flag = 0;
	getData = 0;

	//シリアル受信処理
	getData = serial.readByte();

	if (scene == 1) {
		if (circle_reset == false) {
			if (getData == 0x01) {
				circle_a[0] = 0;
				serial.writeByte(0x01);
			}
			else if (getData == 0x02) {
				circle_a[1] = 0;
				serial.writeByte(0x02);

			}
			else if (getData == 0x03) {
				circle_a[2] = 0;
				serial.writeByte(0x03);

			}
			else if (getData == 0x04) {
				circle_a[3] = 0;
				serial.writeByte(0x04);

			}
			else if (getData == 0x05) {
				circle_a[4] = 0;
				serial.writeByte(0x05);

			}
			else if (getData == 0x06) {
				circle_a[5] = 0;
				serial.writeByte(0x06);

			}
			else if (getData == 0x07) {
				circle_a[6] = 0;
				serial.writeByte(0x07);

			}
			else if (getData == 0x08) {
				circle_a[7] = 0;
				serial.writeByte(0x08);
			}
			else if (getData == 0x09) {
				circle_a[8] = 0;
				serial.writeByte(0x09);
			}
			else if (getData == 0x0A) {
				circle_a[9] = 0;
				serial.writeByte(0x0A);

			}
			else if (getData == 0x0B) {
				circle_a[10] = 0;
				serial.writeByte(0x0B);

			}
			else if (getData == 0x0C) {
				circle_a[11] = 0;
				serial.writeByte(0x0C);

			}
			else if (getData == 0x0D) {
				circle_a[12] = 0;
				serial.writeByte(0x0D);

			}
			else if (getData == 0x0E) {
				circle_a[13] = 0;
				serial.writeByte(0x0E);

			}
			else if (getData == 0x0F) {
				circle_a[14] = 0;
				serial.writeByte(0x0F);

			}
			else if (getData == 0x10) {
				circle_a[15] = 0;
				serial.writeByte(0x10);
			}
		}
	}
	else if (scene == 2) {
		if (getData == 0x01) {
			CustomBall sampleCircle;
			sampleCircle.x = posi1_x;
			sampleCircle.y = posi1_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x01);
		}
		else if (getData == 0x02) {
			CustomBall sampleCircle;
			sampleCircle.x = posi2_x;
			sampleCircle.y = posi2_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x02);
		}
		else if (getData == 0x03) {
			CustomBall sampleCircle;
			sampleCircle.x = posi3_x;
			sampleCircle.y = posi3_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x03);
		}
		else if (getData == 0x04) {
			CustomBall sampleCircle;
			sampleCircle.x = posi4_x;
			sampleCircle.y = posi4_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x04);
		}
		else if (getData == 0x05) {
			CustomBall sampleCircle;
			sampleCircle.x = posi5_x;
			sampleCircle.y = posi5_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x05);
		}
		else if (getData == 0x06) {
			CustomBall sampleCircle;
			sampleCircle.x = posi6_x;
			sampleCircle.y = posi6_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x06);
		}
		else if (getData == 0x07) {
			CustomBall sampleCircle;
			sampleCircle.x = posi7_x;
			sampleCircle.y = posi7_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x07);
		}
		else if (getData == 0x08) {
			CustomBall sampleCircle;
			sampleCircle.x = posi8_x;
			sampleCircle.y = posi8_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x08);
		}
		else if (getData == 0x09) {
			CustomBall sampleCircle;
			sampleCircle.x = posi9_x;
			sampleCircle.y = posi9_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x09);
		}
		else if (getData == 0x0A) {
			CustomBall sampleCircle;
			sampleCircle.x = posi10_x;
			sampleCircle.y = posi10_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x0A);
		}
		else if (getData == 0x0B) {
			CustomBall sampleCircle;
			sampleCircle.x = posi11_x;
			sampleCircle.y = posi11_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x0B);
		}
		else if (getData == 0x0C) {
			CustomBall sampleCircle;
			sampleCircle.x = posi12_x;
			sampleCircle.y = posi12_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x0C);
		}
		else if (getData == 0x0D) {
			CustomBall sampleCircle;
			sampleCircle.x = posi13_x;
			sampleCircle.y = posi13_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x0D);
		}
		else if (getData == 0x0E) {
			CustomBall sampleCircle;
			sampleCircle.x = posi14_x;
			sampleCircle.y = posi14_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x0E);
		}
		else if (getData == 0x0F) {
			CustomBall sampleCircle;
			sampleCircle.x = posi15_x;
			sampleCircle.y = posi15_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x0F);
		}
		else if (getData == 0x10) {
			CustomBall sampleCircle;
			sampleCircle.x = posi16_x;
			sampleCircle.y = posi16_y;
			circles.push_back(sampleCircle);
			//serial.writeByte(0x10);
		}
	}

	//----------------- circle --------------------
	if (scene == 1) {

	}
	//----------------- ripple --------------------
	else if (scene == 2) {

		for (int i = 0; i < circles.size(); i++) {
			circles[i].update();
			if (circles[i].dead) {
				circles.erase(circles.begin() + i);
			}
		}

	}

}

//--------------------------------------------------------------
void ofApp::draw() {

	//----------------- common --------------------

	ofBackground(0, 0, 0);

	if (black == false) {
		//draw of frame
		ofSetColor(255, 255, 255);
		ofSetLineWidth(3);
		ofLine(vertex1_x, vertex1_y, vertex2_x, vertex2_y);
		ofLine(vertex2_x, vertex2_y, vertex3_x, vertex3_y);
		ofLine(vertex3_x, vertex3_y, vertex4_x, vertex4_y);
		ofLine(vertex4_x, vertex4_y, vertex1_x, vertex1_y);

		ofFill();
		ofSetColor(0, 0, 255, circle_a[0]); ofCircle(posi1_x, posi1_y, radius);
		ofSetColor(0, 255, 0, circle_a[1]); ofCircle(posi2_x, posi2_y, radius);
		ofSetColor(255, 255, 0, circle_a[2]); ofCircle(posi3_x, posi3_y, radius);
		ofSetColor(255, 0, 255, circle_a[3]); ofCircle(posi4_x, posi4_y, radius);
		ofSetColor(0, 255, 255, circle_a[4]); ofCircle(posi5_x, posi5_y, radius);
		ofSetColor(0, 255, 70, circle_a[5]); ofCircle(posi6_x, posi6_y, radius);
		ofSetColor(255, 183, 76, circle_a[6]); ofCircle(posi7_x, posi7_y, radius);
		ofSetColor(221, 132, 22, circle_a[7]); ofCircle(posi8_x, posi8_y, radius);
		ofSetColor(67, 135, 233, circle_a[8]); ofCircle(posi9_x, posi9_y, radius);
		ofSetColor(149, 255, 101, circle_a[9]); ofCircle(posi10_x, posi10_y, radius);
		ofSetColor(255, 255, 255, circle_a[10]); ofCircle(posi11_x, posi11_y, radius);
		ofSetColor(255, 49, 25, circle_a[11]); ofCircle(posi12_x, posi12_y, radius);
		ofSetColor(156, 167, 22, circle_a[12]); ofCircle(posi13_x, posi13_y, radius);
		ofSetColor(168, 239, 175, circle_a[13]); ofCircle(posi14_x, posi14_y, radius);
		ofSetColor(244, 250, 37, circle_a[14]); ofCircle(posi15_x, posi15_y, radius);
		ofSetColor(225, 0, 178, circle_a[15]); ofCircle(posi16_x, posi16_y, radius);

		//message
		if (messType == 0) {

		}
		else if (messType == 1) {
			ofSetColor(255, 255, 255, 255);
			charRate = 1.3;
			//mess1.draw(1200, 900, 517 * charRate, 72 * charRate);
			//mess1.draw(100, 900, 517 * charRate, 72 * charRate);
			mess1.draw(1350, 900, 251 * charRate, 90 * charRate);
			mess1.draw(300, 900, 251 * charRate, 90 * charRate);
		}
		else if (messType == 2) {
			ofSetColor(255, 255, 255, 255);
			charRate = 1.3;
			mess2.draw(1200, 900, 418 * charRate, 89 * charRate);
			mess2.draw(150, 900, 418 * charRate, 89 * charRate);
			mess2_2.draw(1400, 750, 301 * charRate, 93 * charRate);
			mess2_2.draw(50, 750, 301 * charRate, 93 * charRate);
		}
		else if (messType == 3) {
			ofSetColor(255, 255, 255, 255);
			charRate = 1.3;
			mess3.draw(1200, 900, 529 * charRate, 104 * charRate);
			mess3.draw(50, 900, 529 * charRate, 104 * charRate);
		}
		else if (messType == 4) {
			ofSetColor(255, 255, 255, 255);
			charRate = 1.2;
			mess4.draw(1500, 900, 219 * charRate, 90 * charRate);
			mess4.draw(200, 900, 219 * charRate, 90 * charRate);
			charRate = 0.9;
			mess4_2.draw(1300, 800, 697 * charRate, 104 * charRate);
			mess4_2.draw(30, 800, 697 * charRate, 104 * charRate);
		}
	}

	//----------------- circle --------------------
	cout << circle_reset << " " << messType << " " << scene << " " << counter2 << " " << circle_a[0] << endl;

	if (scene == 1) {

		for (int i = 0; i < 16; i++) {
			if (circle_a[i] == 0)
				circle_flag++;
		}

		if (circle_flag == 16) {
			circle_reset = true;
			serial.writeByte(0xFF);
			//for (int i = 0; i < 100000000; i++); //stalling
		}

		

		if (circle_reset == true) {
			
			if (messType == 3) {
				messType = 4;
				circle_reset = false;
			}
			else if (messType == 4) {
				//none
				circle_reset = false;
			}
			else {
				for (int i = 0; i < 16; i++) {
					circle_a[i] += 2;
				}

				if (circle_a[0] > 250) {
					circle_reset = false;
					if (messType == 2) {
						scene = 2;
						messType = 1;
					}
				}
			}
		}
	}
	//----------------- ripple --------------------
	else if (scene == 2) {

		if (black == false) {
			for (int i = 0; i < circles.size(); i++) {
				circles[i].draw();
			}
		}


		if (messType == 1) {

		}
		else if (messType == 2) {
			counter2++;
			if (counter2 > 1500) {

				if (counter2 == 1501) {
					for (int i = 0; i < 16; i++) {
						circle_a[i] = 0;
					}
				}
				for (int i = 0; i < 16; i++) {
					circle_a[i] += 2;
				}

				if (circle_a[0] > 250) {
					circle_reset = false;
					scene = 1;
					messType = 1;
					counter2 = 0;
				}
			}
		}
		else if (messType == 3) {
			counter2++;
			if (counter2 > 1500) {
				messType = 4;
				counter2 = 0;
			}
		}
		else if (messType == 4) {
			//none
			for (int i = 0; i < 16; i++) {
				circle_a[i] -= 2;
				if (circle_a[i] < 0)
					circle_a[i] = 0;
				if (circle_a[0] == 0)
					scene = 0;
			}
			circle_reset = false;
		}

	}
	else {

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'q') {
		black = !black;
	}
	
	if (circle_reset == false) {
		if (key == 'r') {
			circle_a[0] = 0;
			messType = 1;
			circle_reset = true;
			serial.writeByte(0xFF);
			counter2 = 0;
			scene = 1;
		}
		else if (key == 'n') {
			messType = 2;
			counter2 = 0;
			circle_reset = false;
		}
		else if (key == 'e') {
			messType = 3;
			counter2 = 0;
		}
	}
}

