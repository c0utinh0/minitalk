#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	bin_to_dec(char	* num)
{
	int dec = 0, base = 1, rem, new;
	new = atoi(num);
	while (new > 0)
	{
		rem = new % 10;
		dec = dec + rem * base;
		new = new / 10 ;
		base = base * 2;
	}
	write(1, &dec, 1);
	return (dec);
}

int main(void)
{
	char	*x = "1000010";
	int ret;

	ret = bin_to_dec(x);
//	printf("%c", ret);
	return (0);
}

