#pragma once
#include "ArrayList.h"
#include <string>

struct ActorN {
private:
    int id;
    std::string name, surname;
    int day, month, year;
    int films;

public:
    ActorN(int id, const std::string& name, const std::string& surname, int day, int month, int year, int films = 0)
        : id(id), name(name), surname(surname), day(day), month(month), year(year), films(films) {}

    ~ActorN() {
        id_Actors.clear();
        id_Directors.clear();
    }

    void plus(int num) {
        films += num;
    }

    int getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getSurname() const { return surname; }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    int getFilms() const { return films; }

    std::string toString() const {
        return "ActorN [id=" + std::to_string(id) + ", name=" + name + ", surname=" + surname +
               ", day=" + std::to_string(day) + ", month=" + std::to_string(month) +
               ", year=" + std::to_string(year) + ", films=" + std::to_string(films) + "]";
    }

    ArrayList<int> id_Actors;
    ArrayList<int> id_Directors;
};

struct DirectorN {
private:
    int id;
    std::string name, surname;
    int day, month, year;
    int films;

public:
    DirectorN(int id, const std::string& name, const std::string& surname, int day, int month, int year, int films = 0)
        : id(id), name(name), surname(surname), day(day), month(month), year(year), films(films) {}

    ~DirectorN() {
        id_Directors.clear();
    }

    void plus(int num) {
        films += num;
    }

    int getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getSurname() const { return surname; }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    int getFilms() const { return films; }

    std::string toString() const {
        return "DirectorN [id=" + std::to_string(id) + ", name=" + name + ", surname=" + surname +
               ", day=" + std::to_string(day) + ", month=" + std::to_string(month) +
               ", year=" + std::to_string(year) + ", films=" + std::to_string(films) + "]";
    }

    ArrayList<int> id_Directors;
};

struct FilmN {
private:
    int id;
    std::string name;
    int year;
    int budget;

public:
    FilmN(int id, const std::string& name, int year, int budget)
        : id(id), name(name), year(year), budget(budget) {}

    int getId() const { return id; }
    const std::string& getName() const { return name; }
    int getYear() const { return year; }
    int getBudget() const { return budget; }

    std::string toString() const {
        return "FilmN [id=" + std::to_string(id) + ", name=" + name + ", year=" + std::to_string(year) +
               ", budget=" + std::to_string(budget) + "]";
    }
};

struct Connections {
private:
    int id_Film;
    ArrayList<int> id_Actors;
    ArrayList<int> id_Directors;

public:
    Connections(int id_Film) : id_Film(id_Film) {}

    int getIdFilm() const { return id_Film; }

    std::string toString() const {
        return "Connections [id_Film=" + std::to_string(id_Film) + ", id_Actors=" + id_Actors.toString() +
               ", id_Directors=" + id_Directors.toString() + "]";
    }
};
