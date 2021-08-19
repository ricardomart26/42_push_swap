/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:17:44 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 01:19:23 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

static	void	if_minus(char *str, int *minus, int *c)
{
	*minus = 0;
	if (str[0] == '-')
	{
		(*c)++;
		*minus = 1;
		if (str[1] == '\0')
			error_mes();
	}
}

long int	ft_atoi(char *str)
{
	int			c;
	long int	ret;
	int			size;
	int			minus;

	size = ft_strlen(str);
	if (*str == '0' && size == 1)
		return (0);
	ret = 0;
	c = -1;
	if_minus(str, &minus, &c);
	while (++c < size)
	{
		if (ft_isntdigit(str[c]))
			error_mes();
		ret += str[c] - '0';
		if (size != 1 && str[c + 1] != '\0')
			ret *= 10;
	}
	if (minus)
		ret *= -1;
	return (ret);
}

int	*ft_swap(int *stack, int i)
{
	int	temp;

	temp = stack[i + 1];
	stack[i + 1] = stack[i];
	stack[i] = temp;
	return (stack);
}

int	find(int number, int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (number == arr[i])
			return (i);
		i++;
	}
	return (-1);
}
