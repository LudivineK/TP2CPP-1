/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeTrajets::reallouer() {
  Trajet** temp = new Trajet* [tailleMax * 2];

  /* On fait pointer chaque case du tableau temp sur l'instance de Trajet
  pointée par tab au même indice */

  for (int i = 0; i < this->taille; i++) {
			temp[i] = tab[i];
		}

		// Définition du reste des pointeurs à NULL

		for (int i = taille; i < tailleMax * 2; i++) {
			temp[i] = NULL;
		}

		// On supprime le tableau tab, mais pas les instances de Trajet qu'il contient !

		delete[] tab;

		// On change la valeur max de l'instance de tableau de trajets courante

		this->tailleMax = 2 * tailleMax;

		// On fait pointer l'attribut tab vers temp.

		tab = temp;
    delete[] temp;
}

bool ListeTrajets::ajouter(Trajet *unTrajet)
{
  	if(!(taille < tailleMax)) {
			reallouer();
		}

		tab[taille] = unTrajet;
		taille++;
    return true;
} // fin ajouter

void ListeTrajets::afficher() {
    if(taille == 0) {
      cout << "La liste est vide" << endl;
    }

		for (int i = 0; i < taille; i++) {
			tab[i]->afficherTrajet();
		}
	} // fin afficher

void ListeTrajets::supprimerTrajet(int i)
// Algorithme
// On supprime le trajet à l'emplacement i - 1 (si l'utilisateur veut
// supprimer le premier trajet, ce sera le trajet à l'emplacement tab[0])
// et on déplace les trajets de i à taille - 1 de une case vers la gauche
{
  cout << "Coucou" << endl;
  delete tab[i];
  cout << "Coucou2" << endl;

  if(i > 1)
    for(int j = i; j < taille; j++) 
      tab[j - 1] = tab[j];

  tab[taille - 1] = NULL;
  taille--;
}

/*void ListeTrajets::supprimerTrajetRecherche(uint index) 
{
  ListeTrajets *head = this;
  ListeTrajets *temp = head;
  ListeTrajets *prev = nullptr;
  if (head != nullptr && index == 0)
  {
    if (head->trajetSuivant == nullptr)
    {
      head->trajet = nullptr;
      taille--;
      return;
    }
    temp = head->trajetSuivant;
    head->trajet = temp->trajet;
    head->trajetSuivant = temp->trajetSuivant;
    temp->trajet = nullptr;
    temp->trajetSuivant = nullptr;
    delete temp;
  }
  else
  {
    while (temp != nullptr && index--)
    {
      prev = temp;
      temp = temp->trajetSuivant;
    }
    if (temp == nullptr)
      return;

    prev->trajetSuivant = temp->trajetSuivant;
    delete temp;
  }

  while (head != nullptr)
  {
    head->taille--;
    head = head->trajetSuivant;
  }
}

void ListeTrajets::vider()
{
  // on souhaite casser les pointeurs sans supprimer les trajets...
  if (trajet != nullptr)
  {
    trajet = nullptr;
  }
  if (trajetSuivant != nullptr)
  {
    trajetSuivant->vider();
  }
}*/

//------------------------------------------------------ Getters - setters

int ListeTrajets::getTaille() const
{
  return taille;
}

int ListeTrajets::getTailleMax() const
{
  return tailleMax;
}

Trajet *ListeTrajets::getElement(int i) const
{
  return tab[i];
}

//-------------------------------------------- Constructeurs - destructeur

ListeTrajets::ListeTrajets() : tailleMax(TAILLEMAX), taille(0)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif

  tab = new Trajet*[tailleMax];

	// Initialisation des pointeurs à NULL 

	for (int i = 0; i < tailleMax; i++) {
		tab[i] = NULL;
	}
} //----- Fin de ListeTrajets

ListeTrajets::ListeTrajets(const ListeTrajets &uneListeTrajets)
// Algorithme :
// Instancie une liste de trajets. Pour chaque case, il instancie un 
// nouveau trajet, qui va utiliser le constructeur de copie de la classe
// Trajet. 
{
#ifdef MAP
		cout << "Appel au constructeur de copie de <ListeTrajets>" << endl;
#endif

  taille = uneListeTrajets.getTaille();
  tailleMax = uneListeTrajets.getTailleMax();

  tab = new Trajet*[tailleMax];

  for(int i = 0; i < taille; i++) {
    tab[i] = new Trajet(*(uneListeTrajets.getElement(i)));
  }

  for(int i = taille; i < tailleMax; i++) {
    tab[i] = NULL;
  }
} //----- Fin du constructeur de copie de ListeTrajets

ListeTrajets::~ListeTrajets()
// Algorithme :
// On delete les éléments présents dans le tableau (sauf les cases set
// à NULL). On supprime ensuite le tableau lui-même. 
{
#ifdef MAP
  cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif
  
  for (int i = 0; i < taille; i++) {
		delete tab[i];
	}

	delete[] tab;
}

//----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
