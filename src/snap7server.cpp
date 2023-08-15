#include <stdio.h>
#include <snap7.h>
#include <logs.h>

typedef unsigned char byte;

TS7Server* server;
byte DB1 [2048];
byte DB2 [2048];
byte DB3 [2048];
byte MB  [2048];

void setup_memory() {
  log_info("Setup memories");

  server->RegisterArea(srvAreaDB, 1, &DB1, sizeof(DB1));
  server->RegisterArea(srvAreaDB, 2, &DB2, sizeof(DB2));
  server->RegisterArea(srvAreaDB, 3, &DB3, sizeof(DB3));
  server->RegisterArea(srvAreaMK, 0, &MB, sizeof(MB));
}

int main() {
  log_info("Snap 7 Server");
  
  int err;
  server = new TS7Server;
  
  setup_memory();
  
  err = server->Start();
  if (err == 0) {
    log_ok("Online ... [press enter to finish]");
    getchar();
  } else {
    log_err("%s", SrvErrorText(err).c_str());
    return 1;
  }
  
  server->Stop();
  delete server;
  
  return 0;
}