/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:47:45 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/13 18:43:22 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n1;

	n1 = n;
	if (n1 < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = -n1;
	}
	if (n1 / 10 > 0)
		ft_putnbr_fd(n1 / 10, fd);
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		ft_putchar_fd((n1 % 10) + 48, fd);
}
