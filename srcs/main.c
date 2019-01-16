/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 15:57:27 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 18:24:18 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/sh.h"

void	init_struct(t_sh *sh, t_tool *tool)
{
	sh->entry = NULL;
	sh->type = NULL;
	tool->buf = NULL;
	ft_bzero(tool->tmp, 4096);
	tool->cmd = 0;
	tool->ret = 0;
	tool->buf_pos = 0;
	ft_putstr("$21sh> ");
}

int		manage_entry(t_sh *sh, t_tool *tool)
{
	char	**ret;
	int		i;

	i = 0;
	ret = NULL;
	tool->cmd = ft_ocurences(tool->buf, ';') + 1;
	if (!(sh->entry = malloc(sizeof(char**) * (tool->cmd + 1))))
		return (0);
	ret = ft_strsplit(tool->buf, ';');
	if (tool->cmd >= 1)
	{
		while (i != tool->cmd)
		{
			if (ret[i] == NULL)
			{
				ft_putendl("21sh: parse error near `;;'");
				free_tab(ret);
				return (0);
			}
			sh->entry[i] = ft_split(ret[i]);
			i++;
		}
	}
	free_tab(ret);
	return (1);
}

char	*manage_buf(t_tool *tool)
{
	char *tmp;
//	char *tmp1;

	tmp = ft_strdup(tool->tmp);
	return(tmp);
}

int		main(void)
{
	t_sh	sh;
	t_tool	tool;

	init_struct(&sh, &tool);
	if (!term(&sh))
		return (0);
	while ((tool.ret = read(0, tool.tmp, 4096)) > 0)
	{
		tool.tmp[tool.ret] = '\0';
		tool.buf = manage_buf(&tool);
	//	printf("buf = %s\n", tool.buf);
		if (*tool.tmp == '\n')
			break ;
		*tool.tmp >= 32 && *tool.tmp == 127 ? ft_putstr("del") :
			ft_putchar(*tool.tmp);
//		printf("buf = %s\n", tool.buf);
//		if (!manage_entry(&sh, &tool))
//			return (0);
//		printf("cmd = %d\n", tool.cmd);
		ft_bzero(tool.tmp, 4096);
	}
	printf("tool buf = %s\n", tool.buf);
	return (0);
}
