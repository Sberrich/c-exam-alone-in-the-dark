#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i;
    int count;
    char *ptr;

    if(ac == 2)
    {
        i = 0;
        if(!(ptr = (char *)malloc(sizeof(char) * 2048)))
        {
            return(0);
        }
        while (av[1][i])
        {
            av[1][i] == '>' ? ptr++ : ptr;
            av[1][i] == '<' ? ptr-- : ptr;
            av[1][i] == '+' ? (*ptr)++ : *ptr;
            av[1][i] == '-' ? (*ptr)-- : *ptr;
            if(av[1][i] == '.')
            {
                write(1,ptr,1);
            }
            i++;
            if(av[1][i] == '[' && !(*ptr))
            {
                count = 1;
                while(count)
                {
                    i++;
                    if(av[1][i] == '[')
                    {
                        count++;
                    }
                    if(av[1][i] == ']')
                    {
                        count--;
                    }
                }
            }
            if(av[1][i] == ']' && (*ptr))
            {
                count = 1;
                while(count)
                {
                    i--;
                    if(av[1][i] == '[')
                    {
                        count--;
                    }
                    if(av[1][i] == ']')
                    {
                        count++;
                    }
                }
            }
        }
    }
    else
    {
    write(1,"\n",1);
        /* code */
    }
    
    return(0);
}


/* SUBJECT
Assignment name  : brainfuck
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a Brainfuck interpreter program.
The source code will be given as first parameter.
The code will always be valid, with no more than 4096 operations.
Brainfuck is a minimalist language. It consists of an array of bytes
(in our case, let's say 2048 bytes) initialized to zero,
and a pointer to its first byte.

Every operator consists of a single character :
- '>' increment the pointer ;
- '<' decrement the pointer ;
- '+' increment the pointed byte ;
- '-' decrement the pointed byte ;
- '.' print the pointed byte on standard output ;
- '[' go to the matching ']' if the pointed byte is 0 (while start) ;
- ']' go to the matching '[' if the pointed byte is not 0 (while end).

Any other character is a comment.

Examples:

$>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
Hello World!$
$>./brainfuck 
Hi$
$>./brainfuck | cat -e
$
*/