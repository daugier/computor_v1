/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor_v1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 10:04:30 by ddufour           #+#    #+#             */
/*   Updated: 2018/06/07 03:15:25 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_V1_H
# define COMPUTOR_V1_H

# include "../libft/libft.h"

double			*parse_argument(char *av);
void			display(double *x, int count);
void			resolve_second(double *x);
void			resolve_premier(double *x);
void			resolve_zero(double *x);

#endif
