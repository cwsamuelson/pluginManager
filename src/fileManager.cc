#include<iostream>
#include<vector>
#include<dirent.h>
#include"fileManager.hh"

std::vector<std::string>* fileManager::getFiles(std::string dir){
  DIR *dp;
  struct dirent *dirp;
  std::string bad1(".");
  std::string bad2("..");
  std::vector<std::string>* files = new std::vector<std::string>;

  if((dp  = opendir(dir.c_str())) == NULL) {
    std::cerr << "Error(" << errno << ") opening " << dir << std::endl;
    return 0;
  }

  while ((dirp = readdir(dp)) != NULL) {
    std::string tmp(dirp->d_name);
    if(tmp != bad1 && tmp!= bad2){
      files->push_back(tmp);
    }
  }

  closedir(dp);
  return files;
}
