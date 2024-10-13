/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:53:53 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 12:46:24 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	get_size(int nb)
{
	int	s;

	s = 1;
	while (nb > 9)
	{
		nb /= 10;
		s++;
	}
	return (s);
}

static void	ft_strrev(char *s)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		temp = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = temp;
		i++;
		j--;
	}
}

static void	fill_string(char *s, int nb, int sign, int i)
{
	while (nb > 9)
	{
		*(s + i) = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	*(s + i) = nb + '0';
	i++;
	if (sign == 1)
	{
		*(s + i) = '-';
		i++;
	}
	*(s + i) = '\0';
	ft_strrev(s);
}

static void	init_int_min(char *s)
{
	*(s) = '-';
	*(s + 1) = '2';
	*(s + 2) = '1';
	*(s + 3) = '4';
	*(s + 4) = '7';
	*(s + 5) = '4';
	*(s + 6) = '8';
	*(s + 7) = '3';
	*(s + 8) = '6';
	*(s + 9) = '4';
	*(s + 10) = '8';
	*(s + 11) = '\0';
}

char	*pft_itoa(int n, t_state *state)
{
	int		sign;
	char	*s;

	sign = 0;
	if (n == -2147483648)
	{
		s = ft_malloc(sizeof(char) * 12, &(state->gc), state);
		if (!s)
			return (NULL);
		init_int_min(s);
		return (s);
	}
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	s = ft_malloc(sizeof(char) * (get_size(n) + sign + 1), &(state->gc), state);
	if (!s)
		return (NULL);
	fill_string(s, n, sign, 0);
	return (s);
}
