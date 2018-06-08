/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:05:22 by daugier           #+#    #+#             */
/*   Updated: 2018/06/07 03:08:05 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/computor_v1.h"

double			ft_sqrt(double nbr)
{
	double		i;
	int			j;
	double		precision;

	i = 1;
	j = 0;
	precision = 100;
	if (nbr == 0.0 || nbr == 1.0)
		return (nbr);
	while (j < 9 && i * i != nbr)
	{
		while ((i * i) != nbr && (i * i) < nbr)
			i += precision;
		if ((i * i) != nbr)
		{
			i -= precision;
			precision /= 10;
		}
		j++;
	}
	return (i);
}

void			resolve_zero(double *x)
{
	if (x[0] == 0)
		ft_printf("Every real are solution.\n");
	else
		ft_printf("No solution.\n");
}

void			resolve_premier(double *x)
{
	double		result;

	result = 0;
	if (x[1] == 0)
	{
		if (x[0] == 0)
			ft_printf("Indeterminate equation.\n");
		else
			ft_printf("impossible equation.\n");
	}
	else
	{
		result = (-x[0]) / x[1];
		ft_printf("The solution is:\n%f\n", result);
	}
}

void			complexe_solution(double *x, double delta)
{
	double		resultat;
	double		i;

	resultat = 0;
	delta *= -1;
	i = 0;
	ft_printf("Discriminant is strictly negative, ");
	ft_printf("there is no solution in the real.\n");
	ft_printf("There are two complex solutions for this equation: \n");
	ft_printf("(-%f -i√%f) / 2 * %f\n", x[1], delta, x[2]);
	ft_printf("(-%f +i√%f) / 2 * %f\n", x[1], delta, x[2]);
	resultat = -x[1] / (2 * x[2]);
	i = ft_sqrt(delta) / (2 * x[2]);
	if (i == 1 || i == -1)
	{
		ft_printf("%f - i\n", resultat);
		ft_printf("%f + i\n", resultat);
	}
	else
	{
		ft_printf("%f - %fi\n", resultat, i);
		ft_printf("%f + %fi\n", resultat, i);
	}
}

void			resolve_second(double *x)
{
	int			i;
	double		delta;
	double		res;

	i = -1;
	delta = x[1] * x[1] - 4 * x[2] * x[0];
	if (delta < 0)
		complexe_solution(x, delta);
	else if (delta == 0)
	{
		ft_printf("Discriminant is equal has zero, the solution is:\n");
		ft_printf("%f\n", -(x[1] / (2 * x[2])));
	}
	else
	{
		ft_printf("Discriminant is strictly positive, the two solutions are:");
		res = (-x[1] - ft_sqrt(delta)) / (2 * x[2]);
		ft_printf("\n%f\n", res);
		res = (-x[1] + ft_sqrt(delta)) / (2 * x[2]);
		ft_printf("%f\n", res);
	}
}
