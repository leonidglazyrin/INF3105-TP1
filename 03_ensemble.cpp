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
	if(!ssd.contient(7)) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(ssd.contient(-1)) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	if(ssd.taille() != 5) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	ssd.enlever(7);
	if(ssd.contient(7)) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(ssd.taille() != 4) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	Ensemble<int> hdd;
	int n = 64 * 64;
	for(int i = 0; i < n; i++)
		hdd.inserer(i);
	int old_erreur = erreur;
	for(int i = 0; i < n; i++)
		if(!hdd.contient(i))
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - VI" << std::endl;
	old_erreur = erreur;
	for(int i = n; i < 2 * n; i++)
		if(hdd.contient(i))
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - VII" << std::endl;
	old_erreur = erreur;
	for(int i = n; i < 2 * n; i++) {
		if(hdd.enlever(i))
			erreur++;
		if(!hdd.enlever(i - n))
			erreur++;
	}
	if(old_erreur != erreur)
		std::cerr << "ECHEC - VIII" << std::endl;
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return 0;
}

