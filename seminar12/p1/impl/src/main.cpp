#include <iostream>
#include "Agenda.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"


int main(int argc, char** argv)
{
    Agenda agenda;

    class Prieten g;
    g.set_adresa("La mama cucului");
    g.set_nume("Gigi muschi");

    agenda.add_contact(&g);


    return 0;
}
