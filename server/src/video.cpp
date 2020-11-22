#include "../headers/video.h"

Video::Video() : Multimedia(){
    /**
    * create an auto-generated Video with: \
    * name is video \n
    * duree is 0 \n
    */
    nom = "video";
    duree = 0;
}
Video::Video(const std::string name, const std::string path_name, const int duree):Multimedia(name,path_name){
    /**
    * Pathname is the path toward the file \n
    * name is the name of the video \n
    * duree is the length if the video`\n 
    */
    this->duree = duree;
}

void Video::setDuree(int duree) {
    this->duree = duree;
}

int Video::getDuree() {
    return duree;
}

void Video::displayValues(ostream& flux) {
    Multimedia::displayValues(flux);
    flux << "duree: " << duree << std::endl;
}

void Video::play() {
    /**
    * \brief Implement the play function of the Multimedia class
    * 
    * Check wether the os is windows or unix
    */
    #if defined(_WIN32) || defined(_WIN64)
        system(path_file.c_str());
    #endif
    #if defined(__unix__) || defined(__unix)
        string commande = "mpv " +  path_file + " &";
        system(commande.c_str());
    #endif
}