#include "libft.h"

float	ft_float_ternaire(int condition, float first_value, float second_value)
{
	if (condition)
		return (first_value);
	else
		return (second_value);
}
