#include "DirList.h"

std::vector<FilePro>  DirList::traverse(std::string path){
  std::vector<FilePro> results;
  DIR *dir = opendir(path.c_str());
  if(dir == NULL){
    closedir(dir);
    return results;
  }
  else{
    dirent *p = NULL;
    while((p = readdir(dir)) != NULL){
      FilePro obj;
      std::string filename = path + "/" +  std::string(p -> d_name);
      obj.setFilename(filename);
      struct stat s_buf;
      stat(filename.c_str(), &s_buf);
      if(S_ISDIR(s_buf.st_mode))
	obj.setSubdirectory(true);
      obj.setSize(s_buf.st_size);
      obj.setCreated(s_buf.st_ctime);
      obj.setModified(s_buf.st_mtime);
      obj.setAttached(s_buf.st_atime);
      results.push_back(obj);      
    }
    closedir(dir);
    return results;
  }
}