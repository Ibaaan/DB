#pragma once
# include "ArrayList.h"
#include <string>

struct ActorN {
	int id;
	std::string name, surname;
	// date of birth
	int day, month, year;
	// the number of films the actor has played
	int films;
	void plus() {
		films++;
		return;
	}
};

struct DirectorN {
	int id;
	std::string name, surname;
	// date of birth
	int day, month, year;
	// the number of films the director has directed
	int films;
	void plus() {
		films++;
		return;
	}
};

struct FilmN {
	int id;
	std::string name;
	// the release date of the film
	int year;
	// budget of the film
	int budget;
	
};

struct Connections {
	int id_Film;
	// id of actors and directors who participated in the creation of the film
	ArrayList<int> id_Actors;
	ArrayList<int> id_Directors;
};