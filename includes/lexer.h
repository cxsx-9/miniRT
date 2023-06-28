/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:32:18 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/28 00:16:42 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "miniRT.h"

int	    check_all(char *name, t_minirt *minirt);
char	**ft_split_white(char *s);
void	free_2d(char **data);
int     check_line(char *line, t_minirt *minirt);

#endif