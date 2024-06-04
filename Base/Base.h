#pragma once // directive to prevent multiple inclusions of the same header file
#include <array> // for using fixed-size collections
#include <fstream> // for file input/output operations
#include <iostream> // for input/output operations
#include <string> // for string manipulation and storage
#include <vector> // for dynamic-size collections

// Class definitions
class FilmN {}; // FilmN class declaration
class ActorN {}; // ActorN class declaration
class DirectorN {}; // DirectorN class declaration
class Connections {}; // Connections class declaration

class Base { // Base class declaration
private:
    // Private member variables
    std::vector<FilmN> filmArr; // vector to store FilmN objects
    std::vector<ActorN> actorArr; // vector to store ActorN objects
    std::vector<DirectorN> directorArr; // vector to store DirectorN objects
    std::vector<Connections> connectionsArr; // vector to store Connections objects

    const std::string ACTOR_FILE = "Actor_File.txt"; // constant string for actor file name
    const std::string DIRECTOR_FILE = "Director_File.txt"; // constant string for director file name
    const std::string FILM_FILE = "Film_File.txt"; // constant string for film file name
    const std::string CONNECTIONS_FILE = "Connections_File.txt"; // constant string for connections file name

    int last_id_actor = 0, last_id_director = 0, last_id_film = 0; // integer variables to store last IDs for actors, directors, and films

    // Private member functions
    int findActor(const std::string& name, const std::string& surname, const char& spec); // function to find an actor
    int findDirector(const std::string& name, const std::string& surname, const char& spec); // function to find a director
    int findFilm(const std::string& name, const char& spec); // function to find a film
    int findConns(int film_id); // function to find connections
    int findFilmA(int id); // function to find a film by ID
    int findActorA(int id); // function to find an actor by ID
    int findDirectorA(int id); // function to find a director by ID

    void deleteActor(const std::string& name, const std::string& surname); // function to delete an actor
    void deleteDirector(const std::string& name, const std::string& surname); // function to delete a director
    void deleteFilm(const std::string& name); // function to delete a film

    void addActor(const std::string& name, const std::string& surname); // function to add an actor
    void addDirector(const std::string& name, const std::string& surname); // function to add a director
    void addFilm(const std::string& name); // function to add a film
    void addConns(int film_id); // function to add connections

    void clear(); // function to clear all data
    void saveChanges(); // function to save changes to files
    void loadData(); // function to load data from files
    void printData(); // function to print data

    std::string getInput(const std::string& message); // function to get input from user

public:
    Base(); // constructor
    ~Base(); // destructor

    void interface(); // function to start the user interface
};
