#ifndef POINT_H
#define POINT_H

#include<cmath>

class Point
{
private:
  int x,y;
public:
  Point(int _x,int _y):x(_x),y(_y){}
  ~Point();
  int get_x(){return x;}
  int get_y(){return y;}
  int get_distance(Point &p);
};



#endif