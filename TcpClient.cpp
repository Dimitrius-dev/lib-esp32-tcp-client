#include "TcpClient.h"

TcpClient::TcpClient(int start_msg_size)
{
  this->start_msg_size = start_msg_size;
}

void TcpClient::msg_size_norm(String &msg)
{
  while(msg.length() < start_msg_size)
  {
    msg = "0" + msg;
  }
}

bool TcpClient::connect_to(const char * host, const uint16_t port)
{
  return client.connect(host, port);
}

bool TcpClient::is_connected()
{
  return client.connected();
}

void TcpClient::write_socket(String& msg_ext)
{  
  String msg_head = String(msg_ext.length());
  msg_size_norm(msg_head);
  
  client.write(msg_head.c_str(), msg_head.length());

  client.write(msg_ext.c_str(), msg_ext.length());
}

void TcpClient::read_socket(String& msg_ext)
{
  msg_ext.clear();
  //Serial.println("err1");
  while (client.available() == 0){}
  //Serial.println("err2");
  
  String msg_head = "";
  for(int i = 0; i < start_msg_size; i++)
  {
    //Serial.println("err3--");
    char c = 255;
    while(c == 255)
    {
      //Serial.println("no_msg--");
      c = client.read();
    }
  
    //Serial.print(c);
    msg_head += c;
  }
  //Serial.println("");

  int msg_size = msg_head.toInt();

  //Serial.println(msg_size);
  //Serial.println(msg_head);

  for(int i = 0; i < msg_size; i++)
  {
    char c = 255;
    while(c == 255)
    {
      c = client.read();
    }
    
    //Serial.print(int(c));
    //Serial.println("err4--");
    msg_ext += c;
  }
  //Serial.println("");
  
}
