/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:08:44 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/03/15 15:47:47 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_numbers(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' && av[i][j])
				j++;
			if (av[i][j] == '\0')
				break;
			if ((av[i][j] < '0' || av[i][j] > '9') && (av[i][j] != '-'
					&& av[i][j] != '+'))
			{
				ft_printf("Error\nIl ne doit y avoir que des numero ou signe '-' '+'.\n");
				return (1);
			}
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				j++;
				if ((av[i][j] < '0' || av[i][j] > '9'))
				{
					ft_printf("Error.\nPut digit after the sign.\n");
					return (1);
				}
				j--;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int check_doublon(char **av)
{
	char cmp;
	int i;
	int j;
	int k;
	
	
	i = 1;
	k = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][k] == ' ')
				k++;
			while (j == k && av[i][j] == ' ' && av[i][j])
				j++;
			cmp = av[i][k];
			while (j == k && av[i][j] == ' ' && av[i][j])
				j++;
			
			ft_printf("%d %d\n", j, k);
			if (cmp == av[i][j])
			{
				ft_printf("Error\nThere is duplicate number\n");
				return (1);
			}
			j++;
		}
		// ft_printf("%c\n", av[i][j]);
		k++;
		i++;
		
	}
	return (0);
}
