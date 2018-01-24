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
	pf->fzero = 0;
	pf->fspace = 0;
	pf->fdot = 0;

	pf->flong = 0;
	pf->flongd = 0;
	pf->fshort = 0;

	//pf->spec = 0;
}

char	*ft_printbuf(t_print *pf, const char *start, const char *stop)
{
	size_t len;

	len = (stop - start);
	write(1, start, len);
	pf->res_len += len;
	return ((char*)start + len);
}

int		ft_parser(t_print *pf, char *frmt)
{
	int		len;

	ft_reset_pf(pf);
	len = 0;
	pf->tfrm = frmt + 1;
	//pf->spec = *pf->tfrm; //dellllllll!!!!!
	while (*pf->tfrm || (pf->flist[*pf->tfrm] != NULL))
	{
	//	if (*pf->tfrm <= 32 || *pf->tfrm >= 127)
	//		return (-1);
//		get checking of NULL function pointer down here and fork to kalling function and break with nothing/undefine

		printf("%p", pf->flist[*pf->tfrm]);//?????????????????????????????????

		if (pf->flist[*pf->tfrm](pf) < 0)
			return (0);
		pf->tfrm++;
	}
	//here we come only in the end of the line
	pf->flist[0](pf);
	len = pf->tfrm - frmt; //spec len, does this need in my code????????????????
	return (len); //return length of specificator and flags //or job status // speclen == pf->tfrm - frmt
}

int		ft_printf(const char *frmt, ...)
{
	t_print	*pf;

	if (!(pf = ft_memalloc(sizeof(t_print))))
		return (-1);
	ft_intit_flist(pf);
	pf->tfrm = frmt;

	va_start(pf->intarg, frmt);
	va_copy(pf->arg, pf->intarg);

	while (*frmt)
	{
		if (*frmt == '%')
		{
			ft_printbuf(pf, pf->tfrm, frmt);
			//move to the end of spec %-+0#12.2d and moving the pf->buf there
			//also do all job, colling function foreach char
			ft_parser(pf, frmt);
			frmt = pf->tfrm;
		}
		else
			frmt++;
	}
	ft_printbuf(pf, pf->tfrm, frmt);
	va_end(pf->intarg);
	return (pf->res_len);
}





//int		ft_loncher(t_print *pf, int spec, void *x)
//{
//	if (spec <= 32 || spec >= 127)
//		return (1);
//	pf->res_len += pf->flist[spec](pf, x);
//	return (0);
//}