#include "math.h"
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str);

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		size;

	size = ft_strlen((char *)s1);
	dup = (char *)malloc(size + 1);
	if (!dup)
		return (NULL);
	while (*s1)
	{
		*dup = *(char *)s1;
		s1++;
		dup++;
	}
	*dup = '\0';
	return (dup - size);
	free(dup);
}

int	counter(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = counter(n);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}


char	**ft_itoa_arr(int *arr, int len)
{
	char	**str;
	int		size;
	int		i;
	
	str = (char **)malloc(sizeof(char *) * len + 1);
	i = -1;
	while (++i < len)
		str[i] = ft_itoa(arr[i]);

	return (str);
}


int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	ft_isntdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (0);
	return (1);
}

long int	ft_unsigned_atoi(char *str)
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
	if (str[0] == '-')
		return (-1);	
	while (++c < size)
	{
		if (ft_isntdigit(str[c]))
			return (-1);
		ret += str[c] - '0';
		if (size != 1 && str[c + 1] != '\0')
			ret *= 10;
	}
	return (ret);
}

int	*swap(int *arr, int temp, int i, int len_num)
{
	temp = arr[i];
	int x = rand() % len_num;

	arr[i] = arr[x];
	arr[x] = temp;
	return (arr);
}

int main(int ac, char **av)
{
	int len_num;
	int i;
	int *array;
	int temp;
	int randomIndex;
	char **str;
	int fd;

	fd = open("test.txt", O_CREAT | O_TRUNC | O_RDWR);
	len_num = ft_unsigned_atoi(av[1]);
	if (len_num == -1)
		printf("Error on atoi\n");
	array = (int *)malloc(sizeof(int) * len_num + 1);
	i = -1;
	while (++i < len_num)
		array[i] = i;
	i = -1;
	srand(time(NULL));
	while (++i < len_num)
		swap(array, temp, i, len_num);
	i = -1;
	while (++i < len_num)
		printf("arr %d\n", array[i]);
	str = ft_itoa_arr(array, len_num);
	i = -1;
	write(fd, "\"", 1);
	while (++i < len_num)
	{
		write(fd, str[i], ft_strlen(str[i]));
		if (i + 1 < len_num)
			write(fd, " " , 1);
	}
	write(fd, "\"", 1);
	return (0);
}