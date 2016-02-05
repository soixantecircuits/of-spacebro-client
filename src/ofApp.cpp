#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  address = "http://127.0.0.1:8888";
  status = "not connected";

  connection_listener listener(h);

  h.set_open_listener(std::bind(&connection_listener::on_connected, &listener));
  h.set_close_listener(std::bind(&connection_listener::on_close, &listener, std::placeholders::_1));
  h.set_fail_listener(std::bind(&connection_listener::on_fail, &listener));

  h.connect(address);
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
