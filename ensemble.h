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
	ens = new Tableau<T>();
}

template <class T>
Ensemble<T>::Ensemble(const Ensemble<T> & autre) {
	ens = new Tableau<T>(*autre.ens);
}

template <class T>
Ensemble<T>::~Ensemble() {
	delete ens;
}

template <class T>
bool Ensemble<T>::contient(const T & e) const {
	for(int i = 0; i < ens->taille(); i++) {
		if((*ens)[i] == e) return true;
	}
	return false;
}

template <class T>
int Ensemble<T>::taille() const {
	return ens->taille();
}

template <class T>
bool Ensemble<T>::inserer(const T & e)
{
    if (!this->contient(e))
    {
        this->tab->ajouter(e);
        return true;
    }
    return false;
}

// template <class T>
// bool Ensemble<T>::enlever(const T & e)
// {
//     int index = -1;
//     for (int i = 0; i < this->taille(); i++)
//     {
//         if (this->tab->operator[](i) == e)
//         {
//             index = i;
//             break;
//         }
//     }
//     if (index != -1)
//     {
//         this->tab->enlever(index);
//         return true;
//     }
//     return false;
// }
template <class T>
bool Ensemble<T>::enlever(const T & e) {
	for(int i = 0; i < ens->taille(); i++) {
		if((*ens)[i] == e) {
			ens->enlever(i);
			return true;
		}
	}
	return false;
}

template <class T>
bool Ensemble<T>::operator == (const Ensemble<T> & autre) const {
	if(taille() != autre.taille()) return false;
	for(int i = 0; i < taille(); i++) {
		if(!autre.contient((*ens)[i])) return false;
	}
	return true;
}

template <class T>
Ensemble<T> & Ensemble<T>::operator = (const Ensemble<T> & autre) {
	delete ens;
	ens = new Tableau<T>(*autre.ens);
	return *this;
}

template <class T>
Ensemble<T> Ensemble<T>::fusion(const Ensemble<T> & autre) const {
	Ensemble<T> res = *this;
	for(int i = 0; i < autre.taille(); i++) {
		res.inserer((*autre.ens)[i]);
	}
	return res;
}

template <class T>
Ensemble<T> Ensemble<T>::inter(const Ensemble<T> & autre) const {
	Ensemble<T> res;
	for(int i = 0; i < ens.taille(); i++) {
		if(autre.contient((*ens)[i])) res.inserer((*ens)[i]);
	}
	return res;
}

template <class T>
Ensemble<T> Ensemble<T>::minus(const Ensemble<T> & autre) const {
	Ensemble<T> result;
	for(int i = 0; i < ens.taille(); i++) {
		if (!autre.contient((*ens)[i])) {
			result.ajouter((*ens)[i]);
		}
	}
	return result;
}

template <typename U>
std::ostream& operator << (std::ostream& os, const Ensemble<U> & e) {
    os << "{";
    for (unsigned int i = 0; i < this->ens.taille(); ++i) {
        os << ens[i];
        if (i < ens.taille() - 1) os << ", ";
    }
    os << "}";
    return os;
}

/***** Fonctions privées *****/

#endif
