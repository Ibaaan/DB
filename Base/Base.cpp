#include "Base.h"

void Base::ReadDataFileActor(const std::string& filename)
{
	std::fstream f(filename);
	if (f.is_open()) {
		int n;
		f >> n;

		for (int i = 0; i < n; i++) {
			ActorN actor;
			f >> actor.id
				>> actor.name
				>> actor.surname
				>> actor.day
				>> actor.month
				>> actor.year
				>> actor.films;
			actorArr.push(actor);
			last_id_actor = actor.id;
		}
	}
	f.close();
}
void Base::ReadDataFileDirector(const std::string& filename)
{
	std::fstream f(filename);
	if (f.is_open()) {
		int n;
		f >> n;

		for (int i = 0; i < n; i++) {
			DirectorN actor;
			f >> actor.id
				>> actor.name
				>> actor.surname
				>> actor.day
				>> actor.month
				>> actor.year
				>> actor.films;
			directorArr.push(actor);
			last_id_director = actor.id;
		}
	}
	f.close();
}
void Base::ReadDataFileFilm(const std::string& filename)
{
	std::fstream f(filename);
	int n;
	f >> n;
	for (int i = 0; i < n; i++) {
		

		FilmN actor;
		f >> actor.id
			>> actor.name
			>> actor.year
			>> actor.budget;
		filmArr.push(actor);
		last_id_film = actor.id;
	}
	f.close();
}
void Base::ReadDataFileConnections(const std::string& filename)
{
	std::fstream f(filename);
	if(f.is_open()){
		int n;
		f >> n;
		
		const char SEP = ';';
		for (int i = 0; i < n; i++) {

			Connections connections;
			std::string id_acts, id_dirs;
			f >> connections.id_Film >> id_acts >> id_dirs;
			std::string tmp;
			if (id_acts != "-1") {
				std::istringstream ist(id_acts);
				
				while (getline(ist, tmp, SEP)) {
					connections.id_Actors.push(stoi(tmp));
					
				}
			}
			if (id_dirs != "-1") {
				std::istringstream ist(id_dirs);
				while (getline(ist, tmp, SEP)) {
					connections.id_Directors.push(stoi(tmp));
				}
			}
			connnectionsArr.push(connections);
		}
	}
	f.close();
}

void Base::writeDataFileActor(const std::string& filename)
{
	std::fstream f(filename);
	if (f.is_open()) {
		f << actorArr.getSize() << "\n";
		for (int i = 0; i < actorArr.getSize(); i++) {
			f << actorArr.get(i).id << " "
				<< actorArr.get(i).name << " "
				<< actorArr.get(i).surname << " "
				<< actorArr.get(i).day << " "
				<< actorArr.get(i).month << " "
				<< actorArr.get(i).year << " "
				<< actorArr.get(i).films << " "
				<< "\n";
		}
		actorArr.~ArrayList();
	}
	f.close();
}
void Base::writeDataFileDirector(const std::string& filename)
{
	std::fstream f(filename);

	if (f.is_open()) {
		f << directorArr.getSize() << "\n";
		for (int i = 0; i < directorArr.getSize(); i++) {
			f << directorArr.get(i).id << " "
				<< directorArr.get(i).name << " "
				<< directorArr.get(i).surname << " "
				<< directorArr.get(i).day << " "
				<< directorArr.get(i).month << " "
				<< directorArr.get(i).year << " "
				<< directorArr.get(i).films << " "
				<< "\n";
		}
	}
	f.close();
}
void Base::writeDataFileFilm(const std::string& filename)
{
	std::fstream f(filename);

	if (f.is_open()) {
		f << filmArr.getSize() << "\n";
		for (int i = 0; i < filmArr.getSize(); i++) {
			f << filmArr.get(i).id << " "
				<< filmArr.get(i).name << " "
				<< filmArr.get(i).year << " "
				<< filmArr.get(i).budget << " "
				<< "\n";
		}
		filmArr.~ArrayList();
	}
	f.close();
}
void Base::writeDataFileConnections(const std::string& filename)
{
	std::fstream f(filename);
	if (f.is_open()) {

		f << connnectionsArr.getSize() << "\n";
		for (int i = 0; i < connnectionsArr.getSize(); i++) {
			f << connnectionsArr.get(i).id_Film << " ";
			if(!connnectionsArr.get(i).id_Actors.isEmpty()){
				f << connnectionsArr.get(i).id_Actors.get(0);
				for (int j = 1; j < connnectionsArr.get(i).id_Actors.getSize(); j++) {
					f << ";" << connnectionsArr.get(i).id_Actors.get(j);
				}
			}
			else {
				f << "-1";
			}
			if (!connnectionsArr.get(i).id_Directors.isEmpty()) {
				f << " " << connnectionsArr.get(i).id_Directors.get(0);
				for (int j = 1; j < connnectionsArr.get(i).id_Directors.getSize(); j++) {
					f << ";" << connnectionsArr.get(i).id_Directors.get(j);
				}
				f << "\n";
			}
			else {
				f << " -1\n";
			}
		}
		
		connnectionsArr.~ArrayList();
	}
	f.close();
}

