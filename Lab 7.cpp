#include <iostream>
using namespace std;
class Flying {
	virtual void sound() = 0;
};
class PassangerLiner : Flying {
public:
	void sound() {
		cout << "Passanger liner..." << endl << "sounds noisy, but becaus of people inside" << endl;
	}
};
class SportPlane : Flying {
public:
	void sound() {
		cout << "SSSSPPPOOOORT" << endl << "I AM SPEEEED" << endl;
	};
};
class Planer : Flying {
public:
	void sound() {
		cout << "..." << endl;
	};
};
class destroyer : Flying {
public:
	void sound() {
		cout << "destroyer incoming !" << endl;
	};
};
class bomber : Flying {
public:
	void sound() {
		cout << "bomber?" << endl << "KABOOM!" << endl;
	};
};
void main() {
	bomber Caproni;
	Caproni.sound();
	Planer planer;
	planer.sound();
	destroyer SU34;
	SU34.sound();
	SportPlane  speedie;
	speedie.sound();
	PassangerLiner boing;
	boing.sound();
};