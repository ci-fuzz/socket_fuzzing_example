#include <iostream>
#include <flibc.h>
#include <string.h>
#include <stdint.h>
#include "func.h"

int StartServer(int argc, char**argv) {
  ForkingServer();
  return 0;
}


FUZZ_SERVER(StartServer, 5001, int client_fd, const uint8_t* data,
            size_t size) {
  write(client_fd, data, size);
}
