// ActorN.h

// ActorN struct represents a movie actor with the following attributes:
// - id: unique identifier for the actor
// - name: actor's first name
// - surname: actor's last name
// - day, month, year: actor's date of birth
// - films: number of films the actor has appeared in
//
// The struct also contains two ArrayLists for storing identifiers of films the actor has acted in and
// identifiers of films the actor has directed.

#pragma once
#include "ArrayList.h"
#include <string>

struct ActorN {
private:
    // id: unique identifier for the actor
    int id;

    // name: actor's first name
    std::string name;

    // surname: actor's last name
    std::string surname;

    // day, month, year: actor's date of birth
    int day, month, year;

    // films: number of films the actor has appeared in
    int films;

public:
    // Constructor for ActorN struct
    //
    // Parameters:
    // - id: unique identifier for the actor
    // - name: actor's first name
    // - surname: actor's last name
    // - day: actor's date of birth day
    // - month: actor's date of birth month
    // - year: actor's date of birth year
    // - films: number of films the actor has appeared in (default is 0)
    ActorN(int id, const std::string& name, const std::string& surname, int day, int month, int year, int films = 0)
        : id(id), name(name), surname(surname), day(day), month(month), year(year), films(films) {}

    // Destructor for ActorN struct
    //
    // Clears the id_Actors and id_Directors ArrayLists
    ~ActorN() {
        id_Actors.clear();
        id_Directors.clear();
    }

    // plus function increments the number of films the actor has appeared in by the given number
    //
    // Parameters:
    // - num: number of films to add to the actor's film count
    void plus(int num) {
        films += num;
    }

    // getId function returns the actor's unique identifier
    //
    // Returns:
    // - id: unique identifier for the actor
    int getId() const { return id; }

    // getName function returns the actor's first name
    //
    // Returns:
    // - name: actor's first name
    const std::string& getName() const { return name; }

    // getSurname function returns the actor's last name
    //
    // Returns:
    // - surname: actor's last name
    const std::string& getSurname() const { return surname; }

    // getDay function returns the actor's date of birth day
    //
    // Returns:
    // - day: actor's date of birth day
    int getDay() const { return day; }

    // getMonth function returns the actor's date of birth month
    //
    // Returns:
    // - month: actor's date of birth month
    int getMonth() const { return month; }

    // getYear function returns the actor's date of birth year
    //
    // Returns:
    // - year: actor's date of birth year
    int getYear() const { return year; }

    // getFilms function returns the number of films the actor has appeared in
    //
    // Returns:
    // - films: number of films the actor has appeared in
    int getFilms() const { return films; }

    // toString function returns a string representation of the ActorN struct
    //
    // Returns:
    // - a string representation of the ActorN struct
    std::string toString() const {
        return "ActorN [id=" + std::to_string(id) + ", name=" + name + ", surname=" + surname +
               ", day=" + std::to_string(day) + ", month=" + std::to_string(month) +
               ", year=" + std::to_string(year) + ", films=" + std::to_string(films) + "]";
    }

    // id_Actors ArrayList stores the identifiers of films the actor has acted in
    ArrayList<int> id_Actors;

    // id_Directors ArrayList stores the identifiers of films the actor has directed
    ArrayList<int> id_Directors;
};

// DirectorN.h

// DirectorN struct represents a movie director with the following attributes:
// - id: unique identifier for the director
// - name: director's first name
// - surname: director's last name
// - day, month, year: director's date of birth
// - films: number of films the director has directed
//
// The struct also contains an ArrayList for storing identifiers of films the director has directed.

struct DirectorN {
private:
    // id: unique identifier for the director
    int id;

    // name: director's first name
    std::string name;

    // surname: director's last name
    std::string surname;

    // day, month, year: director's date of birth
    int day, month, year;

    // films: number of films the director has directed
    int films;

public:
    // Constructor for DirectorN struct
    //
    // Parameters:
    // - id: unique identifier for the director
    // - name: director's first name
    // - surname: director's last name
    // - day: director's date of birth day
    // - month: director's date of birth month
    // - year: director's date of birth year
    // - films: number of films the director has directed (default is 0)
    DirectorN(int id, const std::string& name, const std::string& surname, int day, int month, int year, int films = 0)
        : id(id), name(name), surname(surname), day(day), month(month), year(year), films(films) {}

