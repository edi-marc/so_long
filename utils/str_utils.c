/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:58:11 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/13 16:14:43 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	get_next_line modified and reduced only for read the map
*/

#include "libft.h"

static void	helper(char *new_a, int i)
{
	if (new_a[i - 1] == '\n')
		new_a[i - 1] = '\0';
	new_a[i] = '\0';
}

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i;

	i = 0;
	a[i] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\n' || !a[i])
			break ;
		i++;
	}
	if (a[0] == '\n' || !a[0])
		return (NULL);
	new_a = malloc(i + 1);
	if (!new_a)
		return (NULL);
	i = -1;
	while (a[++i])
		new_a[i] = a[i];
	helper(new_a, i);
	return (new_a);
}
