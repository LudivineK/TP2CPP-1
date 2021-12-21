#define MAP 1

#include <iostream>
#include <typeinfo>
#include <cstring>
#include <string>

#include "Trajet.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "ListeTrajets.h"
#include "Menu.h"
#include "TrajetCompose.h"

using namespace std;



void testMenu() {
    Menu * m = new Menu();
    m->afficherMenu();
    delete m;
}

int main()
{
    testMenu(); // exécution du programme
    
    return 0;
}