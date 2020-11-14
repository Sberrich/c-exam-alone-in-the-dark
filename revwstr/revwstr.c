#include <unistd.h>

int main(int ac,char **av)
{
    int i;
    int j;
    int nbr;
    char words[256][4096];

    if(ac == 2)
    {
        i = 0;
        nbr = 0;
        j = 0;
        while (av[1][i] != '\0')
        {
            if(av[1][i] == ' ')
            {
                nbr++;
                i++;
                j = 0;
            }
            words[nbr][j] = av[1][i];
            i++;
            j++;
        }
        j = 0;
        while(nbr >= 0)
        {
            if(words[nbr][j] == '\0')
            {
                if(nbr > 0)
                {
                    write(1," ",1);
                }
                if(nbr == 0 && words[nbr][j] == '\0')
                {
                    break;
                }
                nbr--;
                j = 0;
            }
            write(1,&words[nbr][j++],1);
        }
    }
    write(1,"\n",1);
    return (0);
}
