#include <stdio.h>
#include "lib/snap7/snap7.h"

typedef unsigned char byte;

TS7Server* server;
byte DB1[512];
byte DB2[128];
byte DB3[1024];
byte MB[2048];

int main() {
  printf("Snap7 Server\n");
  
  int err;
  server = new TS7Server;
  
  server->RegisterArea(srvAreaDB, 1, &DB1, sizeof(DB1));
  server->RegisterArea(srvAreaDB, 2, &DB2, sizeof(DB2));
  server->RegisterArea(srvAreaDB, 3, &DB3, sizeof(DB3));
  server->RegisterArea(srvAreaMK, 0, &MB, sizeof(MB));
  
  err = server->Start();
  if (err == 0) {
    printf("Online...\n");
    getchar();
  } else {
    printf("%s\n", SrvErrorText(err).c_str());
  }
  
  server->Stop();
  delete server;
  
  return 0;
}