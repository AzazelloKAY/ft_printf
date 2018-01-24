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



	int a;
	//printf("_%lu\n", sizeof(long double));

	a = 234;//.19;
	//ft_bzero(&a, sizeof(long double));



	printf("<< pf2>=%d\n",printf("%4. 05d", a));
    return (0);
}