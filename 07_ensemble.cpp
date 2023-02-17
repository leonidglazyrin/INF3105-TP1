/**
 * Tests unitaires pour Ensemble<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "ensemble.h"
#include <iostream>

int compteurComparaisons = 0;
class A {
	private:
		int x;
	public:
		A(int x_ = 0) : x(x_) {}
		bool operator < (const A & o) const { 
			compteurComparaisons++;
			return x < o.x; 
		}
		bool operator <= (const A & o) const { 
			compteurComparaisons++;
			return x <= o.x;	
		}
		bool operator == (const A & o) const { 
			compteurComparaisons++;
			return x == o.x;	
		}
		bool operator != (const A & o) const { 
			compteurComparaisons++;
			return x != o.x;	
		}
		bool operator >= (const A & o) const { 
			compteurComparaisons++;
			return x >= o.x;	
		}
		bool operator > (const A & o) const {	
			compteurComparaisons++;
			return x > o.x;	
		}
};

int main() {
	Ensemble<A> usb;
	int erreur = 0;
	int n = 128 * 128, log_n = 14;
	for(int i = 0; i < n; i++)
		usb.inserer(i);
	int sum = 0;
	for(int i = n; i < 2 * n; i++) {
		compteurComparaisons = 0;
		usb.contient(i);
		sum += compteurComparaisons;
	}
	if((sum / n) > 4 * log_n) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	sum = 0;
	for(int i = 0; i < n; i++) {
		compteurComparaisons = 0;
		usb.contient(i);
		sum += compteurComparaisons;
	}
	if((sum / n) > 4 * log_n) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	Ensemble<A> hdd, ssd, flash;
	n = 16;
	for(int i = 0; i < 2 * 64 * n; i++) {
		hdd.inserer(i);
		ssd.inserer(i + 64 * n);
	}
	compteurComparaisons = 0;
	flash = hdd.fusion(ssd);
	if(compteurComparaisons > 194 * n) {
		std::cout << "Compte : " << compteurComparaisons << " vs : " << 194 * n << std::endl;
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	compteurComparaisons = 0;
	flash = hdd.inter(ssd);
	if(compteurComparaisons > 194 * n) {
		std::cout << "Compte : " << compteurComparaisons << " vs : " << 194 * n << std::endl;
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	compteurComparaisons = 0;
	flash = hdd.minus(ssd);
	if(compteurComparaisons > 194 * n) {
		std::cout << "Compte : " << compteurComparaisons << " vs : " << 194 * n << std::endl;
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
