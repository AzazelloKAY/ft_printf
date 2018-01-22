#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint-gcc.h>
# include "../libft/libft.h"

typedef int		(*func_p)(void*, void*);

typedef struct 	s_prnt
{
	int 	buf_len;
	int 	res_len;


	//long double	forthefuture;// for presitious float
	//FIX FT_STRJOIN!!!!!!!!!!!!

	//move flags and spec-s to separet struct????
	int 	minwidth;
	int		precision;
	uint8_t fplus;
	uint8_t fmnus;
	uint8_t fhash;
	char 	spec;

	va_list arg;
	const char 	*tfrm;
	func_p	*flist;
}				t_print;

int				ft_printf(const char *format, ...);

int				ftpf_c(t_print *pf, void *x);
int				ftpf_s(t_print *pf, void* x);
int				ftpf_persent(t_print *pf, void* x);

void			ft_reset_pf(t_print *pf); //reset PF after each spec

#endif
