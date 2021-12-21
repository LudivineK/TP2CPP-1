/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Menu> (fichier Menu.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
//------------------------------------------------------ Include personnel
#include "Menu.h"

//------------------------------------------------------------- Constantes
const unsigned int TAILLE_MAX_NOM_VILLE = 40 + 1;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Menu::afficherMenu()
{
    string choix;
    do
    {
        cout << "-------------- MENU --------------" << endl;
        cout << "1 : Ajouter un trajet au catalogue" << endl;
        cout << "2 : Rechercher un trajet dans le catalogue" << endl;
        cout << "3 : Afficher le catalogue" << endl;
        cout << "4 : Supprimer un trajet" << endl;
        cout << "Veuillez entrer votre choix (q pour quitter) : ";
        cin >> choix;
        while (choix.compare("1") != 0 && choix.compare("2") != 0 && choix.compare("3") != 0 && choix.compare("4") != 0 && choix.compare("q") != 0)
        {
            cout << "Choix incorrect. Choix possibles : 1, 2, 3, 4, q. Choix : ";
            cin >> choix;
        }
        if (choix.compare("1") == 0)
        {
            ajouterTrajet();
        }
        else if (choix.compare("2") == 0)
        {
            rechercher();
        }
        else if (choix.compare("3") == 0)
        {
            afficherCatalogue();
        }
        else if (choix.compare("4") == 0)
        {
            supprimerTrajet();
        }

    } while (choix.compare("q") != 0);
}

TrajetSimple *Menu::saisirTS(std::string ville_depart)
{
    std::string depart ="", arrivee="", moyenTransport="";
    cout << ">> SAISIE D'UN TRAJET SIMPLE" << endl;
    cout << "Ville de départ : ";
    if (ville_depart.compare("") == 0)
    {
        cin >> depart;
    }
    else
    {
        depart = ville_depart;
        cout << ville_depart << endl;
    }
    cout << "Ville d'arrivée : ";
    cin >> arrivee;
    cout << "Moyen de transport : ";
    cin >> moyenTransport;
    TrajetSimple *t = new TrajetSimple(depart, arrivee, moyenTransport);
    return t;
}

TrajetCompose *Menu::saisirTC()
{
    std::string depart, arrivee, mTransport, derniereVille;
    
    TrajetCompose *trajet;
    TrajetSimple *ts;

    int nbTrajets = 1;

    cout << ">> SAISIE D'UN TRAJET COMPOSE" << endl;
    cout << "Ville de départ : ";
    cin >> depart;
    cout << "Ville d'arrivée : ";
    cin >> arrivee;
    trajet = new TrajetCompose(depart, arrivee);
    derniereVille = depart;
    cout << "Saisie des sous-trajets (jusqu'à arriver à " << arrivee << ") : " << endl;
    do
    {
        cout << "> Veuillez saisir les informations du sous-trajet " << nbTrajets << endl;
        ts = saisirTS(derniereVille);
        derniereVille = ts->getArrivee();
        trajet->ajouterTrajet(ts);
        nbTrajets++;
    } while (derniereVille != arrivee);
    return trajet;
}

void Menu::rechercher()
{
    string choix = "", depart = "", arrivee = "";
    cout << "Quelle recherche souhaitez-vous effectuer ? Simple ou Avancée ? (s/a) ";
    cin >> choix;
    while (choix.compare("a") != 0 && choix.compare("s") != 0)
    {
        cout << "Choix incorrect. Choix possibles : a, s. Choix : ";
        cin >> choix;
    }
    cout << "Ville de départ : ";
    cin >> depart;
    cout << "Ville d'arrivée : ";
    cin >> arrivee;

    if(choix.compare("s") == 0)
    {
        c->rechercheSimple(depart, arrivee);
    }
    else
    {
        cout << "Pas pour le moment" << endl;
        // c->rechercheAvancee(depart, arrivee);
    }
}

void Menu::afficherCatalogue()
{
    c->afficher();
}
void Menu::ajouterTrajet()
{
    string choix;

    cout << "Souhaitez-vous ajouter un trajet simple (s) ou composé (c) ? (s/c) Choix : ";
    cin >> choix;
    while (choix.compare("s") && choix.compare("c"))
    {
        cout << "Choix incorrect. Choix possibles : s, c. Choix : ";
        cin >> choix;
    }
    if (choix.compare("s") == 0)
    {
        c->ajouterTrajet(saisirTS());
    }
    else
    {
        c->ajouterTrajet(saisirTC());
    }
}

void Menu::supprimerTrajet()
{

    afficherCatalogue();
    if (c->getTaille() == 0)
    {
        cout << "Il n'y a pas de trajet à supprimer" << endl;
        return;
    }
    int i;
    cout << "Entrez le numéro du trajet à supprimer : ";
    cin >> i;
    if (i > 0 && i < c->getTaille() + 1)
    {
        c->supprimerTrajet(i - 1);
        cout << "Le trajet a été supprimé du catalogue" << endl;
    }
    else
        cout << "L'indice entré ne correspond à aucun trajet du catalogue" << endl;
}
//-------------------------------------------- Constructeurs - destructeur

Menu::Menu()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Menu>" << endl;
#endif
    c = new Catalogue();
} //----- Fin de Menu

Menu::~Menu()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Menu>" << endl;
#endif
    delete c;
} //----- Fin de ~Menu

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
