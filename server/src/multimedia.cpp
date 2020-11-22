#include "../headers/multimedia.h"

Multimedia::Multimedia(){
    nom = "default";
    path_file = "";
}

Multimedia::Multimedia(const string nom, const string path_file){
    /**
     * \brief detailed constructor where nom is name of the object
     *        path_file is the path to the targeted file
     *  
     */
    this->nom = nom;
    this->path_file = path_file;
}

     void Multimedia::displayValues(ostream & flux){
    /**
    * Display the name of the Multimedia object and the path of the file associated.
    */
    flux<<"nom: "<<nom<<std::endl;
    flux<<"path file: "<< path_file<<std::endl;
}

void Multimedia::setNom(string nom) {
    this->nom = nom;
}

void Multimedia::setPathFile(string path_name) {
    this->path_file = path_name;
}

string Multimedia::getNom() {
    return nom;
}

string Multimedia::getPathFile() {
    return path_file;
}
