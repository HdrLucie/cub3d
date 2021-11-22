#include "libft.h"

int	ft_int_ternaire(int condition, int first_value, int second_value)
{
	if (condition)
		return (first_value);
	else
		return (second_value);
}
