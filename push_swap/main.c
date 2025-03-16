/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:11:16 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/03/15 15:15:36 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (check_if_numbers(av) == 1)
			return (1);
		if (check_doublon(av) == 1)
			return (1);
		else
			ft_printf("OK. Il n'y a pas de doublon.\n");
	}
	return (0);
}
