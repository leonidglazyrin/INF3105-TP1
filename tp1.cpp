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
 * Lit des paires de membres à partir de l'entrée standard et les ajoute à un tableau de tableaux d'entiers.
 *
 * @param source Le tableau de tableaux d'entiers à remplir avec les paires de membres lues.
 */
void input_pairs(Tableau<Tableau<int>> & source) {
	int premier_membre, deuxieme_membre;

	while (cin >> premier_membre >> deuxieme_membre) {
		Tableau<int> tmp;
        tmp.ajouter(premier_membre);
        tmp.ajouter(deuxieme_membre);
		source.ajouter(tmp);
    }
}

/**
 * Compte le nombre de membres dans chaque ensemble d'un tableau 
 * d'ensembles et renvoie un tableau des comptes.
 *
 * @param result_final Le tableau d'ensembles à analyser.
 * @return Un tableau d'entiers représentant le nombre de membres dans chaque ensemble.
 */
Tableau<int> count_members(const Tableau<Ensemble<int>> & result_final)  {
	Tableau<int> comptes;
	for (int i = 0; i < result_final.taille(); ++i)
		comptes.ajouter(result_final[i].taille());
	return comptes;
}

/**
 * Ajoute les membres solitaires à un tableau d'ensembles.
 *
 * @param nombre_membres Le nombre total de membres dans le tableau.
 * @param membres Le tableau de membres, où chaque membre est représenté par un entier.
 * @param result_final Le tableau d'ensembles à modifier, 
 *						où les ensembles représentent des groupes de membres.
 */
void add_loners(const int nombre_membres, const Tableau<int> & membres, Tableau<Ensemble<int>> & result_final) {
	for (int i = 0; i < nombre_membres; ++i) {
		if(membres[i] == 0) {
			Ensemble<int> tmp;
			tmp.inserer(i);
			result_final.ajouter(tmp);
		}
	}
}

/**
 * Calcule les intersections entre les ensembles d'un tableau 
 * d'ensembles et renvoie un nouveau tableau d'ensembles résultant.
 * Enleve les ensembles qui ont formees un nouvel, mais garde ceux qui
 * n'en n'ont pas.
 *
 * @param tmp_result Le tableau d'ensembles à utiliser pour les calculs d'intersection.
 * @return Un nouveau tableau d'ensembles résultant des calculs d'intersection.
 */
Tableau<Ensemble<int>> intersections(Tableau<Ensemble<int>> & tmp_result) {
	Tableau<Ensemble<int>> result_final;
	for (int i = 0; i < tmp_result.taille(); ++i) {
		for (int j = 1; j < tmp_result.taille(); ++j) {
			if (tmp_result[i].inter(tmp_result[j]).taille() != 0){
				Ensemble<int> tmp = tmp_result[i].fusion(tmp_result[j]);
				tmp_result.enlever(j);
				tmp_result.enlever(i);
				result_final.ajouter(tmp);
			}
		}
	}
	return result_final;
}

/**
 * Cette fonction lit son entrée standard pour construire le réseau.
 * Par la suite, elle calcule le nombre de communautés et leur tailles
 * et retourne un tableau de type Tableau<int> contenant les tailles de 
 * toutes les communautés présentes dans le réseau lu.
 */
Tableau<int> communautes() {
	// Stocker la premiere ligne contenant le nombre de membres
	int nombre_membres;
	cin >> nombre_membres;
	
	// Tableau de longueur du nombre de membre au fur et a mesure 1 sera mis pour les membre dans une communaute
	Tableau<int> membres;
	for (int i = 0; i < nombre_membres; ++i)
		membres.ajouter(0);

	// Tableau de paire correspondants aux lignes dans le fichier en entree
	Tableau<Tableau<int>> source;
	input_pairs(source);

	// Ce tableau aura des ensembles qui pourraient avoir une intersection
	Tableau<Ensemble<int>> tmp_result;

	for (int i = 0; i < source.taille(); ++i){
		int j;
		for (j = 0; j < tmp_result.taille(); ++j) {
			// Si l'un des deux est dans un ensemble, on insere l'autre dedans
			if (tmp_result[j].contient(source[i][0])){
				membres[source[i][1]] = 1;
				tmp_result[j].inserer(source[i][1]);
				break;
			} else if (tmp_result[j].contient(source[i][1])){
				membres[source[i][0]] = 1;
				tmp_result[j].inserer(source[i][0]);
				break;
			}
		}
		// Si la nouvelle paire n'a pu etre mise dans aucun autre ensemble, on cree un nouveau ensemble(communaute)
		if (j == tmp_result.taille()){
			Ensemble<int> tmp;
			tmp.inserer(source[i][0]);
			tmp.inserer(source[i][1]);
			tmp_result.ajouter(tmp);
			membres[source[i][0]] = 1;
			membres[source[i][1]] = 1;
		}
	}

	// Verifier les intersections entre ensembles
	Tableau<Ensemble<int>> result_final;
	result_final = intersections(tmp_result);

	// Rajouter les ensembles qui n'avaient pas d'intersections avec un autre ensemble
	for (int i = 0; i < tmp_result.taille(); ++i)
		result_final.inserer(tmp_result[i]);

	// Rajouter les membre qui n'etaient dans aucune communaute
	add_loners(nombre_membres, membres, result_final);

	return count_members(result_final);
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
