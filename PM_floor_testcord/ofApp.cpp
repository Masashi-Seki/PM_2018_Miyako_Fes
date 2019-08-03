/*
* Tokyo Metropolitan University
* Code of the projection show at Miyako fest.
*
* Test Code of the floor.
* Written by Masashi Seki
*
* 2019.2.6 Wed.
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofHideCursor();
	//CGDisplayHideCursor(NULL);

	serial.setup("COM3", 9600); //Windows
	//serial.setup("/dev/tty.usbmodem1411",9600); //Mac
}

//--------------------------------------------------------------
void ofApp::update() {
	getData = 0;
	getData = serial.readByte();

	if (getData == 0x01) {
		cout << "button1 pushed" << endl;
		serial.writeByte(0x01);
	}
	else if (getData == 0x02) {
		cout << "button2 pushed" << endl;
		serial.writeByte(0x02);
	}
	else if (getData == 0x03) {
		cout << "button3 pushed" << endl;
		serial.writeByte(0x03);
	}
	else if (getData == 0x04) {
		cout << "button4 pushed" << endl;
		serial.writeByte(0x04);
	}
	else if (getData == 0x05) {
		cout << "button5 pushed" << endl;
		serial.writeByte(0x05);
	}
	else if (getData == 0x06) {
		cout << "button6 pushed" << endl;
		serial.writeByte(0x06);
	}
	else if (getData == 0x07) {
		cout << "button7 pushed" << endl;
		serial.writeByte(0x07);
	}
	else if (getData == 0x08) {
		cout << "button8 pushed" << endl;
		serial.writeByte(0x08);
	}
	else if (getData == 0x09) {
		cout << "button9 pushed" << endl;
		serial.writeByte(0x09);
	}
	else if (getData == 0x0A) {
		cout << "button10 pushed" << endl;
		serial.writeByte(0x0A);
	}
	else if (getData == 0x0B) {
		cout << "button11 pushed" << endl;
		serial.writeByte(0x0B);
	}
	else if (getData == 0x0C) {
		cout << "button12 pushed" << endl;
		serial.writeByte(0x0C);
	}
	else if (getData == 0x0D) {
		cout << "button13 pushed" << endl;
		serial.writeByte(0x0D);
	}
	else if (getData == 0x0E) {
		cout << "button14 pushed" << endl;
		serial.writeByte(0x0E);
	}
	else if (getData == 0x0F) {
		cout << "button15 pushed" << endl;
		serial.writeByte(0x0F);
	}
	else if (getData == 0x10) {
		cout << "button16 pushed" << endl;
		serial.writeByte(0x10);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'r')
		serial.writeByte(0xFF);
}