int Base::findActor(const std::string& name, const std::string& surname, const char& spec)
{
	for (int i = 0; i < actorArr.getSize(); i++) {
		if (name == actorArr.get(i).name && surname == actorArr.get(i).surname) {
			if(spec == 'a'){
				return actorArr.get(i).id;
			}
			if (spec == 'd') {
				return i;
			}
			
		}
	}
	return -1;
}
int Base::findDirector(const std::string& name, const std::string& surname, const char& spec)
{
	for (int i = 0; i < directorArr.getSize(); i++) {
		if (name == directorArr.get(i).name && surname == directorArr.get(i).surname) {
			if (spec == 'a') {
				return directorArr.get(i).id;
			}
			if (spec == 'd') {
				return i;
			}
		}
	}
	return -1;

}
int Base::findFilm(const std::string& name, const char& spec)
{
	for (int i = 0; i < filmArr.getSize(); i++) {
		if (name == filmArr.get(i).name) {
			if (spec == 'a') {
				return filmArr.get(i).id;
			}
			if (spec == 'd') {
				return i;
			}
		}
	}
	return -1;
}
int Base::findConns(int film_id)
{
	for (int i = 0; i < connnectionsArr.getSize(); i++) {
		if (film_id == connnectionsArr.get(i).id_Film) {
			return i;
		}
	}
	return -1;
}
int Base::findFilmA(int id)
{
	for (int i = 0; i < filmArr.getSize(); i++) {
		if (id == filmArr.get(i).id) {
			return i;
		}
	}
	return -1;
}
int Base::findActorA(int id)
{
	for (int i = 0; i < actorArr.getSize(); i++) {
		if (id == actorArr.get(i).id) {
			return i;
		}
	}
	return -1;
}
int Base::findDirectorA(int id)
{
	for (int i = 0; i < directorArr.getSize(); i++) {
		if (id == directorArr.get(i).id) {
			return i;
		}
	}
	return -1;
}

