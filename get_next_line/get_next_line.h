/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:04:40 by crmorale          #+#    #+#             */
/*   Updated: 2024/09/23 18:33:26 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char				*save_the_rest(char *save);
char				*make_line_from(char *save);
char				*read_all(int fd, char *save);
char				*read_until_jump(int fd, char *temp, char *save);
char				*get_next_line(int fd);
/*    ---    utils    ---   */
unsigned long int	ft_strlen(char *s);
char				*ft_strcat(char *s1, char *s2);
char				*ft_free_strjoin(char *save, char *temp);
char				*ft_strchr(char *save, int character);
void				*ft_calloc(unsigned long int size, unsigned long int c);
#endif