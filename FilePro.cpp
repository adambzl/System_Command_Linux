#include "FilePro.h"

void FilePro::setCreated(time_t created){
    struct tm tm = *localtime(&created);
    char tChars[50] =  {0};
    std::strftime(tChars, sizeof tChars, "%Y-%m-%d %H:%M:%S", &tm);
    this->created = std::string(tChars);
    return;
}
 
void FilePro::setModified(time_t modified){
    struct tm tm = *localtime(&modified);
    char tChars[50] = {0};
    std::strftime(tChars, sizeof tChars, "%Y-%m-%d %H:%M:%S", &tm);
    this->modified = std::string(tChars);
    return;
}
 
void FilePro::setAttached(time_t attached){
    struct tm tm = *localtime(&attached);
    char tChars[50] = {0};
    std::strftime(tChars, sizeof tChars, "%Y-%m-%d %H:%M:%S", &tm);
    this->attached = std::string(tChars);
    return;
}