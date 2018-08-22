#include "DirList.h"

int main(){
  std::string path;
  char inputPath[100];
  while(1){
    std::cout<<"输入文件路径(退出:exit):";
    std::cin.getline(inputPath, 100);
    path = std::string(inputPath);
    if(path == "exit")
      break;
    else{
      std::vector<FilePro> results = DirList::traverse(path);
      std::vector<FilePro>::iterator it;
      if(results.empty())
        std::cout<<"非法路径"<<std::endl;
      else{
        std::cout<<"文件名\t是否为目录\t创建时间\t大小\t(部分属性未列出)<<std::endl;
        it = results.begin();
        while(it != results.end()){
          std::cout<<(*it).getFilename()<<"\t"<<(*it).isSubdirectory()<<"\t"<<(*it).getCreated()<<"\t"<<(*it).getSize()<<std::endl;
          it++;
        }
      }
    }
  }
  return 0;
}
