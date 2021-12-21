/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Trajet::afficherTrajet() const
{
    cout << "De " << depart << " à " << arrivee << endl;
}

bool Trajet::estEgal(Trajet *t)
{
    if(this->getDepart() == t->getDepart())
        return true;
    return false;
}

std::string Trajet::getType() {
    return "Trajet";
}

std::string const Trajet::getDepart() const
{
    return depart;
}
std::string const Trajet::getArrivee() const
{
    return arrivee;
}
const std::string Trajet::writeFile() const {
    return std::string(depart) +","+std::string(arrivee);
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet(std::string villeDepart, std::string villeArrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif

    depart = villeDepart;
    arrivee = villeArrivee;

} //----- Fin de Trajet

Trajet::Trajet(const Trajet &unTrajet) {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Trajet>" << endl;
    #endif
    depart = unTrajet.getDepart();
    arrivee = unTrajet.getArrivee();
}

Trajet::~Trajet()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
