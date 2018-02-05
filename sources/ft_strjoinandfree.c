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

char 	*ft_concatresbuf(t_print *pf)
{
	char	*res;

	res = ft_strmemcat(pf->res, pf->buf, pf->res_len, pf->buf_len);
	return (res);
}

char 	*ft_strmemcat(char *s1, char *s2, int s1len, int s2len)
{
	char	*res;

	res = ft_strnew(s1len + s2len);
	ft_memcpy(res, s1, s1len);
	ft_memcpy(&res[s1len], s2, s2len);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (res);
}
