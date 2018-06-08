/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:02:06 by daugier           #+#    #+#             */
/*   Updated: 2018/06/07 03:02:08 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/computor_v1.h"

void			make_polynome(double *x, int degres)
{
	if (degres == 2)
		resolve_second(x);
	else if (degres == 1)
		resolve_premier(x);
	else if (degres == 0)
		resolve_zero(x);
}

void			aff_reduce_form(double *x, int count)
{
	int		i;

	i = -1;
	ft_printf("Reduced form: ");
	while (++i <= count)
	{
		if (i == 0)
			ft_printf("%f * X^%d ", x[i], i);
		else
		{
			if (x[i] < 0)
				ft_printf("- %f * X^%d ", x[i] * -1, i);
			else if (x[i] != 0)
				ft_printf("+ %f * X^%d ", x[i], i);
		}
	}
	ft_printf("= 0\n");
}

void			display(double *x, int count)
{
	int j;
	int degres;

	j = -1;
	degres = 0;
	aff_reduce_form(x, count);
	while (++j <= count)
	{
		if (x[j] != 0)
			degres = j;
	}
	ft_printf("Polynomial degree: %d\n", degres);
	if (degres > 2)
	{
		ft_printf("The polynomial degree is stricly greater ");
		ft_printf("than 2, I can't solve.\n");
	}
	else
		make_polynome(x, degres);
}
