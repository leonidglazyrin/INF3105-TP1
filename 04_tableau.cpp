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
	tab.ajouter(3);
	tab.ajouter(3);
	tab.ajouter(3);
	if(tab.taille() != 8) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	tab.vider();
	if(tab.taille() != 0) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	tab.ajouter(-2);
	tab.ajouter(10);
	tab.ajouter(4);
	tab.ajouter(3);
	if(tab.taille() != 4) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	Tableau<int> sab;
	int n = 2 * 256 * 256;
	for(int i = 0; i < n; i++)
		sab.ajouter(i);
	if(sab.taille() != n) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	sab.vider();
	if(sab.taille() != 0) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	for(int i = 0; i < n; i++)
		sab.ajouter(i * 3);   
	if(sab.taille() != n){
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(int i = 0; i < sab.taille(); i++)
		if(sab[i] != i * 3)
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - VII" << std::endl;
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
