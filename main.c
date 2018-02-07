#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "includes/ft_printf.h"

//	fflush(stdout);


typedef struct bitfield
{
	unsigned x1:1;
	unsigned x2:30;
	unsigned sign:1;

}				bbfield;

typedef struct s_long_d
{
	unsigned long	man		: 64;
	unsigned long	exp		: 15;
	unsigned 		sign	: 1;

}				t_long_d;

typedef union	u_bfild
{
	long double	x;
	t_long_d	f;
}				t_bfild;


/*
 * 	u_type test;
	test.x = -1;
	test.y.sign = 0;
	printf("==%d\n\n", test.x);
 * */

int main()
{
	//setlocale(LC_ALL,"");
	setlocale(LC_NUMERIC,"");

//	ft_putstr("asdasdgfsdg#$%$^$&$&^*546867sd\n");


	int ff = 200000000;
	printf("~~%'d<\n\n", ff);

	long double l;
	t_bfild test;
	l = 1;
	test.x = l;

	printf(">>%L.10f<\n", test.x);
	ft_printf("sign = %b exp = %b man = %b\n", test.f.sign, test.f.exp, test.f.man);
	test.x /= 1;
	printf(">>%.10Lf<\n", test.x);

	ff = 0;
//	while (ff < 25)
	{
		ft_printf("sign = %b exp = %b man = %b\n", test.f.sign, test.f.exp, test.f.man);
		fflush(stdout);
		test.x /= 2;
		ff++;
	}

	//ft_printf("sign = %b exp = %d man = %ld\n",test.f.sign, test.f.exp, test.f.man );



//u_type test;
//test.x = 2;
//test.y.sign = 0;
//printf("==%d\n\n", test.x);



uint32_t x = 945;


//	if (MB_CUR_MAX == 1)
//		printf("aaaaaa\n");
//	else if (MB_CUR_MAX == 4)
//		printf("XYIIIII");

	char *c = 0;
	printf(">%7.8s<<<\n", c);
	fflush(stdout);
	ft_printf("_%7.8s<<<\n", c);


	//***************************************************

//	printf("long dbl size = %lu\n", sizeof(long double));
//	printf("double size = %lu\n", sizeof(double));
//	long double ld= 0;
//	fflush(stdout);
//	double d;
//	d = 1.0;
//	ft_printf("binary = %b\n", d);

//	while (d >0)
//	{
//		d /= 2.0;
//		ft_printf("2binary = %b\n", d);
//	}
//	d /= 2.0;
//	ft_printf("3binary = %b\n", d);
//	d /= 2.0;
//	ft_printf("4binary = %b\n", d);
//	printf("ld = %5.2f\n", d);


//	char *cc = NULL;
//	printf("123\e[m%s\n", ft_strjoin(cc, "asd"));
//	fflush(stdout);
//
//	t_colors n = e_blue;

	//printf("n = %s\n", ft_joinfree("\\e[", ft_itoa(n), F_LAST));
	//ft_printf("a{black}a{red}a{green}a{orange}a{blue}s{purple}s{cyan}s{gay}s{white}sss%dzzz{{white}zzz", 54);



	return (0);
}



