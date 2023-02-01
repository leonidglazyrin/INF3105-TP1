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
	hdd.inserer(-7);
	hdd.inserer(-3);
	hdd.inserer(-1);
	hdd.inserer(-5);
	hdd.inserer(-2);
	flash = ssd.inter(hdd);
	if(flash.taille() != 0) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	flash = hdd.inter(ssd);
	if(flash.taille() != 0) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	ssd.inserer(-7);
	ssd.inserer(-3);
	hdd.inserer(5);
	hdd.inserer(2);
	flash = ssd.inter(hdd);
	if(flash.taille() != 4) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	if(!flash.contient(-7) ||
			!flash.contient(-3) ||
			!flash.contient(5) ||
			!flash.contient(2)) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	flash = hdd.inter(ssd);
	if(flash.taille() != 4) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(!flash.contient(-7) ||
			!flash.contient(-3) ||
			!flash.contient(5) ||
			!flash.contient(2)) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	Ensemble<int> usb, usa, usc;
	int n = 1024;
	for(int i = 0; i < 2 * n; i++) {
		usb.inserer(i);
		usa.inserer(i + n);
	}
	usc = usa.inter(usb);
	if(usc.taille() != n) {
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(int i = n; i < 2 * n; i++)
		if(!usc.contient(i))
			erreur++;
	if(old_erreur != erreur)
		std::cerr << "ECHEC - VIII" << std::endl;
	usc = usb.inter(usb);
	if(usc.taille() != 2 * n) {
		std::cerr << "ECHEC - IX" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return 0;
}

