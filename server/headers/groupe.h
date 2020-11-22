#ifndef MALISTE_H
#define MALISTE_H

#include <iostream>
#include <list>
#include "multimedia.h"
#include <memory>

/**
* \brief A group of Multimedia objects
* has one attribute name which is the name of the list
*/
class Groupe : public std::list<std::shared_ptr<Multimedia>> {
public:
	/**
	* \brief default constructor which set name with the default value Toto.
	*/
	Groupe() : std::list<std::shared_ptr<Multimedia>>() { name = "Toto"; };
	
	/**
	* \brief Defined name attribute with name parameter
	*/
	Groupe(string name) : Groupe() { this->name = name;  };

	string const& getName() const { return name; };
	void setName(string name) { this->name = name; };
	void displayValues(std::ostream& flux);
private:
	string name;
};
#endif // !MALISTE_H
