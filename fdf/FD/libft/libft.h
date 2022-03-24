/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:32:23 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/04 13:22:36 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10
# define READ 1
# define READ_EOF 0
# define READ_ERROR -1
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}					t_arr;

int				ft_malloc_p(void **p, size_t len);
int				ft_atoi(const char *s);
int				ft_wdcounter(char const *str, char c);
int				get_next_line(const int fd, char **line);
int				ft_printf(const char *format, ...);
char			*ft_strdup(char *src);
char			**ft_split(char const *str, char c);
char			*ft_strnew(size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *restrict str1, const char *restrict str2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
void			ft_strclr(char *s);
size_t			ft_strlen(char const *s);

#endif
