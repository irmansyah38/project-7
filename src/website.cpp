#include "website.h"

WebServer server(80); // Create a web server object that listens on port 80

void handlePageForm()
{
  String htmlPage = "<!DOCTYPE html>\
  <html>\
  <head>\
    <title>ESP32 Web Server</title>\
    <meta charset=\"UTF-8\">\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\
  </head>\
  <body>\
    <h1>Hello, World!</h1>\
    <p>This is a simple web server on ESP32.</p>\
  </body>\
  </html>";

  server.send(200, "text/html", htmlPage);
}

void handleSubmit()
{
}

void inializationWebsite()
{
  // Tentukan URL untuk halaman root dan fungsi handler
  server.on("/", handlePageForm);

  // Mulai web server
  server.begin();
}
void executeWebsite()
{
  server.handleClient();
}