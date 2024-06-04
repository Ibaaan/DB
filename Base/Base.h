#pragma once
#include "Data.h"
#include <fstream>
#include <sstream>

class Base {
private:
	ArrayList<FilmN> filmArr;
	ArrayList<ActorN> actorArr;
	ArrayList<DirectorN> directorArr;
	ArrayList<Connections> connnectionsArr;

	const std::string ACTOR_FILE = "Actor_File.txt";
	const std::string DIRECTOR_FILE = "Director_File.txt";
	const std::string FILM_FILE = "Film_File.txt";
	const std::string CONNSECTIONS_FILE = "Connections_File.txt";
	ArrayList<int> NOacts, NOdirs, NOfilms;
	ArrayList<Connections> NOcons;
	int last_id_actor=0, last_id_director= 0, last_id_film=0;

	void ReadDataFileActor(const std::string& filename);
	void ReadDataFileDirector(const std::string& filename);
	void ReadDataFileFilm(const std::string& filename);
	void ReadDataFileConnections(const std::string& filename);

	void writeDataFileActor(const std::string& filename);
	void writeDataFileDirector(const std::string& filename);
	void writeDataFileFilm(const std::string& filename);
	void writeDataFileConnections(const std::string& filename);

	int findActor(const std::string& name, const std::string& surname, const char& spec);
	int findDirector(const std::string& name, const std::string& surname, const char& spec);
	int findFilm(const std::string& name, const char& spec);
	int findConns(int film_id);
	int findFilmA(int id);
	int findActorA(int id);
	int findDirectorA(int id);

	void deleteActor(const std::string& name, const std::string& surname);
	void deleteDirector(const std::string& name, const std::string& surname);
	void deleteFilm(const std::string& name);

	void printActorArr();
	void printDirectorArr();
	void printFilmArr();
	void printConnsArr();
	
	void printActor( ArrayList<int>& no, ArrayList<int>& noF);
	void printDirector( ArrayList<int>& no, ArrayList<int>& noF);
	void printFilm(ArrayList<int>& noA, ArrayList<int>& noD, ArrayList<int>& noF);

	void addActor(const std::string& name, const std::string& surname);
	void addDirector(const std::string& name, const std::string& surname);
	void addFilm(const std::string& name);
	void addConns(int film_id);

	void menu1();
	void menu2();
	void menu3();
	void menu4();
	void menu5();
public:
	Base();
	~Base();

	void interface();
};