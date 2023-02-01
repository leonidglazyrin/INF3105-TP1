/** 
 * Squelette pour classe générique Ensemble<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2023)
 */

#ifndef __ENSEMBLE_H__
#define __ENSEMBLE_H__

#include "tableau.h"
#include <ostream>

template <class T>
class Ensemble {
	/**************** Interface publique ****************
	* 
	* Vous ne devez pas ajouter de nouvelles fonctions 
	* publiques ni modifier les fonctions déjà présentes.
	*
	*****************************************************/
	public:		
		Ensemble();
		Ensemble(const Ensemble & autre);
		~Ensemble();
  
		// Retourne le nombre d'éléments dans l'ensemble.
		// Complexité : O(1)
		int taille() const;
		
		// Vérifie si l'élément "e" est dans l'ensemble.
		// Complexité : O(log n)
		//	n étant la taille de l'ensemble.
		bool contient(const T & e) const;

		// Insère un élément "e" dans l'ensemble si "e" 
		// n'appartient pas l'ensemble et retourne "true",
		// "false" si l'élément "e" est déjà dans l'ensemble.
		// Complexité : O(n) 
		//	n étant la taille de l'ensemble.
		bool inserer(const T & e);
		
		// Enlève un l'élément "e" de l'ensemble et retourne
		// "true" si l'élément "e" a été supprimé, "false" si 
		// non
		// Complexité : O(n)
		//	n étant la taille de l'ensemble.
		bool enlever(const T & e);

		// Surcharge des opérateurs
		//	- d'égalité == 
		//	Deux ensembles sont égaux s'ils ont 
		//	le même objet qui les représente, ou 
		//	s'ils contiennent exactement les mêmes 
		//	éléments.
		//	Complexité : O(min(n,m))
		//		n étant la taille de l'ensemble courant.
		//		m étant la taille de l'ensemble "autre".
		//	- d'affectation de tableau =
		bool operator == (const Ensemble<T> & autre) const;
		Ensemble<T> & operator = (const Ensemble<T> & autre);
		
		// Retourne un ensemble qui contient les éléments
		// de l'ensemble courant et l'ensemble "autre" donné
		// en paramètre.
		// Complexité : O(n + m)
		//	n étant la taille de l'ensemble courant.
		//	m étant la taille de l'ensemble "autre".
		Ensemble<T> fusion(const Ensemble<T> & autre) const;

		// Retourne un ensemble qui contient les éléments
		// communs entre l'ensemble courant et l'ensemble 
		// "autre" donné en paramètre.
		// Complexité : O(min(n,m))
		//	n étant la taille de l'ensemble courant.
		//	m étant la taille de l'ensemble "autre".
		Ensemble<T> inter(const Ensemble<T> & autre) const;

		// Retourne un ensemble qui contient les éléments
		// qui sont dans l'ensemble courant mais qui 
		// n'appartiennent à l'ensemble "autre" donné en 
		// paramètre.
		// Complexité : O(n)
		//	n étant la taille de l'ensemble courant.
		Ensemble<T> minus(const Ensemble<T> & autre) const;
		
		// Affiche les éléments d'un Ensemble, entre 2 accolades {}
		// et séparés par une virgule. Par exemple, {2,5,7,10}
		template <typename U>
		friend std::ostream& operator << (std::ostream& os, const Ensemble<U> & e);		

	/**************** Représentation ********************
	* 
	* Représentation interne de la classe Ensemble<T>,
	* vous n'avez pas le droit de la modifier ni d'y 
	* ajouter des variables.
	*
	*****************************************************/
	private:
    		Tableau<T> ens;
    		
    	
	/**************** Interface privée ******************
	* 
	* Vous pouvez ajouter toutes les fonctions privées
	* que vous estimez nécessaire.
	* N'oubliez pas de bien commenter vos fonctions, de 
	* bien utilisez le mot-clé const et de prendre en 
	* considération les bonnes pratiques.
	*
	*****************************************************/
};

/***** Fonctions publiques *****/

template <class T>
Ensemble<T>::Ensemble() {
}

template <class T>
Ensemble<T>::Ensemble(const Ensemble & autre) {
	// À compléter
}

template <class T>
Ensemble<T>::~Ensemble() {
}

template <class T>
bool Ensemble<T>::contient(const T & e) const {
	// À compléter
	return false;
}

template <class T>
int Ensemble<T>::taille() const {
	// À compléter
	return 0;
}

template <class T>
bool Ensemble<T>::inserer(const T & e) {
	// À compléter
	return false;
}

template <class T>
bool Ensemble<T>::enlever(const T & e) {
	// À compléter
	return false;
}

template <class T>
bool Ensemble<T>::operator == (const Ensemble<T> & autre) const {
	// À compléter
	return true;
}

template <class T>
Ensemble<T> & Ensemble<T>::operator = (const Ensemble<T> & autre) {
	// À compléter
	return nullptr;
}

template <class T>
Ensemble<T> Ensemble<T>::fusion(const Ensemble<T> & autre) const {
	// À compléter
	return nullptr;
}

template <class T>
Ensemble<T> Ensemble<T>::inter(const Ensemble<T> & autre) const {
	// À compléter
	return nullptr;
}

template <class T>
Ensemble<T> Ensemble<T>::minus(const Ensemble<T> & autre) const {
	// À compléter
	return nullptr;
}

template <typename U>
std::ostream& operator << (std::ostream& os, const Ensemble<U> & e) {
	// À compléter
	return os;
}

/***** Fonctions privées *****/

#endif
