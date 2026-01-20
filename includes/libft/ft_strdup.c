/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:24:14 by acapobia          #+#    #+#             */
/*   Updated: 2026/01/16 23:17:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		len;

	if (!s)  // 🚨 Prevents a segfault if s is NULL
		return (NULL);

	len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);

	i = 0;
	while (i < len)  // No need to call ft_strlen inside the loop
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main()
// {
// 	char *s1 = "\nollare_the_gang";
// 	char *s2 = ft_strdup(s1);
// 	printf("%s", s2);
// 	free(s2);
// 	return 0;
// }
