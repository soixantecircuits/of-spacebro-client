//
//  socketHandler.hpp
//  spacebro-client
//
//  Created by hugohil on 04/02/16.
//
//

#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include <stdio.h>

#if defined(_MSC_VER) || defined(_WIN32) || defined(WIN32) || defined(__MINGW32__)
  // Windows stuff
#else
  // Linux and OSX here
  #include <sio_client.h>
#endif

using namespace std;
using namespace sio;

class socketHandler: protected ofThread {

  private:
    sio::client handler;

    void onConnected();
    void onClosed();
    void onFailed();

  public:
    void setup(string& address);

    ofEvent<void> notifyConnection;
    ofEvent<void> notifyDisconnect;
    ofEvent<void> notifyError;
};
