/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//  Cette classe modélise un trajet composé. Les trajets composés sont une sorte de Trajet. 
//  Ils sont composés de sous-trajets de type TrajetSimple. La classe TrajetCompose modélise
//  en fait un trajet ayant des étapes.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void afficherTrajet() const;
    // Mode d'emploi :
    //  Affiche un trajet (ville de départ, arrivée) et les informations de tous ses sous-trajets.
    // Contrat :
    //  Aucun.

    void ajouterTrajet(Trajet *unTrajet);
    // Mode d'emploi :
    //  Ajoute un trajet comme étape de celui-ci.
    // Contrat :
    //  La cohérence du trajet n'est pas vérifiée ici. Par exemple si le trajet va de A vers B, et que les 
    //  étapes donc A->C puis C->D, c'est incohérent et cela ne doit pas arriver.

    std::string getType();
    // Mode d'emploi :
    //  Retourne "TrajetCompose".
    // Contrat :
    //  Aucun.

    bool estEgal (Trajet *t);
    // Mode d'emploi :
    //  Permet de tester si deux trajets sont égaux, à partir des informations telles que
    //  les villes d'arrivée et de départ, ainsi que toutes les étapes intermédiaires.
    //  Deux trajets sont égaux s'ils comportent strictement toutes les mêmes étapes et les mêmes
    //  moyens de transport.
    // Contrat :
    //  Le paramètre `t` ne doit pas pointer le même trajet que `this`.

    ListeTrajets getLT() const;

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    TrajetCompose(std::string depart, std::string arrivee);
    // Mode d'emploi :
    //  Crée un trajet composé à partir des paramètres : depart (ville de départ), arrivee (ville d'arrivée).
    // Contrat :
    //  Aucun.

    TrajetCompose(const TrajetCompose &unTrajetCompose);
    // Mode d'emploi :
    //  Crée un trajet composé à partir des paramètres : depart (ville de départ), arrivee (ville d'arrivée).
    // Contrat :
    //  Aucun.

    virtual ~TrajetCompose();
    // Mode d'emploi :
    //  Détruit le trajet, ainsi que tous ses sous-trajets.
    // Contrat :
    //  Aucun.

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    ListeTrajets *liste;

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H
