/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : novembre 2021
    copyright            : (C) 2021 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Menu> (fichier Menu.h) ----------------
#if !defined(MENU_H)
#define MENU_H

//--------------------------------------------------- Interfaces utilisées
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Menu>
//  Cette classe gère l'interface graphique du logiciel. Elle propose les différentes options possibles et appelle
//  les méthodes des différentes classes correspondantes.
//------------------------------------------------------------------------

class Menu
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void afficherMenu();
    // Mode d'emploi :
    //  Affiche le menu. Cette méthode doit être appelée pour utiliser le Menu dans la console.
    // Contrat :
    //  Aucun.
    
    TrajetSimple *saisirTS(const std::string villeDepart = "");
    // Mode d'emploi :
    //  Permet de saisir un trajet simple dans la console.
    //  Le paramètre ville_depart permet de préciser une ville de départ prédéfinie, qui ne sera
    //  donc pas demandée à l'utilisateur.
    // Contrat :
    //  Aucun.

    TrajetCompose *saisirTC();
    // Mode d'emploi :
    //  Permet de saisir un trajet composé dans la console. 
    //  On demande la ville d'arrivée et de départ. Le trajet comporte forcément au moins un 
    //  sous-trajet. La ville de départ d'un sous-trajet est forcément la ville de départ du trajet
    //  composé (dans le cas du premier sous-trajet) ou la ville d'arrivée du sous-trajet précédent.
    //  Tant que l'utilisateur n'a pas entré de sous-trajet ayant pour ville d'arrivée la ville
    //  d'arrivée précisée au départ, on demande le sous-trajet suivant. 
    // Contrat :
    //  Aucun.

    void rechercher();
    // Mode d'emploi :
    //  Demande à l'utilisateur quel type de recherche il souhaite effectuer (simple ou avancée) et
    //  lui demande les paramètres de la recherche (ville départ, ville arrivée) avant d'effectuer la
    //  la recherche.
    // Contrat :
    //  Aucun.

    void afficherCatalogue();
    // Mode d'emploi :
    //  Affiche la liste des trajets composant le catalogue.
    // Contrat :
    //  Aucun.

    void ajouterTrajet();
    // Mode d'emploi :
    //  Permet d'ajouter un trajet au catalogue à partir de la console. 
    //  Toutes les informations sont saisies par l'utilisateur au cours de l'exécution de cette méthode.
    // Contrat :
    //  Aucun.

    
 void supprimerTrajet();
    // Mode d'emploi :
    //  Supprimer le ième trajet dans la liste des trajets. L'ordre est celui des entrées. 
    // Contrat :
    //  i est un entier supérieur ou égal à 1
    
    //-------------------------------------------- Constructeurs - destructeur

    Menu();
    // Mode d'emploi :
    //  Crée un menu vierge. 
    // Contrat :
    //  Aucun.

    virtual ~Menu();
    // Mode d'emploi :
    //  Détruit le Menu et son catalogue.
    // Contrat :
    //  Aucun.

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    Catalogue *c;
};

//-------------------------------- Autres définitions dépendantes de <Menu>

#endif // MENU_H
