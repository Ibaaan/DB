#pragma once
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FilmN {};
class ActorN {};
class DirectorN {};
class Connections {};

class Base {
private:
    std::vector<FilmN> filmArr;
    std::vector<ActorN> actorArr;
    std::vector<DirectorN> directorArr;
    std::vector<Connections> connectionsArr;

    const std::string ACTOR_FILE = "Actor_File.txt";
    const std::string DIRECTOR_FILE = "Director_File.txt";
    const std::string FILM_FILE = "Film_File.txt";
    const std::string CONNECTIONS_FILE = "Connections_File.txt";

    int last_id_actor = 0, last_id_director = 0, last_id_film = 0;

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

    void addActor(const std::string& name, const std::string& surname);
    void addDirector(const std::string& name, const std::string& surname);
    void addFilm(const std::string& name);
    void addConns(int film_id);

    void clear();
    void saveChanges();
    void loadData();
    void printData();

    std::string getInput(const std::string& message);

public:
    Base();
    ~Base();

    void interface();
};
