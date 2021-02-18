#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char** argv)
{
    char propozitie[256];
    scanf("%[^\n]s", propozitie);
    char cuvinte[128][32];
    char *cuvant;
    cuvant = strtok( propozitie, " ");
    unsigned int i = 0;
    while( cuvant != NULL)
    {
        cuvinte[i] = cuvant;
        cuvant = strtok( propozitie, " ");
    }

    printf("%s",propozitie);
}