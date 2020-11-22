#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
/**
  * \brief To understand what a Video is, it is highly recommanded to read Larousse or equivalent. 
  * 
  * Look at the constructor for utilisation indications
  */
class Video : public Multimedia
{
    public:
        Video();
        Video(const std::string name, const std::string path_name, const int duree);
        void setDuree(int duree);
        int getDuree();
        void displayValues(ostream& flux);
        void play() override;
    private:
        int duree;
};

#endif