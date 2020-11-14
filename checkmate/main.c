/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:13:23 by sberrich          #+#    #+#             */
/*   Updated: 2020/02/09 18:10:02 by sberrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
int ft_Rock(char **av, int i, int j, int size)
{
	int x;
	int y;

	x = i;
	y = j;
	while (j < size)
	{
		if (av[i][j] == 'P' || av[i][j] == 'B')
			break;
		if (av[i][j] == 'K')
			return 1;
		j++;	

	}
	j = y;
	while (j >= 0)
	{
		if (av[i][j] == 'P' || av[i][j] == 'B')
			break;
		if (av[i][j] == 'K')
			return 1;
		j--;	

	}
	j = y;
	while (i >= 0)
	{
		if (av[i][j] == 'P' || av[i][j] == 'B')
			break;
		if (av[i][j] == 'K')
			return 1;
		i--;	

	}
	i = x;
	while (i < size)
	{
		if (av[i][j] == 'P' ||av[i][j] == 'B')
			break;
		if (av[i][j] == 'K')
			return 1;
		i++;	
	}
	return(0);
}

int ft_Bishop(char **av, int i, int j, int size)
{
	int x;
	int y;

	x = i;
	y = j;
	while (j < size && i < size)
	{
		if (av[i][j] == 'P' ||av[i][j] == 'R')
			break;
		if (av[i][j] == 'K')
			return 1;
		j++;
		i++;	

	}
	j = y;
	i = x;
	while (j >= 0 && i >= 0)
	{
		if (av[i][j] == 'P' ||av[i][j] == 'R')
			break;
		if (av[i][j] == 'K')
			return 1;
		j--;	
		i--;
	}
	j = y;
	i = x;
	while (i >= 0 && j < size)
	{
		if (av[i][j] == 'P' ||av[i][j] == 'R')
			break;
		if (av[i][j] == 'K')
			return 1;
		j++;
		i--;	

	}
	i = x;
	j = y;
	while (i < size && j > 0)
	{
		if (av[i][j] == 'P' ||av[i][j] == 'R')
			break;
		if (av[i][j] == 'K')
			return 1;
		i++;
		j--;	
	}
	return(0);


}

int ft_Pawns(char **av,int i, int j, int size)
{
	if (i - 1 >= 0 && j - 1 >= 0)
	{
		if(av[i - 1][j - 1] == 'K')
		{
			return (1);
		}
	}
	if (i + 1 > 0 && j + 1 < size)
	{
		if(av[i - 1][j - 1] == 'K')
		{
			return (1);
		}
	}
	return(0);
}
int ft_Queen(char **av,int i, int j, int size)
{
	if (ft_Bishop(av,i,j,size) || ft_Pawns(av,i,j,size) || ft_Rock(av,i,j,size))
	{
		return (1);
	}
	return (0);
}
int main(int ac, char **av)
{
	int i;
	int j;
	int size;
	int a;

	a = 0;
	size = ft_strlen(av[1]);

		if (ac >= 2)
		{
			i = 0;
			while (i <= size)
			{
				j = 0;
				while (j <= size)
				{
					if (av[i][j] == 'R')
					{
						if ((a = ft_Rock(av, i, j, size)))
							write(1, "SUCCESS\n", 8);
					}
					if (av[i][j] == 'B')
						if ((a = ft_Bishop(av, i, j, size)))
							write(1, "SUCCESS\n", 8);
					if (av[i][j] == 'P')
						if ((a = ft_Pawns(av, i, j, size)))
							write(1, "SUCCESS\n", 8);
					if (av[i][j] == 'Q')
						if ((a = ft_Queen(av, i, j, size)))
							write(1, "SUCCESS\n", 8);
					j++;
				}
				i++;
			}
			if (a == 0)
			{
				write(1, "Fail\n", 5);
			}
		}
	
}
