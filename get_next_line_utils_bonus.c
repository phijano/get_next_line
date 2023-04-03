/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:54:02 by phijano-          #+#    #+#             */
/*   Updated: 2022/05/13 10:14:01 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	src_size;

	count = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	if (dstsize == 0)
		return (src_size);
	while (src[count] && count < (dstsize - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (src_size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnt_str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		pnt_str = (char *)malloc(sizeof(*pnt_str));
		if (!pnt_str)
			return (NULL);
		pnt_str[0] = '\0';
		return (pnt_str);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	pnt_str = (char *)malloc(sizeof(*pnt_str) * (len + 1));
	if (!pnt_str)
		return (NULL);
	ft_strlcpy(pnt_str, &s[start], len + 1);
	return (pnt_str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count_dst;
	size_t	count_src;

	count_dst = 0;
	count_src = 0;
	while (dst[count_dst])
		count_dst++;
	if (dstsize < count_dst)
	{
		while (src[count_src])
			count_src++;
		return (dstsize + count_src);
	}
	while (dstsize > 0 && count_dst < dstsize - 1 && src[count_src])
		dst[count_dst++] = src[count_src++];
	dst[count_dst] = '\0';
	while (src[count_src++])
		count_dst++;
	return (count_dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*pnt_str;
	int		length;
	char	*temp;

	if (!s1)
	{
		temp = (char *)malloc(sizeof(temp));
		if (!temp)
			return (NULL);
		temp[0] = '\0';
	}
	else
		temp = (char *)s1;
	if (!s2)
		return (NULL);
	length = ft_strlen(temp) + ft_strlen(s2);
	pnt_str = (char *)malloc(sizeof (*pnt_str) * (length + 1));
	if (!pnt_str)
		return (NULL);
	pnt_str[0] = '\0';
	ft_strlcat(pnt_str, temp, ft_strlen(temp) + 1);
	ft_strlcat(pnt_str, s2, length + 1);
	free (temp);
	return (pnt_str);
}
