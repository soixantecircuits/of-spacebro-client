//
//  socketListener.cpp
//  spacebro-client
//
//  Created by hugohil on 04/02/16.
//
//

#include "socketListener.h"

void connection_listener::on_connected () {
  std::cout<<"sio connected "<<std::endl;
}

void connection_listener::on_close (sio::client::close_reason const& reason) {
  std::cout<<"sio closed "<<std::endl;
  exit(0);
}

void connection_listener::on_fail () {
  std::cout<<"sio failed "<<std::endl;
  exit(0);
}