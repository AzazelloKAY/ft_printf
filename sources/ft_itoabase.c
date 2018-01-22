//
// Created by Ali on 22.01.2018.
//

#include "../includes/ft_printf.h"

char	*ft_ud_toa_base(unsigned long long val, int base)
{
	char				*bchr;
	char				*res;
	size_t				len;
	unsigned long long 	tmp;

	tmp = val;
	bchr = "0123456789ABCDEF";
	len = ((val == 0) || (val < 0 && base == 10)) ? 1 : 0;
	while (tmp != 0)
	{
		len++;
		tmp /= base;
	}
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[0] = (char) ((val < 0 && base == 10) ? '-' : '0');
	while (val)
	{
		res[--len] = bchr[val % base];
		val /= base;
	}
	return (res);
}

char	*ft_sd_toa_base(long long val, int base)
{
	char *res;
	char *t;

	res = ft_ud_toa_base((unsigned long long)val, base);
	if (val < 0)
	{
		t = ft_strjoin("-", res);
		ft_memdel((void**)&res);
		res = t;
	}
	return (res);
}
