#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
//# include <stdint-gcc.h>
# include "../libft/libft.h"

# define FREE_NONE -1
# define FREE_FIRST 0
# define FREE_LAST 1
# define FREE_BOTH 2

typedef int		(*func_p)(void*); //0 - move forvard; 1 - time to stop spec parse

typedef struct 	s_prnt
{
	int 		buf_len;
	int 		res_len;
	const char 	*tfrm;
	char 		*res;

	//long double	forthefuture;// for presitious float

	//move flags and spec-s to separet struct????
	int 		minwidth;
	int			precision;
	int8_t		fplus;
	int8_t		fmnus;
	int8_t		fhash;
	int8_t		fzero;
	int8_t		fspace;
	int8_t		fdot;
	int8_t		f_ld;
	int8_t		f_s;
	int8_t		f_l;
	int8_t		f_j;
	int8_t		f_z;


	//char		spec;//в моей схеме не нужно т,к, сам символ будет вызывать ф-цию

	va_list		arg;
	va_list		initarg;
	func_p		*flist;
}				t_print;

int				ft_printf(const char *format, ...);

//int				ft_intit_flist(t_print *pf);
t_print			*ft_init_pf(const char *frm);
int				ftpf_setflag(t_print *pf);
int				ftpf_parsenum(t_print *pf);
int				ftpf_c(t_print *pf);
int				ftpf_s(t_print *pf);
int				ftpf_id(t_print *pf);
int				ftpf_u(t_print *pf);
int				ftpf_persent(t_print *pf);

int				ftpf_undefined(t_print *pf);

void			ft_reset_pf(t_print *pf); //reset PF after each spec
char			*ft_joinandfree(char const *s1, char const *s2, int flag);

#endif
