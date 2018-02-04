//
// Created by Antonin KOKOSHKO on 2/4/18.
//

#include "../includes/ft_printf.h"

int		ftpf_f(t_print *pf)
{
	double x;

	if (pf->fdot == 0)
	{
		pf->fdot = 1;
		pf->precis = 6;
	}
	ftpf_skipvarg(pf);
	x = va_arg(pf->arg, double);


	pf_process_cs(pf);


	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	return (1);
}