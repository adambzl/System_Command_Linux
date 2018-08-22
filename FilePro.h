#include "standard.h"

/*封装了易读形式文件属性的类
 * for linux, 20180720
*/

class FilePro{
  private:
    std::string filename;
    std::string created;
    std::string modified;
    std::string attached;
    off_t size;
    //bool readOnly;
    //bool hidden;
    bool subdirectory;
  public:
    FilePro():subdirectory(false), size(0) {}
    //void setReadOnly(bool readOnly) {
    //  this->readOnly = readOnly;
    //}
    //void setHidden(bool hidden){
    //  this->hidden = hidden;
    //}
    void setSubdirectory(bool subdirectory){
      this->subdirectory = subdirectory;
    }
    void setSize(off_t size){
      this->size = size;
    }
    void setFilename(std::string filename){
      this->filename = filename;
    }
    void setCreated(time_t created);
    void setModified(time_t modified);
    void setAttached(time_t attached);
    //bool isReadOnly(){return readOnly;}
    //bool isHidden(){return hidden;}
    bool isSubdirectory(){return subdirectory;}
    off_t getSize(){return size;}
    std::string getFilename(){return filename;}
    std::string getCreated(){return created;}
    std::string getModified(){return modified;}
    std::string getAttached(){return attached;}
};