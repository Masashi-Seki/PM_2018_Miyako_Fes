#include "ofMain.h"
#include "ofApp.h"

int main(){
    ofSetupOpenGL(768,768,OF_FULLSCREEN);
    //ofSetupOpenGL(768,768,OF_WINDOW);
    
	ofRunApp(new ofApp());
}
