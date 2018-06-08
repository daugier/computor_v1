/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:01:44 by daugier           #+#    #+#             */
/*   Updated: 2018/06/07 03:01:47 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// REVOIR COMMENT ARRONDIR LE FLOAT DANS LA FONCTION FT_FTOA
// VOIRE COMMENT FAIRE POUR REDUIRE L'OPERATION EN AFFICHANT QUAND MEME UNE PUISSSANCE MEME SI TOUS LES NOMBRES SONT A ZERO

#include "../header/computor_v1.h"

int			main(int ac, char **av)
{
	if (ac < 2)
		ft_printf("no operation done");
	else if (ac > 3)
		ft_printf("too much parameters done");
	else
		parse_argument(av[1]);
	return (0);
}
