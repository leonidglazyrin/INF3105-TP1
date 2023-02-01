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
	tab.inserer(1);
	tab.inserer(2);
	tab.inserer(3);
	tab.inserer(4);
	tab.inserer(5);
	tab.inserer(6);
	for(int i = 6; i > 0; i--)
		if(tab[i - 1] != (6 - i) + 1)
			erreur++;
	if(erreur != 0)
		std::cerr << "ECHEC - I" << std::endl;
	tab.inserer(-1, 5);
	if(tab[5] != -1) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	tab.inserer(-1, 3);
	if(tab[3] != -1) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	tab.inserer(-2, 3);
	if(tab[3] != -2) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	Tableau<int> sab;
	int n = 128 * 128;
	for(int i = 0; i < n; i++)
		sab.inserer(i * 2);
	if(sab.taille() != n) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	int pair = (n - 1) * 2, old_erreur = erreur;
	for(int i = 0; i < sab.taille(); i++) {
		if(sab[i] != pair)
			erreur++;
		pair -= 2;
	}
	if(old_erreur != erreur)
		std::cerr << "ECHEC - VI" << std::endl;
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
