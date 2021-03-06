/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 12:38:51 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:27:46 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/sh.h"

void	free_tab(char **tb)
{
	int i;

	i = -1;
	while (tb[++i])
		free(tb[i]);
	free(tb);
}
