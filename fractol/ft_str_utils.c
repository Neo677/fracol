/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:31:14 by thobenel          #+#    #+#             */
/*   Updated: 2024/10/14 13:31:15 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncompare(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

/*
ALPHA TO DOUBLE
 similaire a atoi mais il gere avec des float
 prend argument de args et convertie
 en long double (typedef ldbl)
 */

double	ft_atodbl(char *s)
{
	long	i;
	double	nb;
	double	y;
	int		sign;

	i = 0;
	nb = 0;
	sign = +1;
	y = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s >= '0' && *s <= '9')
		i = (i * 10) + (*s++ - '0');
	if ('.' == *s)
		++s;
	while (*s >= '0' && *s <= '9')
	{
		y /= 10;
		nb = nb + (*s++ - '0') * y;
	}
	return ((i + nb) * sign);
}
