//
// Created by Antonin KOKOSHKO on 1/24/18.
//

#include "../includes/ft_printf.h"

static void	ft_flist_digit(t_print *pf)
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

int		ft_intit_flist(t_print *pf)
{
	if(pf->flist != NULL)
		ft_memdel((void**)pf->flist);
	pf->flist = ft_memalloc(sizeof(func_p) * 128);
	pf->flist[0] = &ftpf_undefined;
	pf->flist['c'] = &ftpf_c;
	pf->flist['s'] = &ftpf_s;
	pf->flist['%'] = &ftpf_persent;

	pf->flist['-'] = ftpf_setflag;
	pf->flist['+'] = ftpf_setflag;
	pf->flist['#'] = ftpf_setflag;
	pf->flist['0'] = ftpf_setflag;
	pf->flist[' '] = ftpf_setflag;
	pf->flist['.'] = ftpf_setflag;
	pf->flist['l'] = ftpf_setflag;
	pf->flist['L'] = ftpf_setflag;
	pf->flist['h'] = ftpf_setflag;
	ft_flist_digit(pf);
	//pf->flist[''] = ftpf_setflag;

}

