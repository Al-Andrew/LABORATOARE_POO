#include <cstdio>
#include <cstdlib>
#include <cstring>


/*
 * @return the number of words split
*/
int split(char *propozitie, const char* delim, char *cuvinte[128][32])
{
    char* cuvant;
    char *next_token;
    cuvant = strtok_s(propozitie, delim, &next_token);
    unsigned int i = 0; 
    while(cuvant != NULL)
    {
        (*cuvinte)[i] = cuvant;
        i++;
        cuvant = strtok_s(NULL , delim, &next_token);
    }
    return i;
}


int main(int argc, char** argv)
{
    char propozitie[256];
    scanf_s("%[^\n]s", propozitie);
    char *cuvinte[32];
    split(propozitie, " ", &cuvinte);
}