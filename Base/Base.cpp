#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdexcept>

// Base.h is not provided, so I am assuming the necessary declarations are made here

// ReadDataFileActor reads data from an actor data file and stores it in the actorArr vector
void Base::ReadDataFileActor(const std::string& filename)
{
    std::ifstream file(filename); // Open the input file
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename); // Throw an error if the file cannot be opened
    }

    int n;
    file >> n; // Read the number of actors in the file
    if (file.fail()) {
        throw std::runtime_error("Failed to read data from file: " + filename); // Throw an error if there's a problem reading the data
    }

    for (int i = 0; i < n; i++) {
        ActorN actor; // Create a new ActorN object
        file >> actor.id >> actor.name >> actor.surname >> actor.day >> actor.month >> actor.year >> actor.films;
        if (file.fail()) {
            throw std::runtime_error("Failed to read data from file: " + filename); // Throw an error if there's a problem reading the data
        }
        actorArr.push_back(actor); // Add the actor to the actorArr vector
        last_id_actor = actor.id; // Update the last_id_actor variable
    }
}

// ReadDataFileDirector reads data from a director data file and stores it in the directorArr vector
void Base::ReadDataFileDirector(const std::string& filename)
{
    std::ifstream file(filename); // Open the input file
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename); // Throw an error if the file cannot be opened
    }

    int n;
    file >> n; // Read the number of directors in the file
    if (file.fail()) {
        throw std::runtime_error("Failed to read data from file: " + filename); // Throw an error if there's a problem reading the data
    }

    for (int i = 0; i < n; i++) {
        DirectorN actor; // Create a new DirectorN object
        file >> actor.id >> actor.name >> actor.surname >> actor.day >> actor.month >> actor.year >> actor.films;
        if (file.fail()) {
            throw std::runtime_error("Failed to read data from file: " + filename); // Throw an error if there's a problem reading the data
        }
        directorArr.push_back(actor); // Add the director to the directorArr vector
        last_id_director = actor.id; // Update the last_id_director variable
    }
}

// ReadDataFileFilm reads data from a film data file and stores it in the filmArr vector
void Base::ReadDataFileFilm(const std::string& filename)
{
    std::ifstream file(filename); // Open the input file
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename); // Throw an error if the file cannot be opened
    }

    int n;
    file >> n; // Read the number of films in the file
    if (file.fail()) {
        throw std::runtime_error("Failed to read data from file: " + filename); // Throw an error if there's a problem reading the data
    }

    for (int i = 0; i < n; i++) {
        FilmN actor; // Create a new FilmN object
        file >> actor.id >> actor.name >> actor.year >> actor.budget;
        if (file.fail()) {
            throw std::runtime_error("Failed to read data from file: " + filename); // Throw an error if there's a problem reading the data
        }
        filmArr.push_back(actor); // Add the film to the filmArr vector
        last_id_film = actor.id; // Update the last_id_film variable
    }
}

// ReadDataFileConnections reads data from a connections data file and stores it in the connnectionsArr vector
void Base::ReadDataFileConnections(const std::string& filename)
{
    std::ifstream file(filename); // Open the input file
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename); // Throw an error if the file cannot be opened
    }

    int n;
    file >> n; // Read the number of connections in the file
    if (file.fail()) {
        throw std::runtime_error("Failed to read data from file: " + filename); // Throw an error if there's a problem reading the data
    }

    for (int i = 0; i < n; i++) {
        Connections connections; // Create a new Connections object
        int id_Film;
        std::string id_acts, id_dirs;
        file >> id_Film >> id_acts >> id_dirs;
        if (file.fail()) {
            throw std::runtime_error("Failed to read data from file: " + filename); // Throw an error if there's a problem reading the data
        }

        std::istringstream iss(id_acts);
        std::vector<int> ids{(std::istream_iterator<int>(iss)), std::istream_iterator<int>()};
        connections.id_Actors = ids; // Parse the actor IDs and store them in the Connections object

        iss.clear();
        iss.str(id_dirs);
        ids.clear();
        std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(ids));
        connections.id_Directors = ids; // Parse the director IDs and store them in the Connections object

        connnectionsArr.push_back(connections); // Add the connections to the connnectionsArr vector
    }
}

// ... (other function definitions)

Base::Base()
{
    try {
        ReadDataFileActor("actor.txt"); // Read the actor data file
        ReadDataFileDirector("director.txt"); // Read the director data file
        ReadDataFileFilm("film.txt"); // Read the film data file
        ReadDataFileConnections("connections.txt"); // Read the connections data file
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl; // Print the error message if there's an exception
    }
}

Base::~Base()
{
    // No need to explicitly close the files or destruct ArrayLists, as this is handled by the standard library
}

// ... (other function definitions)

