/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:11:16 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/03/14 17:25:21 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (check_if_numbers(av) == 1)
			return (1);
	}
	else
		ft_printf("Error\nVeuilez entrer 2 arguments minimum.\n");
	ft_printf("ok\n");
	return (0);
}
