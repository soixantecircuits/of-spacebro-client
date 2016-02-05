//
//  ofxSocketIO.cpp
//  spacebro-client
//
//  Created by hugohil on 05/02/16.
//
//
#include "ofxSocketIO.h"

void ofxSocketIO::setup (std::string &address) {
  currentStatus = "not connected";

  client.set_open_listener(std::bind(&ofxSocketIO::onConnect, this));
  client.set_close_listener(std::bind(&ofxSocketIO::onClose, this, std::placeholders::_1));
  client.set_fail_listener(std::bind(&ofxSocketIO::onFail, this));
  client.set_reconnect_listener(std::bind(&ofxSocketIO::onTryReconnect, this));

  client.connect(address);
}

void ofxSocketIO::onConnect () {
  ofLogNotice("ofxSocketIO", "connection");
  socket = client.socket();
  bindEvents();
  currentStatus = "connected";
  ofNotifyEvent(notifyEvent, currentStatus);
}

void ofxSocketIO::onClose (sio::client::close_reason const& reason) {
  currentStatus = "close";
  ofLogNotice("ofxSocketIO", currentStatus);
  ofNotifyEvent(notifyEvent, currentStatus);
}

void ofxSocketIO::onFail () {
  currentStatus = "error";
  ofLogNotice("ofxSocketIO", currentStatus);
  ofNotifyEvent(notifyEvent, currentStatus);
}

void ofxSocketIO::onTryReconnect () {
  currentStatus = "trying to reconnect";
  ofLogNotice("ofxSocketIO", currentStatus);
  ofNotifyEvent(notifyEvent, currentStatus);
}

void ofxSocketIO::bindEvents () {
  socket->on("server-event", sio::socket::event_listener_aux([&] (string const& name, sio::message::ptr const& data, bool isAck, sio::message::list &ack_resp) {
    ofLogNotice("ofxSocketIO - name", ofToString(name));
    currentStatus = name;
    ofNotifyEvent(notifyEvent, currentStatus);
  }));
}

void ofxSocketIO::closeConnection () {
  client.sync_close();
}