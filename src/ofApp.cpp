#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  address = "http://127.0.0.1:8888";
  status = "not connected";
  sioHandler.setup(address);
  ofAddListener(sioHandler.notifyConnection, this, &ofApp::onConnection);
  ofAddListener(sioHandler.notifyDisconnect, this, &ofApp::onDisconnect);
  ofAddListener(sioHandler.notifyError, this, &ofApp::onError);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofDrawBitmapStringHighlight(ofApp::status, 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::onConnection () {
  status = "connected";
}

void ofApp::onDisconnect () {
  status = "not connected";
}

void ofApp::onError () {
  status = "error";
}
