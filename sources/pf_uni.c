//
// Created by Antonin KOKOSHKO on 1/29/18.
//

#include "../includes/ft_printf.h"

static uint32_t		pf_addmask(uint32_t x)
{
	uint32_t mask;
	mask = 0x0;
	if (x <= 0x7F)
	{
	}
	else if(x <= 0x7FF)
	{
		mask = 0xC080;
	}
	else if (x <= 0xFFFF)
	{
		mask = 0xE08080;
	}
	else
	{
		mask = 0xF0808080;
	}
}


//дебаг заменить на вызов из pf_cs.c
static void		pf_process_cs(t_print *pf)
{
	int		dif;
	char	fil;

	fil = (pf->fmnus == 0 && pf->fzero == 1) ? '0' : ' ';
	dif = pf->minlen - pf->buf_len;
	if (dif > 0 && (pf->fmnus == 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), fil, dif), pf->buf, F_BOTH);
	if (dif > 0 && (pf->fmnus == 1))
		pf->buf = ft_joinfree(
				pf->buf, ft_memset(ft_strnew(dif), fil, dif), F_BOTH);
	if (dif > 0)
		pf->buf_len += dif;
	pf->res_len += pf->buf_len;
	if (*pf->tfrm == 'x')
		while (dif--)
			pf->buf[dif] = ft_tolower(pf->buf[dif]);
}

int			ftpf_uni_c(t_print *pf)
{
	uint32_t s;

	s = va_arg(pf->arg, uint32_t);
}

int			ftpf_uni_s(t_print *pf)
{
	uint32_t *s;

	s = va_arg(pf->arg, uint32_t*);
}

