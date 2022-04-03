#pragma once
#include <Arduino.h>
#include <WiFi.h>

class TcpClient
{
private:
  int start_msg_size = 5;
  //String msg = "";
  //int msg_size = 0;
  WiFiClient client;
private:
  void msg_size_norm(String &msg);

public:
  TcpClient(int start_msg_size);

  bool connect_to(const char * host, const uint16_t port);

  bool is_connected();

  void write_socket(String& msg_ext);
  void read_socket(String& msg_ext);
  
};