void Base::printActorArr()
{
	for (int i = 0; i < actorArr.getSize(); i++) {
		std::cout << "Name: " << actorArr.get(i).name << "\n"
			<< "Surname: " << actorArr.get(i).surname << "\n"
			<< "Date of birth: " << actorArr.get(i).day << "." << actorArr.get(i).month << "." << actorArr.get(i).year << "\n"
			<< "The number of films the actor has played: " << actorArr.get(i).films << "\nThe films he played in:";
		
		for (int j = 0; j < connnectionsArr.getSize(); j++) {
			if (connnectionsArr.get(j).id_Actors.contains(actorArr.get(i).id)) {
				int id = connnectionsArr.get(j).id_Film;
				std::cout << filmArr.get(findFilmA(id)).name << " ";
			}
		}
		std::cout << "\n";
		std::cout << "------------------------------------------------------\n";
	}
	return;
}
void Base::printDirectorArr()
{
	for (int i = 0; i < directorArr.getSize(); i++) {
		std::cout << "Name: " << directorArr.get(i).name << "\n"
			<< "Surname: " << directorArr.get(i).surname << "\n"
			<< "Date of birth: " << directorArr.get(i).day << "." << directorArr.get(i).month << "." << directorArr.get(i).year << "\n"
			<< "The number of films directed by: " << directorArr.get(i).films << "\nThe films he directed:";
			for (int j = 0; j < connnectionsArr.getSize(); j++) {
				if (connnectionsArr.get(j).id_Directors.contains(directorArr.get(i).id)) {
					int id = connnectionsArr.get(j).id_Film;
					std::cout << filmArr.get(findFilmA(id)).name << " ";
				}
			}
		std::cout << "\n"
			<< "------------------------------------------------------\n";
	}
	return;
}
void Base::printFilmArr()
{
	for (int i = 0; i < filmArr.getSize(); i++) {
		std::cout << "Name: " << filmArr.get(i).name << "\n"
						<< "The release date of the film: "
						<< filmArr.get(i).year << "\n"
						<< "The bugget of the film: " << filmArr.get(i).budget << "\nActors: ";
		int id = findConns(filmArr.get(i).id);
		for (int j = 0; j < connnectionsArr.get(id).id_Actors.getSize(); j++) {
			int n = connnectionsArr.get(id).id_Actors.get(j);
			ActorN a = actorArr.get(findActorA(n));
			std::cout << a.name<< " " << a.surname << "  ";
		}
		std::cout << "\nDirectors: ";
		for (int j = 0; j < connnectionsArr.get(id).id_Directors.getSize(); j++) {
			int n = connnectionsArr.get(id).id_Directors.get(j);
			DirectorN a = directorArr.get(findDirectorA(n));
			std::cout << a.name << " " << a.surname << "  ";
		}
		std::cout << "\n------------------------------------------------------\n";
	}
}

//void Base::printFilmArr()
//{
//	for (int i = 0; i < filmArr.getSize(); i++) {
//		std::cout << "Name: " << filmArr.get(i).name << "\n"
//			<< "The release date of the film: "
//			<< filmArr.get(i).year << "\n"
//			<< "The bugget of the film: " << filmArr.get(i).budget << "\nActors: ";
//		for (int c = 0; c < connnectionsArr.getSize(); c++) {
//			for (int j = 0; j < connnectionsArr.get(c).id_Actors.getSize(); j++) {
//				int id = connnectionsArr.get(c).id_Actors.get(j);
//				std::cout << actorArr.get(findActorA(id)).name << " " << actorArr.get(findActorA(id)).surname << "\n";
//			}
//			std::cout << "Directors:";
//			for (int j = 0; j < connnectionsArr.get(c).id_Directors.getSize(); j++) {
//				int id = connnectionsArr.get(c).id_Directors.get(j);
//				std::cout << directorArr.get(findDirectorA(id)).name << " " << directorArr.get(findDirectorA(id)).surname << "\n";
//			}
//		}
//		
//		std::cout<< "------------------------------------------------------\n";
//	}
//	return;
//}
void Base::printConnsArr() {
	std::cout << connnectionsArr.getSize() << "\n";
	for (int i = 0; i < connnectionsArr.getSize(); i++) {
		std::cout << connnectionsArr.get(i).id_Film << " ";
		if(!connnectionsArr.get(i).id_Actors.isEmpty()) {
			std::cout << connnectionsArr.get(i).id_Actors.get(0);
			for (int j = 1; j < connnectionsArr.get(i).id_Actors.getSize(); j++) {
				std::cout << ";" << connnectionsArr.get(i).id_Actors.get(j);
			}
		}
		else {
			std::cout << "-1";
		}
		if(!connnectionsArr.get(i).id_Directors.isEmpty()){
			std::cout << " " << connnectionsArr.get(i).id_Directors.get(0);
			for (int j = 1; j < connnectionsArr.get(i).id_Directors.getSize(); j++) {
				std::cout << ";" << connnectionsArr.get(i).id_Directors.get(j);
			}
		}
		else {
			std::cout << " " << -1 ;
		}
		std::cout << "\n";
	}
}

