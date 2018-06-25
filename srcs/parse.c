/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:03:18 by daugier           #+#    #+#             */
/*   Updated: 2018/06/07 03:05:07 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/computor_v1.h"

int				count_exposant(char *av)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (av[++i])
	{
		if (av[i] == '^' && ft_atoi(av + (i + 1)) > count)
			count = ft_atoi(av + (i + 1));
	}
	return (count);
}

char			*ft_init_tab(double *x, int number)
{
	int		i;
	char 	*tmp;

	i = -1;
	if (!(tmp = (char *)malloc(sizeof(char) * number + 2)))
		exit(0);
	while (++i <= number)
	{
		tmp[i] = 'u';
		x[i] = 0;
	}
	tmp[i] = '\0';
	return (tmp);
}

int				stock_exposant(char *av, int i, double *x, int end, char *str)
{
	double	tmp;
	int		neg;

	neg = 1;
	if (i != 0)
	{
		if (av[i] == '-')
			neg = -1;
		i++;
	}
	tmp = ft_atof(av + i);
	tmp *= (end * neg);
	while (av[i] != '^' && av[i])
		i++;
	i++;
	str[ft_atoi(av + i)] = 'i';
	x[ft_atoi(av + i)] += tmp;
	if (av[i + 1] != '\0')
		return (i + 1);
	return (i);
}

double			*parse_argument(char *av)
{
	double	*x;
	int		i;
	int		end;
	int		count;
	char	*tmp;

	i = -1;
	end = 1;
	count = count_exposant(av);
	if (!(x = (double *)malloc(sizeof(double) * count + 1)))
		exit(0);
	tmp = ft_init_tab(x, count);
	while (av[++i])
	{
		if (av[i] == '=')
			end = -1;
		i = stock_exposant(av, i, x, end, tmp);
	}
	display(x, count, tmp);
	return (x);
}
