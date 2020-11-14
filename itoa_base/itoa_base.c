#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *itoa_base(int value,int base)
{
    int i = 0;
    long nbr;
    char *baser = "0123456789ABCDEF";
    char *p;

    if(value == 0)
    {
        return(0);
    }
    nbr = value;
    while(nbr)
    {
        nbr /= base;
        i++;
    }
    nbr = value;
    while (nbr < 0)
    {
        if(base == 10)
        {
            i++;
        }
        nbr *= -1;
    }
    
    if(!(p = (char *)malloc(sizeof(char) * i + 1)))
    {
        return(NULL);
    }
    p[i] = '\0';
    while (nbr)
    {
        p[--i] = baser[nbr % base];
        nbr /= base;
    }
    if(value < 0 && base == 10)
    {
        p[0] = '-';
    }
    return(p);
}
int main()
{
    printf("%s",itoa_base(-4,2));
    return(0);
}