void Base::printDirector(ArrayList<int>& no, ArrayList<int>& noF)
{
	std::string result1;
	bool flag = false;
	for (int i = 0; i < directorArr.getSize(); i++) {
		if (!no.contains(directorArr.get(i).id)) {
			flag = false;
			result1 = "Name: " + directorArr.get(i).name + "\n"
				+ "Surname: " + directorArr.get(i).surname + "\n"
				+ "Date of birth: " + std::to_string(directorArr.get(i).day) + "." + std::to_string(directorArr.get(i).month) + "."
				+ std::to_string(directorArr.get(i).year)
				+ "\nThe number of films directed by: " + std::to_string(directorArr.get(i).films) + "\nThe films he directed: ";
			for (int j = 0; j < NOcons.getSize(); j++) {
				if (NOcons.get(j).id_Directors.contains(directorArr.get(i).id)) {
					int id = NOcons.get(j).id_Film;
					if (!noF.contains(id)) {
						result1 += filmArr.get(findFilmA(id)).name + " ";
						flag = true;
					}
				}
			}
			result1 += "\n------------------------------------------------------\n";
			if (flag) {
				std::cout << result1 ;
			}
		}
		
	}
	
	return;
}
void Base::printActor(ArrayList<int>& noA, ArrayList<int>& noF)
{
	std::string result1;
	bool flag = false;
	for (int i = 0; i < actorArr.getSize(); i++) {
		if (!noA.contains(actorArr.get(i).id)) {
			flag = false;
			result1 = "Name: " + actorArr.get(i).name + "\n"
				+ "Surname: " + actorArr.get(i).surname + "\n"
				+ "Date of birth: " + std::to_string(actorArr.get(i).day) + "." + std::to_string(actorArr.get(i).month) + "."
				+ std::to_string(actorArr.get(i).year) + "\n"
				+ "The number of films the actor has played: " + std::to_string(actorArr.get(i).films) + "\nThe films he played in:";

			for (int j = 0; j < NOcons.getSize(); j++) {
				if (NOcons.get(j).id_Actors.contains(actorArr.get(i).id)) {
					int id = NOcons.get(j).id_Film;
					if (!noF.contains(id)) {
						result1 += filmArr.get(findFilmA(id)).name + " ";
						flag = true;
					}
				}
			}
			result1 += "\n------------------------------------------------------\n";
			if (flag) {
				std::cout << result1;
			}
		}
	}
	return;
}
void Base::printFilm(ArrayList<int>& noA, ArrayList<int>& noD, ArrayList<int>& noF)
{
	std::string result;
	bool flag1, flag2;
	for (int i = 0; i < filmArr.getSize(); i++) {
		if (!noF.contains(filmArr.get(i).id)) {
			flag1 = false;
			flag2 = false;
			result = "Name: " + filmArr.get(i).name + "\n"
				+ "The release date of the film: "
				+ std::to_string(filmArr.get(i).year) + "\n"
				+ "The bugget of the film: " + std::to_string(filmArr.get(i).budget) + "\nActors: ";

			for (int j = 0; j < NOcons.get(i).id_Actors.getSize(); j++) {
				int id = NOcons.get(i).id_Actors.get(j);
				if (!noA.contains(id)) {
					result += actorArr.get(findActorA(id)).name + " " + actorArr.get(findActorA(id)).surname + "\n";
					flag1 = true;
				}
			}
			result += "Directors:";
			for (int j = 0; j < NOcons.get(i).id_Directors.getSize(); j++) {
				int id = NOcons.get(i).id_Directors.get(j);
				if (!noD.contains(id)) {
					result += directorArr.get(findDirectorA(id)).name + " " + directorArr.get(findDirectorA(id)).surname + "\n";
					flag2 = true;
				}
			}
			result += "------------------------------------------------------\n";
			if (flag1 && flag2) {
				std::cout << result;
			}
		}
	}
	return;
}

