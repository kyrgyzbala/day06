#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(char **argv, int l, int h)
{
	char	x;
	int	i;
	int	j;

	x = argv[h][0];
	i = (l - l);
	j = 1;
	while (j <= h - 1)
	{
		if (argv[j][0] <= x)
		{
			i++;
			swap((&argv[i]), (&argv[j]));
		}
		j++;
	}
	swap((&argv[i + 1]), (&argv[h]));
	return (i + 1);
}

void	quick_sort(char **argv, int l, int h)
{
	int	p;

	if (l < h)
	{
		p = partition(argv, l, h);
		quick_sort(argv, l, p - 1);
		quick_sort(argv, p + 1, h);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	quick_sort(argv, 1, argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return 0;
}
