/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sh.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 15:59:29 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 17:03:31 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>
# include <term.h>
# include <curses.h>
# include <termios.h>
# define ok ft_putendl("OK");

typedef struct termios	t_ter;

typedef struct	s_sh
{
	char		***entry;
	char		*type;
//	struct s_sh	*next;
//	struct s_sh *prev;
}				t_sh;

typedef struct	s_tool
{
	int			cmd;
	int			ret;
	int			buf_pos;
	char		*buf;
	char		tmp[4096];
}				t_tool;

int				main(void);
int				manage_entry(t_sh *sh, t_tool *tool);
void			init_struct(t_sh *sh, t_tool *tool);
void			free_tab(char **tb);
int				term(t_sh *sh);

#endif
