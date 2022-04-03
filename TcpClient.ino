#include <WiFi.h>
#include "TcpClient.h"

const char* ssid = "MGTS-455";
const char* password = "4953306832";

const uint16_t port = 8081;
const char * host = "192.168.100.9";

const int start_msg_size = 5;

void setup()
{
  Serial.begin(115200);

  delay(5000);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  TcpClient tcp_client(5);

  if (!tcp_client.connect_to(host, port)) {
      Serial.println("Connection to host failed");
      delay(1000);
      return;
  }
  while(tcp_client.is_connected())
  {
    String msg = "aboba";

    tcp_client.write_socket(msg);

    tcp_client.read_socket(msg);

    Serial.print("server: ");
    Serial.println(msg);

    delay(1000);
  }
}
