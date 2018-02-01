/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinandfree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:33:50 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:31:40 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
*** F_NONE -1
*** F_FIRST 0
*** F_LAST 1
*** F_BOTH 2
*/

char	*ft_joinfree(char const *s1, char const *s2, int flag)
{
	char *res;

	res = ft_strjoin(s1, s2);
	if (flag == 0 || flag == 2)
		ft_memdel(&s1);
	if (flag == 1 || flag == 2)
		ft_memdel(&s2);
	return (res);
}
