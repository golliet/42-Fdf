#include "libft.h"
char		*ft_ulltoa_base(unsigned long long n, int base)
{
	unsigned long long	tmpn;
	unsigned long long	len;
	char	*str;

	tmpn = n;
	len = 2;
	while (tmpn /= base)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % base + ((n % base > 9) ? ('A' - 10) : ('0'));
		n = n / base;
	}
	return (str);
}
