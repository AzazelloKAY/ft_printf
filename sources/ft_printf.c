/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 22:36:31 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:37:23 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>//*******************

char			*ft_catbuf(t_print *pf, const char *start, const char *stop) //change to concat woth res_line
{
	size_t len;

	len = (stop - start);
	//заменить на мемсопи
	//pf->res = ft_joinfree(pf->res, ft_strsub(start, 0, len), F_BOTH);
	pf->res = ft_strmemcat(pf->res, ft_strsub(start, 0, len), pf->res_len, len);
	pf->res_len += len;
	return ((char*)start + len);
}

static char		*ft_parser(t_print *pf, char *frm)
{
	int id;

	ft_reset_pf(pf);
	pf->tfrm = ft_catbuf(pf, pf->tfrm, frm) + 1;
	while (*pf->tfrm)
	{
		id = (ft_isprint(*pf->tfrm)
			  && (pf->flist[*pf->tfrm] != NULL)) ? *pf->tfrm : 0;
		if (pf->flist[id](pf))
		{
			pf->tfrm++;
			break;
		}
		pf->tfrm++;
	}
	return (pf->tfrm);
}

int				ft_printf(const char *frm, ...)
{
	t_print	*pf;

	if (!(pf = ft_init_pf(frm)))
		return (-1);
	va_start(pf->initarg, frm);
	va_copy(pf->arg, pf->initarg);
	while (*frm)
	{
		if (*frm == '%')
			frm = ft_parser(pf, (char*)frm);
		else if (*frm == '{')
		{
			pf->tfrm = ftpf_color(pf, frm);
			frm = pf->tfrm + 1;
		}
		else
			frm++;
	}
	ft_catbuf(pf, pf->tfrm, frm);
	write(1, pf->res, pf->res_len);
	va_end(pf->initarg);
	va_end(pf->arg);
	return (pf->res_len);
}

