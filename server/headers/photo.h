#ifndef PHOTO_H
#define PHOTO_H
#ifndef _OS
#define _OS
#endif // !_OS

#include "multimedia.h"

/**
* \brief To understand what a Photo is, it is highly recommanded to read Larousse or equivalent. 
* 
* Look at the constructor for utilisation indications
*/
class Photo : public Multimedia {
	public:
		Photo();
		Photo(const string nom, const string path_file, const int latitude, const int longitude);
		void displayValues(ostream &flux) override;
		void setLatitude(int latitude);
		void setLongitude(int longitude);
		int getLongitude();
		int getLatitude();
		void play() override;
		~Photo();
	private:
		int latitude;
		int longitude;


};
#endif // !PHOTO_H

