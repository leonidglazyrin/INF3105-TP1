/** 
 * Programme principal pour utiliser les classe Tableau et Ensemble.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#include "tableau.h"
#include "ensemble.h"
#include <iostream>

using namespace std;

/***********************************************************************
 * Vous pouvez ajouter toutes les fonctions dont vous avez abesoin.
 * N'oubliez pas de bien commenter vos fonctions, de bien utilisez le 
 * mot-clé const, &, * et de prendre en considération les bonnes 
 * pratiques.
 ***********************************************************************/

/**
 * Cette fonction lit son entrée standard pour construire le réseau.
 * Par la suite, elle calcule le nombre de communautés et leur tailles
 * et retourne un tableau de type Tableau<int> contenant les tailles de 
 * toutes les communautés présentes dans le réseau lu.
 */
Tableau<int> communautes() {
	// À compléter
	return nullptr;
}

/**
 * La fonction main est le point d'entrée. En principe, vous n'avez pas à modifier.
 */
int main() {
	int erreur = 0;
	Tableau<int> tab = communautes();
	if(tab.taille() != 5) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(tab.occurrence(1) != 1 &&
		tab.occurrence(6) != 2 &&
		tab.occurrence(13) != 1 &&
		tab.occurrence(15) != 1) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
