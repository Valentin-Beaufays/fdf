/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:36:24 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/10/08 12:36:35 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H	

# include "struct.h"

int		parser(char *file, t_map *map);
void	adapt_map(t_map *map);

#endif
