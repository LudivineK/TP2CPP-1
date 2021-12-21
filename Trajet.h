/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//  Cette classe modélise un trajet de façon abstraite (elle ne peut pas être instanciée).
//  Un trajet possède une ville d'arrivée et une ville de départ.
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    virtual void afficherTrajet() const;
    // Mode d'emploi :
    //  Affiche les informations du trajet (ville départ, ville arrivée).
    // Contrat :
    //  Aucun.

    virtual bool estEgal(Trajet *t);
    // Mode d'emploi :
    //  Permet de tester si deux trajets sont égaux, à partir des informations telles que
    //  les villes d'arrivée et de départ, ainsi que toutes les étapes intermédiaires.
    //  Deux trajets sont égaux s'ils comportent strictement toutes les mêmes étapes et les mêmes
    //  moyens de transport.
    // Contrat :
    //  Le paramètre `t` ne doit pas pointer le même trajet que `this`.

    std::string const getDepart() const;
    // Mode d'emploi :
    //  Donne la ville de départ du trajet.
    // Contrat :
    //  Aucun.

    std::string const getArrivee() const;
    // Mode d'emploi :
    //  Donne la ville d'arrivée du trajet.
    // Contrat :
    //  Aucun.

    virtual std::string getType() ;
    // Mode d'emploi :
    //  
    // Contrat :
    //  Aucun.

    virtual const std::string writeFile() const;

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Trajet(std::string depart, std::string arrivee);
    // Mode d'emploi :
    //  Crée un trajet à partir des paramètre : depart (ville de départ), arrivee (ville d'arrivée).
    // Contrat :
    //  La ville de départ et d'arrivée ne devraient pas être les mêmes.

    Trajet(const Trajet &unTrajet);
    // Mode d'emploi :
    //  Crée un trajet à partir des paramètre : depart (ville de départ), arrivee (ville d'arrivée).
    // Contrat :
    //  La ville de départ et d'arrivée ne devraient pas être les mêmes.

    virtual ~Trajet();
    // Mode d'emploi :
    //  Détruit l'objet et ses chaines de caractères.
    // Contrat :
    //  Aucun.

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    std::string depart;
    std::string arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
