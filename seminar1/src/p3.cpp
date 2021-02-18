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

// ? Simple bubble sort
// TODO:: make this a better sorting algorithm and make it [[noexcept]]
void sort(char *cuvinte[128][32], unsigned int wordc)
{
    bool done = false;
    while(!done)
    {
        done = true;
        for(unsigned int i = 0; i < wordc - 1; ++i)
        {
            if(strlen((*cuvinte)[i]) < strlen((*cuvinte)[i+1]))
            {
                char *tmp = (*cuvinte)[i];
                (*cuvinte)[i] = (*cuvinte)[i+1]; 
                (*cuvinte)[i+1] = tmp;
                done = false;
            }
            else if (strlen((*cuvinte)[i]) == strlen((*cuvinte)[i+1]) && strcmp( (*cuvinte)[i],(*cuvinte)[i+1]) > 0)
            {
                char *tmp = (*cuvinte)[i];
                (*cuvinte)[i] = (*cuvinte)[i+1]; 
                (*cuvinte)[i+1] = tmp;
                done = false;
            }
        }
    }
}


int main(int argc, char** argv)
{
    char propozitie[256];
    scanf_s("%[^\n]s", propozitie);
    char *cuvinte[32];
    int word_c = split(propozitie, " ", &cuvinte);
    sort(&cuvinte, word_c);

    for(unsigned int i = 0 ; i < word_c; ++i)
    {
        puts(cuvinte[i]);
    }
}