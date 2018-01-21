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

void	ft_reset_pf(t_print *pf)
{
//	if (pf-> != NULL)
//		ft_memdel(pf->);
	pf->buf_len = 0;
	pf->minwidth = 0;
	pf->precision = 0;
	pf->fplus = 0;
	pf->fmnus = 0;
	pf->fhash = 0;
	pf->spec = 0;
}

int		ft_intit_flist(t_print *pf)
{
	if(pf->flist != NULL)
		ft_memdel((void**)pf->flist);
	pf->flist = ft_memalloc(sizeof(func_p) * 128);
	//pf->flist[0]=ft_strlen;		//plag
	pf->flist['c'] = &ftpf_c;
	pf->flist['s'] = &ftpf_s;
	pf->flist['%'] = &ftpf_persent;

}

char	*ft_printbuf(const char *c, t_print *pf)
{
	size_t len;

	len = (pf->tfrm - c);
	write(1, c, len);
	pf->res_len += len;
	return ((char*)c + len);
}

int		ft_loncher(t_print *pf, int spec, void *x)
{
	if (spec <= 32 || spec >= 127)
		return (1);
	pf->res_len += pf->flist[spec](pf, x);
	return (0);
}

int		ft_printf(const char *frmt, ...)
{
	t_print	*pf;

	if (!(pf = ft_memalloc(sizeof(t_print))))
		return (-1);
	ft_intit_flist(pf);
	pf->tfrm = frmt;					//maytbe not needed
	va_start(pf->arg, frmt);
	while (*(pf->tfrm))
	{
		if (*(pf->tfrm) == '%')
		{
			ft_printbuf(frmt, pf);
			//ft_parsespec()		//move to the end of spec %-+0#12.2d and moving the pf->buf there
			if (ft_loncher(pf, pf->spec, va_arg(pf->arg, void*)))
				return (-1);
			frmt = /*++*/pf->tfrm;
		}
		else
			pf->tfrm++;
	}
	ft_printbuf(frmt, pf);
	va_end(pf->arg);
	return (pf->res_len);
}