void Base::addActor(const std::string& name, const std::string& surname)
{
	int id = findActor(name, surname, 'd');
	if (id != -1) {
		std::cout << "Such an actor is already in the database\n";
		return;
	}
	ActorN act;
	act.id = ++last_id_actor;
	act.name = name;
	act.surname = surname;
	std::cout << "Enter the Day of birth(00 00 0000(d,m,y)\n";
	std::cin >> act.day >> act.month >> act.year;
	act.films = 0;
	actorArr.push(act);
}
void Base::addDirector(const std::string& name, const std::string& surname)
{
	int id = findDirector(name, surname, 'd');
	if (id != -1) {
		std::cout << "Such a director is already in the database\n";
		return;
	}
	DirectorN act;
	act.id = ++last_id_director;
	act.name = name;
	act.surname = surname;
	std::cout << "Enter the Day of birth(00 00 0000(d,m,y)\n";
	std::cin >> act.day >> act.month >> act.year;
	act.films = 0;
	directorArr.push(act);
}
void Base::addFilm(const std::string& name)
{
	int id = findFilm(name, 'd');
	if (id != -1) {
		std::cout << "Such a film is already in the database\n";
		return;
	}
	FilmN flm;
	flm.id = ++last_id_film;
	flm.name = name;
	std::cout << "Enter the the release year of the film\n";
	std::cin >>  flm.year;
	std::cout << "Enter budget of the film\n";
	std::cin >> flm.budget;
	filmArr.push(flm);
}


void Base::addConns(int film_id)
{
	int id = findConns(film_id);
	Connections con;
	if (id == -1) {
		
		con.id_Film = film_id;
	}
	else{
		con = connnectionsArr.get(id);
	}
	std::cout << "Enter names of actors who played in this film(in the end press (/ /)\n";
	std::string name, surname;
	do{
		std::cin >> name >> surname;
		if(name == "/" && surname == "/")break;
		int id_a = findActor(name, surname, 'a');
		if (id_a == -1) {
			std::cout << "There is no such actor in DB\n";
			
		}
		else{
			if (!con.id_Actors.contains(id_a)) {
				con.id_Actors.push(id_a);
				actorArr.get(findActorA(id_a)).plus();
			}
			else {
				std::cout << "The actor is already donnected to the film\n";
			}
		}

	} while (true);
	system("cls");
	std::cout << "Enter names of director who directed this film(in the end press (/ /)\n";
	do {
		std::cin >> name >> surname;
		if(name == "/" && surname == "/")break;
		int id_d = findDirector(name, surname, 'a');
		if (id_d == -1) {
			std::cout << "There is no such director in DB\n";
			
		}
		else{
			if (!con.id_Directors.contains(id_d)) {
				con.id_Directors.push(id_d);
				directorArr.get(findDirectorA(id_d)).plus();
			}
			else {
				std::cout << "The director is already connected to the film\n";
			}
		}
	} while (true);
	if (id == -1) {

		connnectionsArr.push(con);
	}
	else {
		connnectionsArr.set(con, id);
	}
	
}



void Base::deleteActor(const std::string& name, const std::string& surname)
{
	int id = findActor(name, surname, 'a');
	if (id == -1) {
		std::cout << "There is no such an actor in data base\n";
		return;
	}
	for (int i = 0; i < connnectionsArr.getSize(); i++) {
		Connections con = connnectionsArr.get(i);
		for (int j = 0; j < con.id_Actors.getSize(); j++) {
			if (id == con.id_Actors.get(j)) {
				con.id_Actors.del(j);
				connnectionsArr.set(con, i);
				break;
			}
		}
	}
	id = findActor(name, surname, 'd');
	if (id == -1) {
		std::cout << "There is no such an actor in data base\n";
		return;
	}
	else {
		actorArr.del(id);
	}
	return;
}
void Base::deleteDirector(const std::string& name, const std::string& surname)
{
	int id = findDirector(name, surname, 'a');
	if (id == -1) {
		std::cout << "There is no such an actor in data base\n";
		return;
	}
	for (int i = 0; i < connnectionsArr.getSize(); i++) {
		Connections con = connnectionsArr.get(i);
		for (int j = 0; j < con.id_Directors.getSize(); j++) {
			if (id == con.id_Directors.get(j)) {
				con.id_Directors.del(j);
				connnectionsArr.set(con, i);
				break;
			}
		}
	}
	id = findDirector(name, surname, 'd');
	if (id == -1) {
		std::cout << "There is no such an actor in data base\n";
		return;
	}
	else {
		directorArr.del(id);
	}
	return;
}
void Base::deleteFilm(const std::string& name)
{
	int id = findFilm(name, 'a');
	for (int i = 0; i < connnectionsArr.getSize(); i++) {
		if (connnectionsArr.get(i).id_Film == id) {
			connnectionsArr.del(i);
			break;
		}
	}

	id = findFilm(name, 'd');
	if (id == -1) {
		std::cout << "There is no such an film in data base\n";
	}
	else {
		filmArr.del(id);
	}
	return;
}


