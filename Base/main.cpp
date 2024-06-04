#include "Base.h"

int main()
{
	Base base;
	base.interface();

	/*ArrayList<Connections> cons;
	ArrayList<int> noact;
	ArrayList<int> noflm;
	ArrayList<int> nodir;

	for (int i = 0; i < 3; i++) {
		Connections c;
		c.id_Film = i;
		if(i != 2){
			noflm.push(i);
			noact.push(i + 2);
			nodir.push(i + 1);
		}
		c.id_Actors.push(i + 1);
		c.id_Actors.push(i + 3);
		c.id_Directors.push(i + 2);
		cons.push(c);
	}

	for (int i = 0; i < cons.getSize(); i++) {
		std::cout << cons.get(i).id_Film << " "
			<< cons.get(i).id_Actors.get(0) << ";"
			<< cons.get(i).id_Actors.get(1) << " "
			<< cons.get(i).id_Directors.get(0) << "\n";
	}

	for (int i = 0; i < 2; i++) {
		std::cout <<"F " << noflm.get(i) << "A "
			<< noact.get(i) << "D "
			<< nodir.get(i) << "\n";
	}*/
}

