#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <map>
#include<memory>
#include "multimedia.h"
#include "./groupe.h"
#include "video.h"
#include "photo.h"
#include "film.h"

/**
* \brief Class whith two instance : an associative map of Multimedia objects and one of Groupe objects
*
*To prevent an object to be created outside the table there are two possibilities:
*either adding a pointer toward a Table in the Multimedia class and check if it is null or not 
*or setting the constructors of the Video, Photo, Film  as protected
*/
class Table
{
public:
	Table();
	std::shared_ptr<Photo> addPhoto(const string nom, const string path_file, const int latitude, const int longitude);
	void addPhoto(std::shared_ptr<Photo> photo);

	std::shared_ptr<Video> addVideo(const std::string name, const std::string path_name, const int duree);
	void addVideo(std::shared_ptr<Video> video);

	std::shared_ptr<Film> addFilm(const std::string name, const std::string path_name, const int duree);
	void addFilm(std::shared_ptr<Film> film);
	
	std::shared_ptr<Groupe> addGroup(const std::string name);
	void addGroup(std::shared_ptr<Groupe> groupe);


	
	/**
	 * \brief research a Group and display its attribute before returning it 
	 */
	std::shared_ptr<Groupe> findGroupe(std::string name, std::ostream &flux) const;
	/**
	 * \brief research a Multimedia and display its attribute before returning it 
	 */
	std::shared_ptr<Multimedia> findMultimedia(std::string name, std::ostream &flux) const;
	
	/**
	 * \brief Play multimdeia file
	 */
	void play(std::string name);


private:
	std::map<std::string, std::shared_ptr <Multimedia>> multimedias;
	std::map<std::string, std::shared_ptr<Groupe>> groupes;

};
#endif // !TABLE_H
