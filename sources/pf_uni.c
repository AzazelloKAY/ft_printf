//
// Created by Antonin KOKOSHKO on 1/29/18.
//

#include "../includes/ft_printf.h"

#include <stdio.h>//******************************

static uint32_t		pf_addmask(uint32_t x)
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
//static void		pf_process_cs(t_print *pf)
//{
//	//int		dif;
//	char	fil;
//
//	fil = (pf->fmnus == 0 && pf->fzero == 1) ? '0' : ' ';
//	ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
//	pf->res_len += pf->buf_len;
//}

int 		ft_unilen(uint32_t *s)
{
	int len;

	len = 0;
	while (*s++ != 0)
		len++;
	return (len);
}

int			ft_uint_to_str(char *s, uint32_t u)
{
	uint8_t *t;
	int 	i;
	int 	res;

	t = &u;
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

	c = va_arg(pf->arg, uint32_t);
	pf->buf = ft_strnew(4);
	pf->buf_len = ft_uint_to_str(pf->buf, pf_addmask(c));
	pf_process_cs(pf);
	write(1, pf->buf, pf->buf_len);
	return (0);
}



int			ftpf_uni_s(t_print *pf)
{
	uint32_t	*s;
	int 		slen;
	int 		i;

	s = va_arg(pf->arg, uint32_t*);
	slen = ft_unilen(s);
	pf->buf = ft_strnew(slen * 4);
	i = 0;
	while (i < slen )
	{
		pf->buf_len += ft_uint_to_str(&(pf->buf[pf->buf_len]), pf_addmask(s[i]));
		if (pf->fdot == 1 && pf->buf_len > pf->precis)
		{
			//удалить последний символ!!!! длинной которую верент юинтТУстр
			break;
		}
		i++;
	}
	if ((pf->fdot == 1)  && (pf->precis < pf->buf_len))
	{
		//выводить только полные ЮНИКОД символы попадающие в длинну пресижина!!!!!!!!!!!
		pf->buf[pf->precis] = 0;
		pf->buf_len = pf->precis;
	}
	pf_process_cs(pf);
	write(1, pf->buf, pf->buf_len);
}

