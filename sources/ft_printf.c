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

static char			*ft_printbuf(t_print *pf, const char *start, const char *stop)
{
	size_t len;

	len = (stop - start);
	write(1, start, len);
	pf->res_len += len;
	return ((char*)start + len);
}

static char		*ft_parser(t_print *pf, char *frm)
{
	int id;

	ft_reset_pf(pf);
	pf->tfrm = frm + 1;
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
		{
			ft_printbuf(pf, pf->tfrm, frm);
			frm = ft_parser(pf, (char*)frm);
		}
		else
			frm++;
	}
	ft_printbuf(pf, pf->tfrm, frm);
	va_end(pf->initarg);
	va_end(pf->arg);
	return (pf->res_len);
}

