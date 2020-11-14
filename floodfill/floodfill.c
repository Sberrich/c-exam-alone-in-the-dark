#include "point.h"

void fill(char **tab,int x, int y, t_point prev,t_point size)
{
    if(x >= 0 || x < size || y >= 0 || y < size || tab[y][x] != prev)
        return;
    fill(tab,x - 1,y,prev,size);
    fill(tab,x + 1,y,prev,size);
    fill(tab,x,y - 1,prev,size);
    fill(tab,x,y + 1,prev,size);
}
void floodfill(char **tab,t_point prev,t_point size)
{
    char prev = tab[begin.y][begin.x];
    fill(tab,begin.x,begin.y,prev,size);
}