#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include <iostream>

#include <./basic/point.h>

#define OVAL_A 1
#define OVAL_B 1
#define NO_BUILDING -1

class Building
{
private:
  int id = NO_BUILDING;
  std::string owner_id;
  double scale = 1;

public:
  Building(int _id, std::string _onwer, double _scale = 1)
      : id(_id), owner_id(_onwer), scale(_scale) {}
  ~Building();
  int getId() { return id; }
  std::string getOwnerId() { return owner_id; }
  double getScale() { return scale; }
};

#endif