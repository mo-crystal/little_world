#include "spyrite.h"
#include "suser.h"
#include <mocutils/log.h>

prt::server *server;

void init_pyrite() {
  server = new prt::server(8081);
  server->set_handler("login", login);
  server->set_handler("whoami", whoami);
  server->async();
}