void Base::menu1()
{
	std::cout << "1) Add to table\n";
	std::cout << "2) Delete from the table\n";
	std::cout << "3) Show filtered table\n";
	std::cout << "4) Filter the table\n";
	std::cout << "5) Show full table\n";
	std::cout << "0) Exit\n";
	
}
void Base::menu2()
{
	std::cout << "1) Film table\n";
	std::cout << "2) Actor table\n";
	std::cout << "3) Director table\n";
	std::cout << "0) Go back\n";
	
}
void Base::menu3()
{
	std::cout << "1) name\n";
	std::cout << "2) surname\n";
	std::cout << "3) year\n";
	std::cout << "4) films\n";
}
void Base::menu4()
{
	std::cout << "1) More than\n";
	std::cout << "2) Less than\n";
	std::cout << "3) Equal to\n";
}
void Base::menu5()
{
	std::cout << "1) name\n";
	std::cout << "2) year\n";
	std::cout << "3) budget\n";
}

Base::Base() 
{
	
	ReadDataFileActor("actor.txt");
	ReadDataFileDirector("director.txt");
	ReadDataFileFilm("film.txt");
	ReadDataFileConnections("connections.txt");
	NOcons = connnectionsArr;
}
Base::~Base() {

	writeDataFileActor("actor.txt");

	writeDataFileDirector("director.txt");

	writeDataFileFilm("film.txt");
	
	writeDataFileConnections("connections.txt");
	filmArr.~ArrayList();
	connnectionsArr.~ArrayList();
	actorArr.~ArrayList();
	directorArr.~ArrayList();
	NOacts.~ArrayList();
	NOdirs.~ArrayList();
	NOfilms.~ArrayList();
}

