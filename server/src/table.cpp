#include "../headers/table.h"

Table::Table()
{

}

std::shared_ptr<Photo> Table::addPhoto(const string nom, const string path_file, const int latitude, const int longitude) {
	std::cout<<"Photo not created no problem"<<std::endl;
	std::shared_ptr<Photo> newPhoto = std::make_shared<Photo>(nom, path_file, latitude, longitude);
	std::cout<<"Photo created no problem"<<std::endl;
	multimedias[newPhoto->getNom()] = newPhoto;
	return newPhoto;
}

std::shared_ptr<Video> Table::addVideo(const std::string name, const std::string path_name, const int duree) {
	std::shared_ptr<Video> newVideo = std::make_shared<Video>(name, path_name, duree);
	multimedias[newVideo->getNom()] = newVideo;
	return newVideo;
}

std::shared_ptr<Film> Table::addFilm(const std::string name, const std::string path_name, const int duree){
	std::shared_ptr<Film> newFilm = std::make_shared<Film>(name, path_name, duree);
	multimedias[newFilm->getNom()] = newFilm;
	return newFilm;
}

void Table::addFilm(std::shared_ptr<Film> film){
	multimedias[film->getNom()] = film;
}

void Table::addPhoto(std::shared_ptr<Photo> photo) {
	multimedias[photo->getNom()] = photo;
}

void Table::addVideo(std::shared_ptr<Video> video) {
	multimedias[video->getNom()] = video;
}

std::shared_ptr<Groupe> Table::addGroup(std::string name) {
	std::shared_ptr<Groupe> newGroupe = std::make_shared<Groupe>(name);
	groupes[name] = newGroupe;
	return newGroupe;
}

void Table::addGroup(std::shared_ptr<Groupe> groupe) {
	groupes[groupe->getName()] = groupe;
}

std::shared_ptr<Groupe> Table::findGroupe(std::string name, ostream &flux)const{
	auto it = groupes.find(name);
	if(it!=groupes.end()){
		it->second->displayValues(flux);
		return it->second;
	}
	std::cout<<"Nothing matchs the research"<<std::endl;
	return nullptr;
}
std::shared_ptr<Multimedia> Table::findMultimedia(std::string name, ostream &flux)const{
	auto it = multimedias.find(name);
	if(it!=multimedias.end()){
		it->second->displayValues(flux);
		return it->second;
	}
	std::cout<<"Nothing matchs the research"<<std::endl;
	return nullptr;
}

void Table::play(std::string name){
	auto it = multimedias.find(name);
	if(it!=multimedias.end()){
		it->second->play();
	}
	std::cout<<"Nothing matchs the research"<<std::endl;
}

