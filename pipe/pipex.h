/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:02:44 by wsaturn           #+#    #+#             */
/*   Updated: 2021/12/10 22:28:45 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

char	*path_join(char *path, char *bin);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_strchr(char *str, char c);
char	*ft_strndup(char *str, unsigned int n);
char	**ft_split(char *str, char sep);

#endif
