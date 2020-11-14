#include <unistd.h>
#include <stdlib.h>

void print_memory(const void *addr, size_t size)
{
    size_t i;
    size_t j;
    unsigned char *p;
    char *str;

    str = "0123456789abcdef";
    p = (unsigned char *)addr;
    i = 0;

    while (i < size)
    {
        j = 0;
        while (j < 16 && j + i < size)
        {
            write(1,&str[(*(p + i + j) / 16) % 16],1);
            write(1,&str[(*(p + i + j) % 16)],1);

            if(j % 2)
            {
                write(1," ",1);
            }
            j++;
        }
        while (j < 16)
        {
            write(1,"  ",2);
            if(j % 2)
            {
                write(1," ",1);
            }
            j++;
        }
        j = 0;
        while (j < 16 && j + i < size)
        {
            if(*(p + i + j) >= 32 && *(p + i + j) < 127)
            {
                write(1,p + i + j,1);
            }else{
                write(1,".",1);
            }
            j++;
        }
        write(1,"\n",1);
        i+=16;   
    }   
}
int	main(void)
{
		int	tab[10] = {0, 23, 150, 255,
			              12, 16,  21, 42};

						  	print_memory(tab, sizeof(tab));
								return (0);
}
/* SUBJECT 

Assignment name  : print_memory
Expected files   : print_memory.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes (const void *addr, size_t size), and displays the
memory as in the example.

Your function must be declared as follows:

void	print_memory(const void *addr, size_t size);

---------
$> cat main.c
void	print_memory(const void *addr, size_t size);

int	main(void)
{
		int	tab[10] = {0, 23, 150, 255,
			              12, 16,  21, 42};

						  	print_memory(tab, sizeof(tab));
								return (0);
}
$> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e
0000 0000 1700 0000 9600 0000 ff00 0000 ................$
0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$
0000 0000 0000 0000                     ........$

*/