//
// Created by Ali on 31.01.2018.
//

#include "../includes/ft_printf.h"

int 		ftpf_process_minlen(t_print *p, char *buf, int len, char fil)
{
	len = p->minlen - len;
	if (len > 0)
	{
		if (p->fmnus == 0)
			p->buf = ft_joinfree(ft_memset(ft_strnew(len), fil, len), buf, F_BOTH);
		else
			p->buf = ft_joinfree(buf, ft_memset(ft_strnew(len), fil, len), F_BOTH);
		p->buf_len += len;
	}
	return (p->buf_len);
}

int 		ftpf_process_precis(t_print *p, char *buf, int len)
{
	len = p->precis - len;
	if ((p->fdot == 1) && (len > 0))
	{
		p->buf = ft_joinfree(ft_memset(ft_strnew(len), '0', len), buf, F_BOTH);
		p->buf_len += len;
	}
	return (p->buf_len);
}

int 		ftps_process_sign(t_print *pf)
{
	if (pf->sign[0] == '-' || pf->fplus == 1)
	{
		pf->buf = ft_joinfree(pf->sign, pf->buf, F_LAST);
		pf->buf_len++;
	}
	return (pf->buf_len);
}

long 		ft_abs(long x)
{
	return ((x < 0) ? -x : x);
}
