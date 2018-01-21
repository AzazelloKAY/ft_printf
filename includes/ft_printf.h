#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef void	(*func_p)(void*);


typedef struct 	s_prnt
{
	int 	buf_len;
	int 	res_len;
	int 	tmp;
	int 	minwidth;
	int		precision;
	uint8_t fplus;
	uint8_t fmnus;
	uint8_t fhash;
	char 	*spec;
	va_list arg;
	char 	*buf;
	func_p	*flist;
}				t_print;

int				ft_printf(const char *format, ...);

#endif
