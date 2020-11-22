#include "../headers/photo.h"

Photo::Photo() : Multimedia() {
	nom = "photo";
}

Photo::Photo(const string nom, const string path_file, const int latitude, const int longitude) : Multimedia(nom, path_file){
	this->latitude = latitude;
	this->longitude = longitude;
}

void Photo::displayValues(ostream& flux) {
	Multimedia::displayValues(flux);
	flux << "latitude: " << latitude << std::endl;
	flux << "longitude: " << longitude << std::endl;
}

void Photo::setLatitude(int latitude) {
	this->latitude = latitude;
}

void Photo::setLongitude(int longitude) {
	this->longitude = longitude;
}

int Photo::getLatitude() {
	return latitude;
}

int Photo::getLongitude() {
	return longitude;
}

void Photo::play() {
	/**
   * \brief Implement the play function of the Multimedia class
   *
   * Check wether the os is windows or unix
   */
	#if defined(_WIN32) || defined(_WIN64)
		system(path_file.c_str());
	#endif
	#if defined(__unix__) || defined(__unix)
		string commande = "gimp " + path_file + " &";
		system(commande.c_str());
	#endif
}

Photo::~Photo() {
	/**
	* \brief destructor implemented to test the efficiency of the smart pointer(and it is efficient indeed)
	*/
	std::cout << "Photo terminated" << std::endl;
}

