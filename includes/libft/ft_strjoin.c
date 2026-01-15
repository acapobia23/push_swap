/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:24:18 by acapobia          #+#    #+#             */
/*   Updated: 2025/12/29 03:05:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(char const *s1, char const *s2)
{
	int	l_s1;
	int	l_s2;
	int	len;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	len = l_s1 + l_s2;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*new;
	int		len;
	int		i;
	int		j;

	new = NULL;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	len = find_len(s1, s2);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
