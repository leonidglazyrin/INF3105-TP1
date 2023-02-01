/**
 * Tests unitaires pour Ensemble<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "ensemble.h"
#include <iostream>

int main() {
	Ensemble<int> ssd, hdd, flash;
	int erreur = 0;
	ssd.inserer(7);
	ssd.inserer(3);
	ssd.inserer(1);
	ssd.inserer(0);
	ssd.inserer(5);
	ssd.inserer(2);
	hdd.inserer(3);
	hdd.inserer(1);
	hdd.inserer(2);
	flash = ssd.minus(hdd);
	if(flash.taille() != 3) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(!flash.contient(7) ||
			!flash.contient(5) ||
			!flash.contient(0)) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	if(flash.contient(1) ||
			flash.contient(2) ||
			flash.contient(3)) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	flash = hdd.minus(ssd);
	if(flash.taille() != 0) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	Ensemble<int> usb, usa, usc;
	int n = 1024;
	for(int i = 0; i < 2 * n; i++) {
		usb.inserer(i);
		usa.inserer(i + n);
	}
	usc = usa.minus(usb);
	if(usc.taille() != n) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(int i = 0; i < n; i++)
		if(usc.contient(i))
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - V" << std::endl;
	old_erreur = erreur;
	for(int i = 2 * n; i < 3 * n; i++)
		if(!usc.contient(i))
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - VI" << std::endl;

	usc = usb.minus(usb);
	if(usc.taille() != 0) {
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return 0;
}

