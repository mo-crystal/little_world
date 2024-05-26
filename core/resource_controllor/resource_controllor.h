#ifndef RESOURCE_CONTROLLOR_H
#define RESOURCE_CONTROLLOR_H

#include<string>
#include<vector>
#include<unordered_map>

class ResourceControllor
{
private:
  std::unordered_map<std::string,std::vector<std::string>> resourse_map;
public:
  ResourceControllor(std::string path);
  ~ResourceControllor();
};




#endif