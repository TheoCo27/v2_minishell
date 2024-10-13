/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:00:32 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 19:51:04 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_exec(char *str, long nb, int sign, int len)
{
	if (sign == 1)
		str[0] = '-';
	str[len + sign] = '\0';
	while (len > 0)
	{
		str[len - 1 + sign] = (nb % 10) + '0';
		if (str[len - 2 + sign] == '-')
			break ;
		nb = nb / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;
	int		sign;

	sign = 0;
	nb = (long)n;
	if (nb < 0)
	{
		nb = nb * -1;
		sign = 1;
	}
	len = int_len(nb);
	str = (char *)g_malloc((sizeof(char)) * (len + 1 + sign));
	if (!str)
		return (NULL);
	return (ft_exec(str, nb, sign, len));
}
