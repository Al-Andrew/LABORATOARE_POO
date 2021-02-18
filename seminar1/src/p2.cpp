#include <cstdio>
#include <cstdlib>
#include <cstring>


int scruffy_atoi(const char* input)
{
    unsigned int len = strlen(input);
    int sol = 0;
    for(unsigned int i = 0; i < len ; ++i )
    {
        if( input[i] >= '0' && input[i] <= '9')
        {
            sol = sol * 10 + (input[i] - '0');
        }
    }
    return sol;
}


int main(int argc, char** argv)
{
    char nr[128];
    FILE* fisier;
    int suma = 0;
    //!! THIS CAN BE NULL
    fopen_s(&fisier, "ini.txt", "r");
    while( fisier != NULL && !feof(fisier) )
    {
        fgets(nr, 127, fisier);
        //TODO : add whitespace trimming
        suma += scruffy_atoi(nr);
    }
    printf("%d", suma );
}