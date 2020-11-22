#ifndef FILM_H
#define FILM_H

#include "video.h"
/**
* \brief A Video with an extra property called chapitre.
* 
* Chapitre is the list of chapters of a Film. \n
* The index of the list means the number of the chapter and the value chapitre[index] is the length of the chepter index
*/
class Film : public Video {
public:
	Film() : Video() { chapitre = NULL; nbr_chapitre = 0; };
	Film(const std::string name, const std::string path_name, const int duree) : Video(name, path_name, duree) { chapitre = NULL; nbr_chapitre = 0; };
	/**
	* \brief redefines the operator = to make a deep copy.
	*/
	Film& operator=(const Film& film);
	const int* getChapitre() { return (chapitre); };
	const int getNbrChapitre() { return(nbr_chapitre); }
	void setChapitre(int* const liste, int size);
	void displayValues(std::ostream& flux) override;
	
	/**
	* \brief clean the chapter list.
	*/
	~Film();

private:
	int* chapitre;
	int nbr_chapitre;

};

#endif 
