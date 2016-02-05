//
//  socketListener.hpp
//  spacebro-client
//
//  Created by hugohil on 04/02/16.
//
//

#pragma once

#include "ofMain.h"
#include <stdio.h>

#if defined(_MSC_VER) || defined(_WIN32) || defined(WIN32) || defined(__MINGW32__)
  // Windows stuff
#else
  // Linux and OSX here
  #include <sio_client.h>
#endif

class connection_listener {
  sio::client &handler;

public:
  connection_listener(sio::client& h):
    handler(h){}

  void on_connected();
  void on_close(sio::client::close_reason const& reason);
  void on_fail();
};