void Base::interface() 
{
	
	int key1,key2, key3,key4, id, year;
	std::string name, surname;
	do{
		system("cls");
		menu1();
		std::cin >> key1;
		switch (key1) {
		case  5:
			system("cls");
			menu2();
			std::cin >> key2;
			system("cls");
			switch (key2) {
			case 2:
				printActorArr();
				system("pause");
				break;
			case 1:
				printFilmArr();
				system("pause");
				break;
			case 3:
				printDirectorArr();
				system("pause");
				break;
			default:
				break;
			}
			system("cls");
			break;
		case 1:
			do{
				system("cls");
				menu2();
				std::cout << "4) Connections\n";
				std::cin >> key2;
				system("cls");
				switch (key2) {
				case 1:
					std::cout << "Enter film name\n";
					getline( std::cin,name);
					getline(std::cin, name);
					for (int i = 0; i < name.size(); i++) {
						if (name[i] == ' ') {
							surname += '_';
						}
						else {
							surname += name[i];
						}
					}
					addFilm(surname);

					break;

				case 2:
					std::cout << "Enter actor name and surname\n";
					std::cin >> name >> surname;
					addActor(name, surname);
					break;

				case 3:
					std::cout << "Enter diector name and surname\n";
					std::cin >> name >> surname;
					addDirector(name, surname);
					break;
				case 4:
					std::cout << "Enter film name\n";
					std::cin >> name;
					
					id = findFilm(surname, 'a');
					if (id == -1) {
						std::cout << "There is no such a film in Data BAse\n";
					}
					else{
						addConns(id);
					}
				default:
					break;
				}
			} while (key2 != 0);
			break;
			
		case 2:
			do{
				system("cls");
				menu2();
				std::cin >> key2;
				system("cls");
				switch (key2) {
				case 1:
					std::cout << "Enter film name\n";
					std::cin >> name;
					deleteFilm(name);
					break;

				case 2:
					std::cout << "Enter actor name and surname\n";
					std::cin >> name >> surname;
					deleteActor(name, surname);
					break;

				case 3:
					std::cout << "Enter diector name and surname\n";
					std::cin >> surname;
					deleteDirector(name, surname);
					break;

				default:
					break;
				}
			} while (key2 != 0);
			break;

		case 3:
			system("cls");
			menu2();
			std::cin >> key2;
			system("cls");
			switch (key2) {
			case 2:
				printActor(NOacts,NOfilms);
				system("pause");
				break;
			case 1:
				printFilm(NOacts,NOdirs,NOfilms);
				system("pause");
				break;
			case 3:
				printDirector(NOdirs,NOfilms);
				system("pause");
				break;
			default: 
				break;
			}
			system("cls");
			break;
	
		case 4:
			system("cls");
			menu2();
			std::cout << "4) Clear filter\n";
			std::cin >> key2;
			system("cls");
			switch (key2) {
			case 2:
				system("cls");
				menu3();
				std::cin >> key3;
				switch (key3) {
				case 1:
					std::cin >> name;
					for (int i = 0; i < actorArr.getSize(); i++) {
						if (actorArr.get(i).name != name) {
							NOacts.push(actorArr.get(i).id);
						}
					}
					break;
				case 2:
					std::cin >> name;
					for (int i = 0; i < actorArr.getSize(); i++) {
						if (actorArr.get(i).surname != name) {
							NOacts.push(actorArr.get(i).id);
						}
					}
					break;
				case 3:
					system("cls");
					menu4();
					std::cin >> key4;
					system("cls");
					std::cout << "Enter year\n";
					std::cin >> year;
					switch (key4) {
					case 1:
						for (int i = 0; i < actorArr.getSize(); i++) {
							if (actorArr.get(i).year < year) {
								NOacts.push(actorArr.get(i).id);
							}
						}
						break;
					case 2:
						for (int i = 0; i < actorArr.getSize(); i++) {
							if (actorArr.get(i).year > year) {
								NOacts.push(actorArr.get(i).id);
							}
						}
						break;
					case 3:
						for (int i = 0; i < actorArr.getSize(); i++) {
							if (actorArr.get(i).year != year) {
								NOacts.push(actorArr.get(i).id);
							}
						}
						break;
					default:
						break;
					}
					break;
				case 4:
					system("cls");
					menu4();
					std::cin >> key4;
					system("cls");
					std::cout << "Enter films\n";
					std::cin >> year;
					switch (key4) {
					case 1:
						for (int i = 0; i < actorArr.getSize(); i++) {
							if (actorArr.get(i).films > year) {
								NOacts.push(actorArr.get(i).id);
							}
						}
						break;
					case 2:
						for (int i = 0; i < actorArr.getSize(); i++) {
							if (actorArr.get(i).films < year) {
								NOacts.push(actorArr.get(i).id);
							}
						}
						break;
					case 3:
						for (int i = 0; i < actorArr.getSize(); i++) {
							if (actorArr.get(i).films == year) {
								NOacts.push(actorArr.get(i).id);
							}
						}
						break;
					default:
						break;
					}
					break;
				}
				break;

			case 3:
				system("cls");
				menu3();
				std::cin >> key3;
				switch (key3) {
				case 1:
					std::cin >> name;
					for (int i = 0; i < directorArr.getSize(); i++) {
						if (directorArr.get(i).name != name) {
							NOdirs.push(directorArr.get(i).id);
						}
					}
					break;
				case 2:
					std::cin >> name;
					for (int i = 0; i < directorArr.getSize(); i++) {
						if (directorArr.get(i).surname != name) {
							NOdirs.push(directorArr.get(i).id);
						}
					}
					break;
				case 3:
					system("cls");
					menu4();
					std::cin >> key4;
					system("cls");
					std::cout << "Enter year\n";
					std::cin >> year;
					switch (key4) {
					case 1:
						for (int i = 0; i < directorArr.getSize(); i++) {
							if (directorArr.get(i).year < year) {
								NOdirs.push(directorArr.get(i).id);
							}
						}
						break;
					case 2:
						for (int i = 0; i < directorArr.getSize(); i++) {
							if (directorArr.get(i).year > year) {
								NOdirs.push(directorArr.get(i).id);
							}
						}
						break;
					case 3:
						for (int i = 0; i < directorArr.getSize(); i++) {
							if (directorArr.get(i).year != year) {
								NOdirs.push(directorArr.get(i).id);
							}
						}
						break;
					default:
						break;
					}
					break;
				case 4:
					system("cls");
					menu4();
					std::cin >> key4;
					system("cls");
					std::cout << "Enter films\n";
					std::cin >> year;
					switch (key4) {
					case 1:
						for (int i = 0; i < directorArr.getSize(); i++) {
							if (directorArr.get(i).films < year) {
								NOdirs.push(directorArr.get(i).id);
							}
						}
						break;
					case 2:
						for (int i = 0; i < directorArr.getSize(); i++) {
							if (directorArr.get(i).films > year) {
								NOdirs.push(directorArr.get(i).id);
							}
						}
						break;
					case 3:
						for (int i = 0; i < directorArr.getSize(); i++) {
							if (directorArr.get(i).films != year) {
								NOdirs.push(directorArr.get(i).id);
							}
						}
						break;
					default:
						break;
					}
					break;
				}
				break;

			case 1:
				system("cls");
				menu5();
				std::cin >> key3;
				switch (key3) {
				case 1:
					std::cin >> name;
					for (int i = 0; i < filmArr.getSize(); i++) {
						if (filmArr.get(i).name != name) {
							NOfilms.push(filmArr.get(i).id);
						}
					}
					break;
				case 2:
					system("cls");
					menu4();
					std::cin >> key4;
					system("cls");
					std::cout << "Enter year\n";
					std::cin >> year;
					switch (key4) {
					case 1:
						for (int i = 0; i < filmArr.getSize(); i++) {
							if (filmArr.get(i).year < year) {
								NOfilms.push(filmArr.get(i).id);
							}
						}
						break;
					case 2:
						for (int i = 0; i < filmArr.getSize(); i++) {
							if (filmArr.get(i).year > year) {
								NOfilms.push(filmArr.get(i).id);
							}
						}
						break;
					case 3:
						for (int i = 0; i < filmArr.getSize(); i++) {
							if (filmArr.get(i).year != year) {
								NOfilms.push(filmArr.get(i).id);
							}
						}
						break;
					default:
						break;
					}
					break;
				case 3:
					system("cls");
					menu4();
					std::cin >> key4;
					system("cls");
					std::cout << "Enter budget\n";
					std::cin >> year;
					switch (key4) {
					case 1:
						for (int i = 0; i < filmArr.getSize(); i++) {
							if (filmArr.get(i).budget < year) {
								NOfilms.push(filmArr.get(i).id);
							}
						}
						break;
					case 2:
						for (int i = 0; i < filmArr.getSize(); i++) {
							if (filmArr.get(i).budget > year) {
								NOfilms.push(filmArr.get(i).id);
							}
						}
						break;
					case 3:
						for (int i = 0; i < filmArr.getSize(); i++) {
							if (filmArr.get(i).budget != year) {
								NOfilms.push(filmArr.get(i).id);
							}
						}
						break;
					default:
						break;
					}
					break;
				}
				break;
			case 4:
				NOacts = ArrayList<int>();
				NOdirs = ArrayList<int>();
				NOfilms = ArrayList<int>();
				NOcons = connnectionsArr;
				break;
			default:
				break;
			}
			//filter();
			break;
		}
	}while (key1 != 0);
}
