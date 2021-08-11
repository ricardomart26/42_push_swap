#include "../push_swap.h"

stacks_t	get_av(stacks_t main, char **av)
{
	int	x;
	long int temp;

	x = 1;
	while (av[x])
	{
		temp = ft_atoi(av[x]);
		if (temp > 2147483647 || temp < -21474836478)
        	error_mes();
		main.stackA[x - 1] = (int)temp;
		x++;
	}
	return (main);
}

int	main(int ac, char **av)
{
	stacks_t	main;

	init_struct(&main, ac);
	main = get_av(main, av);
	if (is_valid(main) == 2)
		return (0);
	if (ac < 20)
		main = peanuts(main);
	else
		main = do_easy_one2(main);
}
