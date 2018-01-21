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

	int xx = ft_printf("\nft_printf test>%s >>", "<my test string>");//"<words in arg>\n");


	printf("\n\n>__|%d|__", xx);
//	printf("\n%d\n",printf("_@%c_",127));
    return (0);
}