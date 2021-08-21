#include "../push_swap.h"

void	free2(int **org, int **chunks)
{
	free(*org);
	*org = NULL;
	free(*chunks);
	*chunks = NULL;
}

void	ft_bzero(void *s, size_t n)
{
	int		c;
	char	*temp;

	temp = (char *)s;
	c = 0;
	while (c < (int)n)
	{
		temp[c] = '\0';
		c++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc((count * size) + 1);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
