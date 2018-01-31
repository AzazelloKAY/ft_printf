//
// Created by Antonin KOKOSHKO on 1/26/18.
//

#include "../includes/ft_printf.h"

#include <stdio.h>//******************************

static int		ft_getvarg_s(t_print *pf, char *sp, int64_t *prm)
{
	if (*sp == 'D')
		*prm = va_arg(pf->arg, int64_t);
	else if (pf->f_l > 0 || pf->f_ll > 0 || pf->f_ld > 0 || pf->f_z > 0 || pf->f_j > 0)
		*prm = va_arg(pf->arg, int64_t);
	else if (pf->f_h == 2)
		*prm = va_arg(pf->arg, int8_t);
	else if (pf->f_h == 1)
		*prm = va_arg(pf->arg, int16_t);
	else
		*prm = va_arg(pf->arg, int32_t);
	return (0);
}

static int		ft_getvarg_u(t_print *pf, char *sp, uint64_t *prm)
{
	if (*sp == 'U')
		*prm = va_arg(pf->arg, uint64_t);
	else if (pf->f_l > 0 || pf->f_ll > 0 || pf->f_ld > 0 || pf->f_z > 0 || pf->f_j > 0)
		*prm = va_arg(pf->arg, uint64_t);
	else if (pf->f_h == 1)
		*prm = va_arg(pf->arg, uint16_t);
	else if (pf->f_hh == 1)
		*prm = va_arg(pf->arg, uint8_t);
	else
		*(uint32_t*)prm = va_arg(pf->arg, uint32_t);
	return (0);
}


static void		pf_process_idu(t_print *pf)
{
	//int		dif;
	char	fil;

	ftpf_process_precis(pf, pf->buf, pf->buf_len);
	if (*pf->tfrm != 'u' && *pf->tfrm != 'U')
		ftps_process_sign(pf);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
	pf->res_len += pf->buf_len;
}

int			ftpf_id(t_print *pf)
{
	int64_t x;

	x = 0;
	ft_getvarg_s(pf, pf->tfrm, &x);
	pf->sign = (x < 0) ? "-" : "+";
	pf->buf = ft_stoa_base(pf, x, 10);
	((x == 0 && pf->fdot == 1 && pf->precis == 0) ? pf->buf[0] = 0 : 0);
	pf_process_idu(pf);
	write(1, pf->buf, pf->buf_len);
	return (1);
}

int			ftpf_u(t_print *pf)
{
	uint64_t x;

	x = 0;
	ft_getvarg_u(pf, pf->tfrm, &x);
	pf->buf = ft_utoa_base(pf, x, 10);
	((x == 0 && pf->fdot == 1 && pf->precis == 0) ? pf->buf[0] = 0 : 0);
	pf_process_idu(pf);
	write(1, pf->buf, pf->buf_len);
	return (1);
}
