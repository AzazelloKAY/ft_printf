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

int		ft_intit_flist(t_print *pf)
{
	if(pf->flist != NULL)
		ft_memdel(pf->flist);
	pf->flist = ft_memalloc(sizeof(func_p) * 128);
	pf->flist[0]=ft_strlen;
	pf->flist['c'] = &ft_putchar;
	pf->flist['s'] = &ft_putstr;

}

char	*ft_printbuf(char *c, t_print *pf)
{
	size_t len;

	len = (pf->buf - c);
	write(1, c, len);
	pf->res_len += len;
	return (c + len);
}

int		ft_loncher(t_print *pf, int spec, void *x)
{
	if (spec <= 32 || spec >= 127)
		return (1);
	pf->flist[spec](x);
	return (0);
}

int		ft_printf(const char *frmt, ...)
{
	t_print	*pf;

	if (!(pf = ft_memalloc(sizeof(t_print))))
		return (-1);
	ft_intit_flist(pf);
	pf->buf = frmt;					//maytbe not needed
	va_start(pf->arg, frmt);
	while (*(pf->buf))
	{
		if (*(pf->buf) == '%')
		{
			ft_printbuf(frmt, pf);
			frmt = ++pf->buf; //ft_parsespec()		//move to the end of spec %-+0#12.2d
			if (ft_loncher(pf, *frmt, va_arg(pf->arg, void*)))
				return (-1);
		}
		else
			pf->buf++;
	}
	ft_printbuf(frmt, pf);
	va_end(pf->arg);
	return (pf->res_len);
}
