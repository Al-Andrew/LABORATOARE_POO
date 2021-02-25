#include <iostream>
#include "NumberList.h"

int main(int argc, char** argv)
{
    NumberList numere; // creeam un NumberList nou
    numere.Init(); // Apelam Init() pentru initializare
    numere.Print(); // Afisam lista ( nu pune \n la final)
    printf_s("\n"); 

    numere.Add(5); // Adaugam valori la lista
    numere.Add(13);
    numere.Add(1);
    numere.Print();
    printf_s("\n");

    numere.Add(-3); // Putem adauga valori negative
    numere.Sort(); // Sortam lista de numere
    numere.Print();
    printf_s("\n");
}