    // Destructor for DirectorN struct
    //
    // Clears the id_Directors ArrayList
    ~DirectorN() {
        id_Directors.clear();
    }

    // plus function increments the number of films the director has directed by the given number
    //
    // Parameters:
    // - num: number of films to add to the director's film count
    void plus(int num) {
        films += num;
    }

    // getId function returns the director's unique identifier
    //
    // Returns:
    // - id: unique identifier for the director
    int getId() const { return id; }

    // getName function returns the director's first name
    //
    // Returns:
    // - name: director's first name
    const std::string& getName() const { return name; }

    // getSurname function returns the director's last name
    //
    // Returns:
    // - surname: director's last name
    const std::string& getSurname() const { return surname; }

    // getDay function returns the director's date of birth day
    //
    // Returns:
    // - day: director's date of birth day
    int getDay() const { return day; }

    // getMonth function returns the director's date of birth month
    //
    // Returns:
    // - month: director's date of birth month
    int getMonth() const { return month; }

    // getYear function returns the director's date of birth year
    //
    // Returns:
    // - year: director's date of birth year
    int getYear() const { return year; }

    // getFilms function returns the number of films the director has directed
    //
    // Returns:
    // - films: number of films the director has directed
    int getFilms() const { return films; }

    // toString function returns a string representation of the DirectorN struct
    //
    // Returns:
    // - a string representation of the DirectorN struct
    std::string toString() const {
        return "DirectorN [id=" + std::to_string(id) + ", name=" + name + ", surname=" + surname +
               ", day=" + std::to_string(day) + ", month=" + std::to_string(month) +
               ", year=" + std::to_string(year) + ", films=" + std::to_string(films) + "]";
    }

    // id_Directors ArrayList stores the identifiers of films the director has directed
    ArrayList<int> id_Directors;
};

// FilmN.h

// FilmN struct represents a movie with the following attributes:
// - id: unique identifier for the film
// - name: film name
// - year: film release year
// - budget: film budget

struct FilmN {
private:
    // id: unique identifier for the film
    int id;

    // name: film name
    std::string name;

    // year: film release year
    int year;

    // budget: film budget
    int budget;

public:
    // Constructor for FilmN struct
    //
    // Parameters:
    // - id: unique identifier for the film
    // - name: film name
    // - year: film release year
    // - budget: film budget
    FilmN(int id, const std::string& name, int year, int budget)
        : id(id), name(name), year(year), budget(budget) {}

    // getId function returns the film's unique identifier
    //
    // Returns:
    // - id: unique identifier for the film
    int getId() const { return id; }

    // getName function returns the film's name
    //
    // Returns:
    // - name: film name
    const std::string& getName() const { return name; }

    // getYear function returns the film's release year
    //
    // Returns:
    // - year: film release year
    int getYear() const { return year; }

    // getBudget function returns the film's budget
    //
    // Returns:
    // - budget: film budget
    int getBudget() const { return budget; }

    // toString function returns a string representation of the FilmN struct
    //
    // Returns:
    // - a string representation of the FilmN struct
    std::string toString() const {
        return "FilmN [id=" + std::to_string(id) + ", name=" + name + ", year=" + std::to_string(year) +
               ", budget=" + std::to_string(budget) + "]";
    }
};

// Connections.h

// Connections struct represents the connections between films, actors, and directors with the following attributes:
// - id_Film: unique identifier for the film
// - id_Actors: identifiers of actors in the film
// - id_Directors: identifiers of directors of the film

struct Connections {
private:
    // id_Film: unique identifier for the film
    int id_Film;

    // id_Actors: identifiers of actors in the film
    ArrayList<int> id_Actors;

    // id_Directors: identifiers of directors of the film
    ArrayList<int> id_Directors;

public:
    // Constructor for Connections struct
    //
    // Parameters:
    // - id_Film: unique identifier for the film
    Connections(int id_Film) : id_Film(id_Film) {}

    // getIdFilm function returns the film's unique identifier
    //
    // Returns:
    // - id_Film: unique identifier for the film
    int getIdFilm() const { return id_Film; }

    // toString function returns a string representation of the Connections struct
    //
    // Returns:
    // - a string representation of the Connections struct
    std::string toString() const {
        return "Connections [id_Film=" + std::to_string(id_Film) + ", id_Actors=" + id
