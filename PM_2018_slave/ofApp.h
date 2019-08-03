/*
 * Toyko Metropolitan University
 * Code of the projection show at Miyako fest.
 *
 * Code of the slave (projector).
 * Written by Masashi Seki
 *
 * 2018.10.30 Tue.
 *
 * -----
 * Set IP address of controller in ofApp.h
 * Change the device name of URL of function reply() in ofApp.cpp
 * -----
 */

#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT_TO_SLAVE 8000
#define PORT_TO_CONTROLLER 7000

#define IP_CONTROLLER "192.168.11.4" //IP address of controller

#define PLAY_ADJUST 2

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    void play();
    void pause();
    void rewind();
    void screenOff();
    void screenOn();
    void reply();
    void QR_play();
    
    bool black;
    
    ofxOscSender sender;
    ofxOscReceiver receiver;
    
    ofVideoPlayer movie;
    ofVideoPlayer qr;
    
    int framecount;
    bool count_start;
    bool movie_on;
    
    int videoType;
    
};
