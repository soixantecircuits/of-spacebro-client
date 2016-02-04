//
//  socketHandler.cpp
//  spacebro-client
//
//  Created by hugohil on 04/02/16.
//
//

#include "socketHandler.hpp"

void socketHandler::setup (string& address) {

  handler.set_open_listener(std::bind(&socketHandler::onConnected, this));
  handler.set_close_listener(std::bind(&socketHandler::onClosed, this));
  handler.set_fail_listener(std::bind(&socketHandler::onFailed, this));

  handler.connect(address);
}


void socketHandler::onConnected () {
  ofNotifyEvent(notifyConnection);
}

void socketHandler::onClosed () {
  ofNotifyEvent(notifyDisconnect);
}

void socketHandler::onFailed () {
  ofNotifyEvent(notifyError);
}