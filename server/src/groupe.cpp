#include "../headers/groupe.h"

void Groupe::displayValues(std::ostream& flux) {
	/**
	* Call the display function of all the Multimedia objects in the group
	*/
std::cout<<"dsplay group launched"<<std::endl;
	for (auto i : *this) {
		flux <<'\n';
		i->displayValues(flux);
		
	}
}