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
	tab.ajouter(-2);
	tab.ajouter(10);
	tab.ajouter(4);
	tab.ajouter(-1);
	tab.ajouter(7);
	tab.ajouter(19);
	tab.enlever();
	if(tab[0] != 1) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(tab.taille() != 7) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	tab.enlever();
	if(tab[0] != -2) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	if(tab.taille() != 6) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	tab.enlever();
	tab.enlever();
	if(tab[3] != 19) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(tab[2] != 7) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	if(tab.taille() != 4) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	} 
	Tableau<int> sab;
	int n = 2 * 256 * 256;
	for(int i = 0; i < n; i++)
		sab.ajouter(i * 2);
	int d = 0;
	for(int i = 0; i < sab.taille(); i += 10) {
		sab.enlever(i);
		d++;
	}
	if(sab.taille() != n - d){
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	int j = 1, dix = 0, old_erreur = erreur;
	for(int i = 0; i < n - d; i++) {
		if(sab[i] != (i + j) * 2)
			erreur++;
		dix++;
		if(dix == 10) {
			j++;
			dix = 0;
		}
	}
	if(old_erreur != erreur)
		std::cerr << "ECHEC - VIII" << std::endl;
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
