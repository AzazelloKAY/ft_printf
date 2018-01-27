#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h"



int main()
{
	setlocale(LC_ALL,"");

//	ft_putstr("asdasdgfsdg#$%$^$&$&^*546867sd\n");

//	long i = 7;
//	int8_t xx = 127;
//	int x = printf(">%S_\n", L"ав");
//	printf("num=%d",x);
//	printf("start>");

//	int xx = ft_printf("\n>%s >> ", "<my test string>");//"<words in arg>\n");


//	printf("\npf=%d",printf("\n\n>%в__|%d|__", xx));

	//printf("_%lu\n", sizeof(long double));



	unsigned a = 429;//.19;
	ft_printf("%9.5u", a);
	int c = (unsigned int) a;
	//ft_bzero(&a, sizeof(long double));

	printf("\n<< pf2>=%d\n",printf("=%9.5u", a));//a & 0x7FFFFFFFFFFFFFFF));
    return (0);
}