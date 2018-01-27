/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:46:09 by akokoshk          #+#    #+#             */
/*   Updated: 2018/01/18 19:46:18 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>//******************************

char			*ft_printbuf(t_print *pf, const char *start, const char *stop)
{

	size_t len;

	len = (stop - start);
	write(1, start, len);
	pf->res_len += len;
	return ((char*)start + len);
}

static char		*ft_parser(t_print *pf, char *frm)
{
	ft_reset_pf(pf);
	pf->tfrm = frm + 1;
	while (*pf->tfrm)
	{
		printf("%p", pf->flist[*pf->tfrm]);//?????????????????????????????????

		if (*pf->tfrm >= 32 && *pf->tfrm <= 127 && (pf->flist[*pf->tfrm] != NULL))
		{
			if (pf->flist[*pf->tfrm](pf))
			{
				pf->tfrm++;
				break;
			}
		}
		else
		{
			pf->flist[0](pf);
			break ;
		}
		pf->tfrm++;
	}
	//len = pf->tfrm - frm; //spec len, does it need in my code????????????????
	return (pf->tfrm); //return length of specificator and flags //or job status // speclen == pf->tfrm - frm
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
			//move to the end of spec %-+0#12.2d and moving the pf->buf there
			//also do all job, colling function foreach char
			frm = ft_parser(pf, frm);
		}
		else
			frm++;
	}
	ft_printbuf(pf, pf->tfrm, frm);
	va_end(pf->initarg); //va_end(pf->arg);??????
	return (pf->res_len);
}

