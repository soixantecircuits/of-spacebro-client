//
//  ofxSocketIO.h
//  spacebro-client
//
//  Created by hugohil on 05/02/16.
//
//
#pragma once

#include "ofMain.h"
#if defined(_MSC_VER) || defined(_WIN32) || defined(WIN32) || defined(__MINGW32__)
  // Windows stuff
#else
  // Linux and OSX here
  #include <sio_client.h>
#endif

class ofxSocketIO : protected ofThread {
  private :
    sio::client client;

  public :
    void setup(std::string& address);

    void onConnect();
    void onClose(sio::client::close_reason const& reason);
    void onFail();
    void onTryReconnect();
};