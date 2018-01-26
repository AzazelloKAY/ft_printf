//
// Created by Antonin KOKOSHKO on 1/26/18.
//

#include "../includes/ft_printf.h"

int		ftpf_id(t_print *pf)
{

	return (1);
}

int		ftpf_u(t_print *pf)
{
	uint64_t x;

	if (pf->f_l > 0 || pf->f_ld > 0 || pf->f_z > 0 || pf->f_j > 0)
		x = va_arg(pf->arg, uint64_t);
	else if (pf->f_s == 2)
		x = va_arg(pf->arg, uint16_t);
	else if (pf->f_s == 1)
		x = va_arg(pf->arg, uint8_t);
	else
		x = va_arg(pf->arg, uint32_t);

	return (1);
}
