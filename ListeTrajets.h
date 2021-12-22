/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : novembre 2021
    copyright            : (C) 2021 par Malek Mahjoub et Aurélie Abraham
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if !defined(LISTETRAJETS_H)
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes
const int TAILLEMAX = 2;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//  Classe permettant de définir une structure de données de type tableau.
//  Cette classe stocke des éléments de type Trajet.
/* Fonctionnement général :
  Cette classe stocke des Trajets dans un tableau. 
  Il existe une méthode pour rajouter de l'espace au tableau dans le cas où 
  il n'y a plus de place. 
*/
//------------------------------------------------------------------------

class ListeTrajets
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  
  void reallouer();
  // Mode d'emploi :
  //  Quand la taille du tableau est égale à sa taille maximum, on recréé un 
  // tableau, on fait pointer les éléments de ce tableau vers les éléments
  // du précédent tableau, et on supprime la structure de l'ancien tableau. 
  // Contrat :
  //  Aucun.

  int getTaille() const;
  // Mode d'emploi :
  //  Donne la taille courante du tableau (nombre de trajets qu'il contient).
  // Contrat :
  //  Aucun.

  int getTailleMax() const;
  // Mode d'emploi :
  //  Donne la taille maximum du tableau (nombre de trajets qu'elle PEUT contenir).
  // Contrat :
  //  Aucun.

  virtual bool ajouter(Trajet *);
  // Mode d'emploi :
  //  Permet d'ajouter un trajet passé en paramètre à la liste.
  // Contrat :
  //  Aucun.

  virtual void afficher();
  // Mode d'emploi :
  //  Affiche la liste, en affichant le détail de chaque trajet qui la compose.
  // Contrat :
  //  Aucun.

  Trajet *getElement(int i) const;
  // Mode d'emploi :
  //  Donne l'élément situé à la position i du tableau.
  // Contrat :
  //  Aucun.

  virtual void supprimerTrajet(int i);
  // Mode d'emploi :
  //  Supprime le trajet situé à la position i du tableau. Déplace les éléments situés après
  // i d'une case en arrière pour qu'il n'y ait pas de case vide.
  // Contrat :
  //  index doit être un entier positif ou nul, inférieur strictement à la taille de la liste.

  //-------------------------------------------- Constructeurs - destructeur

  ListeTrajets();
  // Mode d'emploi :
  //  Crée un objet ListeTrajets vierge.
  // Contrat :
  //  Aucun.

  ListeTrajets(const ListeTrajets &uneListeTrajets);
  // Mode d'emploi :
  //  Crée un objet ListeTrajets vierge.
  // Contrat :
  //  Aucun.

  virtual ~ListeTrajets();
  // Mode d'emploi :
  //  Détruit l'objet.
  // Contrat :
  //  Aucun.

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  
  int tailleMax;
  int taille;
  Trajet **tab; // Tableau de pointeurs de Trajet
};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // ListeTrajets_H
