/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uni.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:14:40 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:17:35 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			ft_unilen(uint32_t *s)
{
	int len;

	len = 0;
	while (*s++ != 0)
		len++;
	return (len);
}

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

static int		ft_uni_to_chr(char *dst, uint32_t c)
{
	uint8_t		*t;
	int 		i;
	int 		res;

	//c = pf_addmask(c);
	t = (uint8_t*)&c;
	i = 3;
	res = 0;
	while (i >= 0)
	{
		*dst = t[i];
		if (t[i] != 0)
		{
			dst++;
			res++;
		}
		i--;
	}
	return (res);
}

int					ftpf_uni_c(t_print *pf)
{
	uint32_t c;

	ftpf_skipvarg(pf);
	c = va_arg(pf->arg, uint32_t);
	pf->buf = ft_strnew(4);
	if (MB_CUR_MAX == 4)
		c = pf_addmask(c);
	else if (MB_CUR_MAX != 4 && c > 255)
		return (-1);
	pf->buf_len = ft_uni_to_chr(pf->buf, c);
	pf_process_cs(pf);
//	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}

int				ftpf_uni_s(t_print *pf)
{
	uint32_t	*s;
	int 		i;
	int 		ustrlen;
	int			ucharlen;

	ftpf_skipvarg(pf);
	s = va_arg(pf->arg, uint32_t*);
	ustrlen = ft_unilen(s);
	pf->buf = ft_strnew(ustrlen * 4);
	i = 0;
	while (i < ustrlen)
	{
		ucharlen = ft_uni_to_chr(&(pf->buf[pf->buf_len]), pf_addmask(s[i]));
		if (pf->fdot == 1 && (pf->buf_len + ucharlen) > pf->precis)
		{
			pf->buf[pf->buf_len] = 0;
			break;
		}
		pf->buf_len += ucharlen;
		i++;
	}
	pf_process_cs(pf);
//	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}
