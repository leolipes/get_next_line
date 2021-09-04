/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolipes <leolipes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 23:21:13 by leolipes          #+#    #+#             */
/*   Updated: 2021/09/03 23:30:52 by leolipes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	sub[len] = 0;
	while (len--)
		sub[len] = s[len + start];
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	counts1;
	size_t	counts2;
	size_t	size;
	char	*str;

	counts1 = 0;
	counts2 = 0;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s1[counts1])
	{
		str[counts1] = s1[counts1];
		counts1++;
	}
	while (s2[counts2])
	{
		str[counts1 + counts2] = s2[counts2];
		counts2++;
	}
	str[counts1 + counts2] = 0;
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (i < size * nmemb)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
