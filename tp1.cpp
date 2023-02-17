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
	Tableau<Tableau<int>> source;
	int x, y, n;
	cin >> n;

	while (cin >> x >> y) {
		Tableau<int> tmp;
        tmp.ajouter(x);
        tmp.ajouter(y);
		source.ajouter(tmp);
    }

	Tableau<Ensemble<int>> result;

	for (int i = 0; i < source.taille(); ++i){
		int j;
		for (j = 0; j < result.taille(); ++j) {
			if (result[j].contient(source[i][0])){
				result[j].inserer(source[i][1]);
				break;
			} else if (result[j].contient(source[i][1])){
				result[j].inserer(source[i][0]);
				break;
			}
		}
		if (j == result.taille()){
			Ensemble<int> tmp;
			tmp.inserer(source[i][0]);
			tmp.inserer(source[i][1]);
			result.ajouter(tmp);
		}
	}

	Tableau<Ensemble<int>> result_final;

	for (int i = 0; i < result.taille(); ++i) {
		for (int j = 1; j < result.taille(); ++j) {
			if (result[i].inter(result[j]).taille() != 0){
				Ensemble<int> tmp = result[i].fusion(result[j]);
				result.enlever(j);
				result.enlever(i);
				result_final.inserer(tmp);
			}
		}
	}

	for (int i = 0; i < result.taille(); ++i) {
		result_final.inserer(result[i]);
	}

	for (int i = 0; i < result_final.taille(); ++i) {
		cout << result_final[i] << endl;
	}

	Tableau<int> results;
	for (int i = 0; i < result_final.taille(); ++i) {
		results.inserer(result_final[i].taille());
	}

	for (int i = 0; i < results.taille(); ++i) {
		cout << results[i] << endl;
	}

	return results;
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
