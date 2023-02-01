/**
 * Tests unitaires pour Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "tableau.h"
#include <iostream>

unsigned int compteurAffectations = 0;
class A {
	private:
		int x;
	public:
		A(int x_ = 0) : x(x_) {}
		bool operator < (const A & o) const { return x < o.x; }
		bool operator <= (const A & o) const { return x <= o.x;	}
		bool operator == (const A & o) const { return x == o.x;	}
		bool operator != (const A & o) const { return x != o.x;	}
		bool operator >= (const A & o) const { return x >= o.x;	}
		bool operator > (const A & o) const {	return x > o.x;	}
		A & operator = (const A & o) {
			compteurAffectations++;
			x = o.x;
			return *this;
		}
};

int main() {
	Tableau<A> tab;
	int erreur = 0;
	int size = 256 * 256 * 256;
	int affectations = 33554428;
	compteurAffectations = 0;
	for(int i = 0; i < size; i++)
		tab.ajouter(i);
	unsigned int affectations_tab = compteurAffectations;
	Tableau<A> sab(size + 1);
	compteurAffectations = 0;
	for(int i = 0; i < size; i++)
		sab.ajouter(i);
	unsigned int affectations_sab = compteurAffectations;
	if(affectations_sab != size) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(affectations_tab != affectations) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}	
	if(affectations_sab >= affectations_tab) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
