#ifndef __C_USER_H
#define __C_USER_H

#include <user.h>
#include <vector>
#include <pyrite/server.h>
#include <mocutils/log.h>
#include <map>

extern std::vector<user> users;

void init_user();
prt::bytes login(sockaddr_in client_addr, prt::bytes data);

#endif