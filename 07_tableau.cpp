/**
 * Tests unitaires pour Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "tableau.h"
#include <iostream>

int main() {
	Tableau<int> tab;
	int erreur = 0;
	tab.ajouter(3);
	tab.ajouter(1);
	tab.ajouter(7);
	tab.ajouter(-2);
	tab.ajouter(10);
	tab.ajouter(3);
	tab.ajouter(-1);
	tab.ajouter(7);
	tab.ajouter(3);
	if(tab.occurrence(3) != 3 || 
			tab.occurrence(7) != 2 || 
			tab.occurrence(10) != 1 || 
			tab.occurrence(-1) != 1 ||
			tab.occurrence(13) != 0) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	Tableau<int> sab;
	int n = 2 * 256 * 256;
	int j = 0;
	for(int i = 0; i < n; i++) {
		sab.ajouter(j);
		j = i % 3105;
	}
	int old_erreur = erreur;
	for(int i = 0; i < 3105; i++)
		if((i == 0 && sab.occurrence(i) != 44) ||
				(1 <= i && i <= 660 && sab.occurrence(i) != 43) ||
				(661 <= i && i <= 3104 && sab.occurrence(i) != 42))
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - II" << std::endl;
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
