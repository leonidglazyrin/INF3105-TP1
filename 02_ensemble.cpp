/**
 * Tests unitaires pour Ensemble<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "ensemble.h"
#include <iostream>

int main() {
	Ensemble<int> ssd;
	int erreur = 0;
	ssd.inserer(7);
	ssd.inserer(3);
	ssd.inserer(1);
	ssd.inserer(0);
	ssd.inserer(5);
	ssd.inserer(7);
	if(ssd.taille() != 5) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	ssd.inserer(3);
	ssd.inserer(3);
	ssd.inserer(1);
	ssd.inserer(1);
	ssd.inserer(0);
	ssd.inserer(0);
	ssd.inserer(5);
	ssd.inserer(5);
	if(ssd.taille() != 5) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	Ensemble<int> hdd;
	int n = 64 * 64;
	for(int i = 0; i < n; i++)
		hdd.inserer(i);
	if(hdd.taille() != n) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(int i = 0; i < n; i++)
		if(hdd.inserer(i))
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - IV" << std::endl;
	if(hdd.taille() != n) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return 0;
}

