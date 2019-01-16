/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   term.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 14:18:00 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:38:34 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/sh.h"

int		init_term(t_sh *sh, t_ter *ter)
{
	int i;

	i = 0;
	if ((sh->type = getenv("TERM")) == NULL)
		return (0);
	if ((i = tgetent(NULL, sh->type) <= 0))
	{
		i == 0 ? ft_putstr("terminal type isn't defined in termcap database\n")
			: ft_putstr("couldn't access to the termcap database\n");
		return (0);
	}
	if ((i = tcgetattr(0, ter)) == -1)
		return (0);
	return (1);
}

int		modif_term(t_ter *ter)
{
	ter->c_lflag &= ~(ICANON);
	ter->c_lflag &= ~(ECHO);
	ter->c_cc[VMIN] = 1;
	ter->c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSADRAIN, ter) == -1))
		return (0);
	return (1);
}

int		term(t_sh *sh)
{
	t_ter ter;

	if (!init_term(sh, &ter))
		return (0);
	if (!modif_term(&ter))
	{
		ft_putstr("term settings failed\n");
		return (0);
	}
	return (1);
}
