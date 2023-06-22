/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:55:33 by dcolucci          #+#    #+#             */
/*   Updated: 2022/10/15 15:28:04 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*p;
	unsigned char	u;

	p = 0;
	i = 0;
	u = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == u)
			p = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (p);
}
