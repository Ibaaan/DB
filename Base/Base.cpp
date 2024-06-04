#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdexcept>

// Base.h is not provided, so I am assuming the necessary declarations are made here

void Base::ReadDataFileActor(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    int n;
    file >> n;
    if (file.fail()) {
        throw std::runtime_error("Failed to read data from file: " + filename);
    }

    for (int i = 0; i < n; i++) {
        ActorN actor;
        file >> actor.id >> actor.name >> actor.surname >> actor.day >> actor.month >> actor.year >> actor.films;
        if (file.fail()) {
            throw std::runtime_error("Failed to read data from file: " + filename);
        }
        actorArr.push_back(actor);
        last_id_actor = actor.id;
    }
}

void Base::ReadDataFileDirector(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    int n;
    file >> n;
    if (file.fail()) {
        throw std::runtime_error("Failed to read data from file: " + filename);
    }

    for (int i = 0; i < n; i++) {
        DirectorN actor;
        file >> actor.id >> actor.name >> actor.surname >> actor.day >> actor.month >> actor.year >> actor.films;
        if (file.fail()) {
            throw std::runtime_error("Failed to read data from file: " + filename);
        }
        directorArr.push_back(actor);
        last_id_director = actor.id;
    }
}

void Base::ReadDataFileFilm(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    int n;
    file >> n;
    if (file.fail()) {
        throw std::runtime_error("Failed to read data from file: " + filename);
    }

    for (int i = 0; i < n; i++) {
        FilmN actor;
        file >> actor.id >> actor.name >> actor.year >> actor.budget;
        if (file.fail()) {
            throw std::runtime_error("Failed to read data from file: " + filename);
        }
        filmArr.push_back(actor);
        last_id_film = actor.id;
    }
}

void Base::ReadDataFileConnections(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    int n;
    file >> n;
    if (file.fail()) {
        throw std::runtime_error("Failed to read data from file: " + filename);
    }

    for (int i = 0; i < n; i++) {
        Connections connections;
        int id_Film;
        std::string id_acts, id_dirs;
        file >> id_Film >> id_acts >> id_dirs;
        if (file.fail()) {
            throw std::runtime_error("Failed to read data from file: " + filename);
        }

        std::istringstream iss(id_acts);
        std::vector<int> ids{(std::istream_iterator<int>(iss)), std::istream_iterator<int>()};
        connections.id_Actors = ids;

        iss.clear();
        iss.str(id_dirs);
        ids.clear();
        std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(ids));
        connections.id_Directors = ids;

        connnectionsArr.push_back(connections);
    }
}

// ... (other function definitions)

Base::Base()
{
    try {
        ReadDataFileActor("actor.txt");
        ReadDataFileDirector("director.txt");
        ReadDataFileFilm("film.txt");
        ReadDataFileConnections("connections.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

Base::~Base()
{
    // No need to explicitly close the files or destruct ArrayLists, as this is handled by the standard library
}

// ... (other function definitions)
