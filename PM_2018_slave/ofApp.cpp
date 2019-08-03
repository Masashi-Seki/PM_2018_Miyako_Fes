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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofHideCursor();
    CGDisplayHideCursor(NULL);
    
    ofBackground(0, 0, 0);
    ofSetFrameRate(30);
    
    black = false;
    
    movie.load("A_1102.mp4");
    qr.load("A_QR.mp4");
    
    movie.setLoopState(OF_LOOP_NONE);
    qr.setLoopState(OF_LOOP_NONE);
    
    sender.setup(IP_CONTROLLER, PORT_TO_CONTROLLER);
    receiver.setup(PORT_TO_SLAVE);
    
    movie_on = false;
    framecount = 0;
    
    videoType = 0;
    
    //-- movie start --

    //movie_on = true;
    //count_start = true;
    //play();
    //videoType=2;
    //QR_play();
}

//--------------------------------------------------------------
void ofApp::update(){
    movie.update();
    qr.update();
    
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if (m.getAddress() == "/pmap/media/play" ){
            count_start = true;
            play();
        }
        else if (m.getAddress() == "/pmap/media/pause"){
            pause();
        }
        else if (m.getAddress() == "/pmap/media/rewind") {
            count_start = false;
            rewind();
        }
        else if (m.getAddress() == "/pmap/screen/off") {
            screenOff();
        }
        else if (m.getAddress() == "/pmap/screen/on") {
            screenOn();
        }
        else if (m.getAddress() == "/pmap/connection/ask") {
            reply();
        }
        else if (m.getAddress() == "/pmap/media/QR_play") {
            count_start=true;
            QR_play();
        }
    }
    
    // start timing
    if(count_start){
        framecount ++;
        if(framecount == PLAY_ADJUST){
            movie_on = true;
        }
    }
    
    if(count_start == false){
        framecount = 0;
        movie_on = false;
    }
    
    cout << count_start << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(black == false && movie_on == true){
        cout << videoType<<endl;
        
        if (videoType == 1) {
            movie.draw(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
            //cout<<"draw movie"<<endl;
        }
        if (videoType == 2) {
            qr.draw(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
            //cout<<"draw qr"<<endl;
        }
    }
    //cout << videoType << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'q'){
        black = !black;
    }
}

//--------------------------------------------------------------
void ofApp::play(){
    movie.play();
    movie.setPaused(false);
    qr.setPaused(true);
    videoType = 1;
}

//--------------------------------------------------------------
void ofApp::QR_play() {
    qr.play();
    qr.setPaused(false);
    movie.setPaused(true);
    videoType = 2;
    cout<<"qr play"<<endl;
}

//--------------------------------------------------------------
void ofApp::pause() {
    movie.setPaused(true);
    qr.setPaused(true);
}

//--------------------------------------------------------------
void ofApp::rewind() {
    movie.setPosition(0.0);
    movie.setPaused(true);
    qr.setPosition(0.0);
    qr.setPaused(true);
    videoType = 0;
}

//--------------------------------------------------------------
void ofApp::screenOff() {
    black = true;
}

//--------------------------------------------------------------
void ofApp::screenOn() {
    black = false;
}

//--------------------------------------------------------------
void ofApp::reply() {
    // osc message
    ofxOscMessage message;
    message.setAddress("/pmap/connection/responce/A"); //change URL according to device name.
    
    //stalling
    for (int i = 0; i < 10000; i++);
    sender.sendMessage(message);
}
