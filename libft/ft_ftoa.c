/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:35:46 by daugier           #+#    #+#             */
/*   Updated: 2017/08/06 18:29:42 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define JOIN ft_strjoin

char		*ft_concat(double nbr, int neg, char *tmp)
{
	if (neg)
	{
		if (ft_strlen(tmp))
			return (JOIN(JOIN("-", JOIN(ft_itoa((int)nbr), ".")), tmp));
		else
			return (JOIN(JOIN("-", JOIN(ft_itoa((int)nbr), "\0")), tmp));
	}
	else
	{
		if (ft_strlen(tmp))
			return (JOIN(JOIN(ft_itoa((int)nbr), "."), tmp));
		else
			return (JOIN(JOIN(ft_itoa((int)nbr), "\0"), tmp));
	}
}

char		*ft_ftoa(double nbr)
{
	float	floating;
	char	*tmp;
	int		neg;
	int		precision;
	float	tmp_floating;

	precision = -1;
	if (!(tmp = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	tmp[0] = '\0';
	neg = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	floating = nbr - (int)nbr;
	while (floating > 0.00001 && ++precision < 6)
	{
		if ((floating = floating * 10) && ((int)(floating + 0.1) + '0') == ':')
			break ;
		tmp_floating = floating * 10;
		if (precision == 5 && (int)(tmp_floating) >= 5)
			floating = (int)floating + 1;
		tmp = ft_charjoin(tmp, ((int)(floating) + '0'));
		floating -= (int)floating;
	}
	return (ft_concat((int)nbr, neg, tmp));
}
