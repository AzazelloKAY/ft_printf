//
// Created by Antonin KOKOSHKO on 1/24/18.
//

#include "../includes/ft_printf.h"

void		ft_reset_pf(t_print *pf)
{
	pf->buf_len = 0;
	pf->minlen = 0;
	pf->precis = 0;
	pf->fplus = 0;
	pf->fmnus = 0;
	pf->fhash = 0;
	pf->fzero = 0;
	pf->fspace = 0;
	pf->fdot = 0;

	pf->f_ld = 0;
	pf->f_l = 0;
	pf->f_h = 0;
	pf->f_hh = 0;
	pf->f_ll = 0;
	pf->f_j = 0;
	pf->f_z = 0;

	pf->sign = "+";
	ft_strdel(&pf->buf);
}

static void		ft_flist_digit(t_print *pf)
{
	pf->flist['1'] = ftpf_parsenum;
	pf->flist['2'] = ftpf_parsenum;
	pf->flist['3'] = ftpf_parsenum;
	pf->flist['4'] = ftpf_parsenum;
	pf->flist['5'] = ftpf_parsenum;
	pf->flist['6'] = ftpf_parsenum;
	pf->flist['7'] = ftpf_parsenum;
	pf->flist['8'] = ftpf_parsenum;
	pf->flist['9'] = ftpf_parsenum;
}

static void		ft_init_flist(t_print *pf)
{
	pf->flist[0] = &ftpf_undefined;
	pf->flist['c'] = &ftpf_c;
	pf->flist['C'] = &ftpf_uni_c;
	pf->flist['s'] = &ftpf_s;
	pf->flist['i'] = &ftpf_id;
	pf->flist['d'] = &ftpf_id;
	pf->flist['D'] = &ftpf_id;
	pf->flist['u'] = &ftpf_u;
	pf->flist['U'] = &ftpf_u;
	pf->flist['p'] = &ftpf_p;
	pf->flist['x'] = &ftpf_x;
	pf->flist['X'] = &ftpf_x;
	pf->flist['o'] = &ftpf_o;
	pf->flist['O'] = &ftpf_o;
	pf->flist['%'] = &ftpf_undefined;

	pf->flist['-'] = ftpf_setflag;
	pf->flist['+'] = ftpf_setflag;
	pf->flist['#'] = ftpf_setflag;
	pf->flist['0'] = ftpf_setflag;
	pf->flist[' '] = ftpf_setflag;
	pf->flist['.'] = ftpf_setflag;
	pf->flist['l'] = ftpf_setflag;
	pf->flist['L'] = ftpf_setflag;
	pf->flist['h'] = ftpf_setflag;
	pf->flist['z'] = ftpf_setflag;
	pf->flist['j'] = ftpf_setflag;
	ft_flist_digit(pf);
	//pf->flist[''] = ftpf_setflag;
}

t_print		*ft_init_pf(const char *frm)
{
	t_print	*pf;

	if (!(pf = ft_memalloc(sizeof(t_print))))
		return (NULL);
	if (!(pf->flist = ft_memalloc(sizeof(func_p) * 128)))
		return (NULL);
	ft_init_flist(pf);
	if (frm == NULL)
		return (NULL);
	pf->tfrm = frm;
	return (pf);
}

