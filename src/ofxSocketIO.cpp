//
//  ofxSocketIO.cpp
//  spacebro-client
//
//  Created by hugohil on 05/02/16.
//
//
#include "ofxSocketIO.h"

void ofxSocketIO::setup (std::string &address) {
  client.set_open_listener(std::bind(&ofxSocketIO::onConnect, this));
  client.set_close_listener(std::bind(&ofxSocketIO::onClose, this, std::placeholders::_1));
  client.set_fail_listener(std::bind(&ofxSocketIO::onFail, this));
  client.set_reconnect_listener(std::bind(&ofxSocketIO::onTryReconnect, this));

  client.connect(address);
}

void ofxSocketIO::onConnect () {
  std::cout<<"sio connected "<<std::endl;
}

void ofxSocketIO::onClose (sio::client::close_reason const& reason) {
  std::cout<<"sio closed "<<std::endl;
  exit(0);
}

void ofxSocketIO::onFail () {
  std::cout<<"sio failed "<<std::endl;
  exit(0);
}

void ofxSocketIO::onTryReconnect () {
  std::cout<<"sio attempting to reconnect "<<std::endl;
}