#include "../libft/libft.h"

static size_t	ft_lg(int n)
{
	size_t	result;

	result = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*itoa2(int n)
{
	size_t	len;
	char	*result;
	char	digit;
	int		num;

	num = n;
	len = ft_lg(num);
	if (num < 0)
		len++;
	result = ft_calloc((len + 1), sizeof(char));
	while (len--)
	{
		digit = num % 10;
		if (num < 0)
			digit = -digit;
		result[len] = digit + '0';
		num /= 10;
	}
	if (n < 0)
		*result = '-';
	return (result);
}
