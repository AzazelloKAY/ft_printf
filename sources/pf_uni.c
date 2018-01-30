//
// Created by Antonin KOKOSHKO on 1/29/18.
//

#include "../includes/ft_printf.h"

#include <stdio.h>//******************************

uint32_t		pf_addmask(uint32_t x)
{
	if (x <= 0x7F)
		return (x);
	else if(x <= 0x7FF)
		return (((x & 0x7C0) << 2) + (x & 0x3F) + 0xC080);
	else if (x <= 0xFFFF)
		return (((x & 0xF000) << 4) + ((x & 0xFC0) << 2) + (x & 0x3F) + 0xE08080);
	else
		return (((x & 0x1C0000) << 6) + ((x & 0x3F000) << 4) + ((x & 0xFC0) << 2) + (x & 0x3F) + 0xF0808080);
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

int 		ft_unilen(uint32_t *s)
{
	int len;

	while (*s++ != 0)
		len++;
	return (len);
}

int		ft_uint_to_str(char *s, uint32_t *u)
{
	uint8_t *t;
	int 	i;
	int 	res;

	t = u;
	i = 3;
	res = 0;
	while (i >= 0)
	{
		*s = t[i];

		if (t[i] != 0)
		{
			s++;
			res++;
		}
		i--;
	}
	return (res);
}

int			ftpf_uni_c(t_print *pf)
{
	uint32_t c;

	c = 0;
	c = va_arg(pf->arg, uint32_t);
	pf->buf = ft_strnew(4);
	c = pf_addmask(c);
	pf->buf_len = ft_uint_to_str(pf->buf, &c);
	pf_process_cs(pf);
	write(1, pf->buf, pf->buf_len);
}



int			ftpf_uni_s(t_print *pf)
{
	uint32_t *s;

	s = va_arg(pf->arg, uint32_t*);
	pf->buf_len = ft_unilen(s);
}

