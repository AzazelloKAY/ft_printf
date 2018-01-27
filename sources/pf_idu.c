//
// Created by Antonin KOKOSHKO on 1/26/18.
//

#include "../includes/ft_printf.h"

int		ft_getvarg(t_print *pf, char *sp, void *prm)
{
	//позже сплитнуть на идивидуальные для каждого спека
	//**************
	void *t;

//	if (!(t = va_arg(pf->arg, void*)))
//		return (1);

	if (*sp == 'o' || *sp == 'x' || *sp == 'X' || *sp == 'u')
		if (pf->f_l > 0 || pf->f_ld > 0 || pf->f_z > 0 || pf->f_j > 0)
			*(uint64_t*)prm = *(uint64_t*)t;//va_arg(pf->arg, uint64_t);
		else if (pf->f_h == 2)
			*(uint8_t*)prm = *(uint8_t*)t;//va_arg(pf->arg, uint8_t);
		else if (pf->f_h == 1)
			*(uint16_t*)prm = *(uint16_t*)t;//va_arg(pf->arg, uint16_t);
		else
			*(uint32_t*)prm = /*(uint32_t*)t;*/va_arg(pf->arg, uint32_t);

	else if (*sp == 'i' || *sp == 'd')
		if (pf->f_l > 0 || pf->f_ld > 0 || pf->f_z > 0 || pf->f_j > 0)
			*(int64_t*)prm = *(int64_t*)t;//va_arg(pf->arg, int64_t);
		else if (pf->f_h == 2)
			*(int8_t*)prm = *(int8_t*)t;//va_arg(pf->arg, int8_t);
		else if (pf->f_h == 1)
			*(int16_t*)prm = *(int16_t*)t;//va_arg(pf->arg, int16_t);
		else
			*(int32_t*)prm = *(int32_t*)t;//va_arg(pf->arg, int32_t);

	else if (*sp == 'U')
		*(uint64_t*)prm = *(uint64_t*)t;//va_arg(pf->arg, uint64_t);

	else if  (*sp == 'c')
		*(int32_t*)prm = *(int32_t*)t;//va_arg(pf->arg, int32_t);
	return (0);
}


void	pf_process_idu(t_print *pf)
{
	int		dif;
	char	fil;

	dif = pf->precision - pf->buf_len;
	if ((pf->fdot == 1) && (dif > 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), '0', dif), pf->buf, F_BOTH);
	if (pf->sign[0] == '-' || pf->fplus == 1)
		pf->buf = ft_joinfree(pf->sign, pf->buf, F_LAST);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	dif = pf->minlen - (int)ft_strlen(pf->buf);
	if (dif > 0 && (pf->fmnus == 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), fil, dif), pf->buf, F_BOTH);
	if (dif > 0 && (pf->fmnus == 1))
		pf->buf = ft_joinfree(
				pf->buf, ft_memset(ft_strnew(dif), fil, dif), F_BOTH);
	pf->buf_len = ft_strlen(pf->buf);
}

void	pf_minlen(t_print *pf, char *sign, char *fill)
{
	size_t len;

	len = ft_strlen(pf->buf) + ((*sign == '1') ? 1 : 0);
}



int		ftpf_id(t_print *pf)
{
	int64_t x;

	if (ft_getvarg(pf, pf->tfrm, &x))
		return (-1); //error status for noargv situation;
	if (x < 0)
		pf->sign = "-";
	pf->buf = ft_stoa_base(pf, x, 10);
	pf_process_idu(pf);
	write(1, pf->buf, pf->buf_len);
	return (1);
}

int		ftpf_u(t_print *pf)
{
	uint64_t x;

	if (ft_getvarg(pf, pf->tfrm, &x))
		return (-1); //error status for noargv situation;
	pf->buf = ft_utoa_base(pf, x, 10);
	pf_process_idu(pf);
	write(1, pf->buf, pf->buf_len);
	return (1);
}
