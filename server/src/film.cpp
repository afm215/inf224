#include "../headers/film.h"

Film& Film::operator=(const Film& film) {
	
	Video::operator=(film);
	nbr_chapitre = film.nbr_chapitre;
	delete chapitre;
	chapitre = new int[nbr_chapitre];
	for (int i = 0; i < nbr_chapitre; i++) {
		chapitre[i] = film.chapitre[i];
	}
	return *this;
}

void Film::displayValues(std::ostream& flux) {
	/**
	* Display 
	*/
	Video::displayValues(flux);
	for (int i = 0; i < nbr_chapitre; i++) {
		flux << "chapitre " << i << " " << chapitre[i] << " minutes" << std::endl;
	}
}

void Film::setChapitre(int* const liste, int size) {
	nbr_chapitre = size;
	delete[] chapitre;
	chapitre = new int [size];
	for (int i = 0; i < size; i++) {
		chapitre[i] = liste[i];
	}
}

Film::~Film() {
	
	delete []chapitre;
	/**
	* standard output to test the efficiency of the smart pointer(and it is efficient indeed)
	*/
	std::cout << "Film terminated" << std::endl;
}