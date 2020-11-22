#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <iostream>

using string=std::string;
using ostream = std::ostream;

/**
   * \brief Basic class used to implement all Multimedias Objects such as Photo, Video, Film....
   * This class is virtual!!!! (see play function)
   */
class Multimedia{
    public:
        Multimedia();
        Multimedia(const string nom, const string path_file);
        void setNom(string nom);
        void setPathFile(string path_name);
        virtual void displayValues(ostream & flux);
        string getNom();
        string getPathFile();
        virtual void play() = 0;
    
    protected:
        string nom;
        string path_file;

};


#endif // MACLASSE_H
