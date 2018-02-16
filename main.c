#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "includes/ft_printf.h"

//	fflush(stdout);



/*
 * 	u_type test;
	test.x = -1;
	test.y.sign = 0;
	printf("==%d\n\n", test.x);
 * */

//static double pf_dblpow(int i)
//{
//	double res;
//
//	res = 1;
//	while (i--)
//		res *= 10;
//	return (res);
//}
//
//char	*ft_ffftoa(u_ldoublebfild x)
//{
//	char	*tchar;
//	int 	i;
//	int		num;
//	double 	tmp;
//
//	char 	*res;
//
//
//	tmp = x.x;
//	i = 0;
//	while (tmp >= 1)
//	{
//		tmp /= 10;
//		i++;
//	}
//	tchar = ft_strnew(1);
//	while (i--)
//	{
//		tmp = pf_dblpow(i);
//		num = (uint8_t)(x.x / tmp);
//		tchar[0] = (uint8_t)num + (uint8_t)'0';
//		res = ft_joinfree(res, tchar, F_FIRST);
//		x.x -= num * tmp;
//		//pf->buf_len++;
//	}
// //	pf_fquote(pf);
//	res = ft_joinfree(res, ".", F_FIRST);
//	//pf->buf_len++;
//	if (x.x == 0)
//		return (res);
//	while (x.x != 0)
//	{
//		x.x *= 10;
//		tchar[0] = (uint8_t)x.x+ '0';
//		res = ft_joinfree(res, tchar, F_FIRST);
//		x.x -= (uint8_t)x.x;
//		//pf->buf_flen++;
//	}
//	//pf->buf_len += pf->buf_flen;
//	ft_strdel(&tchar);
//	return (res);
//}


int main()
{
	setlocale(LC_ALL, "");
	//setlocale(LC_NUMERIC,"");

//	ft_putstr("asdasdgfsdg#$%$^$&$&^*546867sd\n");


//	int ff = 200;
//	ft_printf("%1$d====\n%1$5'd<\n\n", ff);

//	long double l;
//	u_ldoublebfild test;
//	l = -222270.9578;
//	test.x = l;
//	printf(">=>%'Lf<\n", test.x);
//	fflush(stdout);


//	ft_printf("\n");


//printf("\n\n\n\n>>>STEP\n");
//fflush(stdout);

//char *s = "*asdwerфывапрнекуцй";
//	printf(">>>>>>%d\n",ft_printf(">%.6ls<\n", s));
//	printf("@%S<\n", s);
//	printf(">>>>>>%d\n", ft_printf(">%S<\n", L""));
//	printf("@>>>>>%d\n", printf("@%S<\n", L""));
//	printf(">>>>>>%d\n", ft_printf(">%03d<\n", 0));
//	printf("@>>>>>%d\n", printf("@%03d<\n", 0));
//	fflush(stdout);
//	ft_printf(">%#o<\n", 0);
//	printf(">%#o<\n", 0);
//	fflush(stdout);
	char *format = "{%#.2o}\n";
	ft_printf(ft_strjoin(">", format), 0);
	printf(ft_strjoin("@", format), 0);
	fflush(stdout);
//	double t = 111111111111111.123456789L;
//	u_ldoublebfild x;
//	x.x = t;
	long double sd = 123.99995454654879875488888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888885L;//11111111111111111111111111111.123456789L;
	format = "%+.4LF<\n";
	sd = -(0.0 / 0.0);

	printf(ft_strjoin("@", format), sd);
	fflush(stdout);
	ft_printf(ft_strjoin(">", format), sd);
	//printf("new >%s\n", ft_ffftoa(x));


//	char *form = "{%f}{%F}\n";
//	ft_printf(ft_strjoin(">", form), t, t);
//	printf(ft_strjoin("@", form), t, t);
//	fflush(stdout);
//	ft_printf(">>%c<<\n", 0);
//	printf(">>%c<<\n", 0);

//	ft_printf("%d%d\n", 42, 41);
//	ft_printf("%d%d%d\n", 42, 43, 44);
//	ft_printf("%ld\n", 2147483647);
//	ft_printf("%lld\n", 9223372036854775807);
//	ft_printf("%x\n", 505);
//	ft_printf("%X\n", 505);
//	ft_printf("%p\n", &ft_printf);
//	ft_printf("%20.15d\n", 54321);
//	ft_printf("%-10d\n", 3);
//	ft_printf("% d\n", 3);
//	ft_printf("%+d\n", 3);
//	ft_printf("%010d\n", 1);
//	ft_printf("%hhd\n", 0);
//	ft_printf("%jd\n", 9223372036854775807);
//	ft_printf("%zd\n", 4294967295);
//	ft_printf("%\n");
//	ft_printf("%U\n", 4294967295);
//	ft_printf("%u\n", 4294967295);
//	ft_printf("%o\n", 40);
//	ft_printf("%%#08x\n", 42);
//	ft_printf("%x\n", 1000);
//	ft_printf("%#X\n", 1000);
//	ft_printf("%s\n", NULL);
//	ft_printf("%S\n", L"ݗݜशব");
//	ft_printf("%s%s\n", "test", "test");
//	ft_printf("%s%s%s\n", "test", "test", "test");
//	ft_printf("%C\n", 15000);

	//system("leaks exe");


//*******************************
	/*
	printf("@_%.5u<\n", 42);
	fflush(stdout);
	ft_printf(">_%.5u<\n", 42);
	 */
//*******************************

//*******************************
	//double@@@@@@@@@@@@@@@@@@@@@@@@
//u_doublebfild d;
//	d.x = 1.9;
//	printf(">====>%f(S=%d E=%ld M=%ld)<\n", d.x, d.f.sign, d.f.exp, d.f.man);
//	fflush(stdout);
//	ft_printf("sign = %b exp = %b man = %b\n", d.f.sign, d.f.exp, d.f.man);

//	d.x = 9.99999;
//	printf("#%.0e\n",d.x);
//
//	printf(">====>%.8f(S=%d E=%ld M=%ld)<\n", d.x, d.f.sign, d.f.exp, d.f.man);
//	fflush(stdout);
//	ft_printf("sign = %b exp = %b man = %b\n", d.f.sign, d.f.exp, d.f.man);
//
//	ft_printf("##MY## >>>%.8'f<\n\n", d.x);
	//double@@@@@@@@@@@@@@@@@@@@@@@@
	//*******************************


//	test.x /= 1;
//	printf(">>%.10Lf<\n", test.x);
//
//	ff = 0;
// //	while (ff < 25)
//	{
//		ft_printf("sign = %b exp = %b man = %b\n", test.f.sign, test.f.exp, test.f.man);
//		fflush(stdout);
//		test.x /= 2;
//		ff++;
//	}

	//ft_printf("sign = %b exp = %d man = %ld\n",test.f.sign, test.f.exp, test.f.man );



//u_type test;
//test.x = 2;
//test.y.sign = 0;
//printf("==%d\n\n", test.x);


//
//uint32_t x = 945;
//
//
//	if (MB_CUR_MAX == 1)
//		printf("aaaaaa\n");
//	else if (MB_CUR_MAX == 4)
//		printf("XYIIIII");
//
//	char *c = 0;
//	printf(">%7.8s<<<\n", c);
//	fflush(stdout);
//	ft_printf("_%7.8s<<<\n", c);


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



