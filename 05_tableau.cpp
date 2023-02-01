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
	int n = 256 * 256 * 256;
	for(int i = 0; i < n; i++)
		tab.ajouter(i * 2);
	if(tab.taille() != n) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(int i = 0; i < tab.taille(); i++)
		if(tab[i] != i * 2)
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - II" << std::endl;
	Tableau<int> sab(tab);
	if(sab.taille() != n){
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	old_erreur = erreur;
	for(int i = 0; i < sab.taille(); i++)
		if(sab[i] != i * 2)
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - IV" << std::endl;
	tab.vider();
	if(tab.taille() != 0) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(sab.taille() != n){
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	old_erreur = erreur;
	for(int i = 0; i < sab.taille(); i++)
		if(sab[i] != i * 2)
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - VII" << std::endl;
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
