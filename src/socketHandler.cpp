//
//  socketHandler.cpp
//  spacebro-client
//
//  Created by hugohil on 04/02/16.
//
//

#include "socketHandler.hpp"

void socketHandler::setup (string& address) {

  handler.set_open_listener(std::bind(&socketHandler::onClientConnected, this));
  handler.set_close_listener(std::bind(&socketHandler::onClientClosed, this, std::placeholders::_1));
  handler.set_fail_listener(std::bind(&socketHandler::onClientFailed, this));

  handler.connect(address);
}

void socketHandler::bindEvents () {
//  currentSocket->on("disconnect", sio::socket::event_listener_aux([&] (string const& name, sio::message::ptr const& data, bool isAck, sio::message::list &ack_resp) {
//    ofNotifyEvent(notifyDisconnect);
//  }));
}

void socketHandler::onClientConnected () {
  currentSocket = handler.socket();
  ofNotifyEvent(notifyConnection);
  bindEvents();
}

void socketHandler::onClientClosed (sio::client::close_reason const& reason) {
  ofNotifyEvent(notifyDisconnect);
}

void socketHandler::onClientFailed () {
  ofNotifyEvent(notifyError);
}
