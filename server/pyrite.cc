#include "spyrite.h"
#include <mocutils/log.h>

prt::server *server;

extern prt::bytes login(sockaddr_in, prt::bytes);

void init_pyrite() {
  server = new prt::server(8081);
  server->set_handler("login", login);
  server->async();
}
