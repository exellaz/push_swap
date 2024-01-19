/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:56:00 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/18 15:41:12 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_nbr(char *result, unsigned int n)
{
	if (n <= 9)
		*result = n + '0';
	else
	{
		*result = ((n % 10) + '0');
		ft_get_nbr(result - 1, n / 10);
	}
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*nbr;
	int		len;

	len = ft_uint_len(n);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	ft_get_nbr(nbr + len - 1, n);
	nbr[len] = '\0';
	return (nbr);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*nbr;

	nbr = ft_unsigned_itoa(n);
	len = ft_print_str(nbr);
	free(nbr);
	return (len);
}
