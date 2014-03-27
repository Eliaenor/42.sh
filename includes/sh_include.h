/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agreau <agreau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 05:35:47 by agreau            #+#    #+#             */
/*   Updated: 2014/03/27 04:44:37 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_INCLUDE_H
# define SH_INCLUDE_H

# include "sh_struct.h"
# include <sys/wait.h>
# include <fcntl.h>
/*
** built-ins/sh_cd.c
*/
int		sh_cd(t_data *st);
/*
** built-ins/sh_exit_echo.c
*/
int		sh_exit(t_data *st);
int		sh_echo(t_data *st);
/*
** env/base_path.c
*/
void	base_env(char **environ, t_data *st);
void	create_envtab(t_data *st, char **environ);
/*
** env/ft_env.c
*/
int		sh_env(t_data *st);
/*
** env/ft_getenv.c
*/
char	*ft_getenv(char **envtab, char *env);
char	**ft_env_dup(char **environ);
int		ft_putenv(t_data *st);
int		ft_tablen(char **tab);
/*
** env/ft_setenv.c
*/
int		set_var_env(t_data *st, char *line);
int		sh_setenv(t_data *st);
/*
** env/ft_unsetenv.c
*/
int		sh_unsetenv(t_data *st);
/*
** exec/sh_builtin.c
*/
int		select_builtin(t_data *st);
int		sh_call_op(t_data *st, t_parse *node);
/*
** exec/sh_exec.c
*/
int		sh_cmd_exec(t_data *st, t_parse *node);
void	sh_split_cmd(t_data *st, t_parse *node);
/*
** exec/sh_call_all_op.c
*/
int		sh_sem(t_data *st, t_parse *node);
int		sh_and(t_data *st, t_parse *node);
int		sh_or(t_data *st, t_parse *node);
/*
** exec/sh_isnobuiltin.c
*/
char	**sh_path_ok(t_data *st);
int		sh_isnobuiltin(t_data *st);
/*
**exec/sh_builtin.c
*/
int		select_builtin(t_data *st);
int		sh_call_op(t_data *st, t_parse *node);
/*
**exec/sh_exec.c
*/
int		sh_cmd_exec(t_data *st, t_parse *node);
void	sh_exec(t_data *st);
/*
**exec/sh_call_op_shell.c
*/
int		sh_sem(t_data *st, t_parse *node);
int		sh_and(t_data *st, t_parse *node);
int		sh_or(t_data *st, t_parse *node);
/*
**exec/sh_call_pipe.c
*/
int		sh_pipe(t_data *st, t_parse *node);
/*
**exec/sh_call_redir.c
*/
int		sh_redir_left(t_data *st, t_parse *node);
int		sh_redir_right(t_data *st, t_parse *node);
int		sh_redir_dbright(t_data *st, t_parse *node);
/*
**exec/sh_isnobuiltin.c
*/
char	**sh_path_ok(t_data *st);
int		sh_isnobuiltin(t_data *st);
/*
** lexer_parser/lexer.c
*/
void	add_to_lex(t_data *st, char *item, int init);
void	sh_lexing(t_data *st);
void	init_lexer(t_data *st, char *item);
/*
** lexer_parser/operator.c
*/
int		is_valid_operator(char *str);
int		detect_ope(char cara);
int		detect_db_ope(t_data *st, int pos, int lex);
/*
** lexer_parser/parser.c
*/
void	sh_parsing(t_data *st);
/*
** termcaps/arrow.c
*/
int		arrow_key(t_data *st, char *buff, int j, char *stdin);
int		up_arrow(t_data *st, int j, char *buff);
int		down_arrow(t_data *st, int j, char *buff);
int		left_arrow(int j);
int		right_arrow(int j, char *buff, t_data *st);
/*
** termcaps/ctrl.c
*/
int		ft_ctrl(t_data *st, char *buff, int j);
int		goto_nextword(char *buff, int j, t_data *st);
int		goto_prevword(char *buff, int j, t_data *st);
/*
** termcaps/delete.c
*/
char	*ft_delete(int j, char *buff);
int		delete_cmd(t_data *st, int j);
int		back_to_j(char *buff, int j);
int		ft_del_line(t_data *st, int curent_line);
char	*bell_for_tab(char *buff, int j);
/*
** termcaps/functions.c
*/
char	**ft_tabdup(char **tbl1);
char	*add_to_tab(char *tbl, char c, int pos);
char	*add_str_to_tab(char *tbl, char *str, int pos);
char	*ft_strcut_end(char const *s, char c);
char	*ft_get_end(char const *s, char c);
/*
** termcaps/get_entry.c
*/
int		ft_get_entry(t_data *st);
int		ft_test(t_data *st, char *buff, int j);
int		ft_test2(t_data *st, char *buff, int j, char *stdin);
char	*ft_test3(t_data *st, char *buff, int *j, char *stdin);
/*
** termcaps/key.c
*/
char	*ascii_key(t_data *st, char *buff, char *stdin, int j);
int		escape_key(t_data *st, char *buff, int j, char *stdin);
int		ft_mini_enter(t_data *st, char *buff);
int		enter_key(t_data *st, char *buff);
/*
** termcaps/prompt.c
*/
void	ft_prompt(t_data *st);
/*
** termcaps/signal.c
*/
int		ft_init_global(t_data *st);
void	sig_ctrl_c(int n);
void	ft_sig_off(void);
/*
** termcaps/term.c
*/
int		init_term(t_data *st);
int		ft_outc(int c);
int		ft_putstr_complete(char *str, t_data *st);
int		ft_putstr_term(char *str, t_data *st);
int		reset_term(t_data *st);
/*
** termcaps/history.c
*/
int		init_history(t_data *st);
char	*get_prev_line(int fd, t_data *st);
char	*get_next_line_m(int fd);
char	*ft_miniread(char *line, char *buff, t_data *st, int fd);
/*
** termcaps/scan.c
*/
char	*ft_scan_buff(char *buff, t_data *st);
char	ft_first_symbol(int j, int k);
char	*ft_seek_symbol(char *buff, t_data *st);
/*
** termcaps/ft_complete.c
*/
int		comp_left_arrow(int j);
int		comp_right_arrow(int j, char *buff, t_data *st);
char	*func1(t_data *st, int *i, char *newbuff, char *stdin);
int		func2(t_data *st, int i, char *newbuff, char *stdin);
/*
** termcaps/tab.c
*/
int		tab_key(t_data *st, char **buff, int j);
int		ft_infolder(t_data *st, char *word, char **comp);
int		get_nbr_match(char *path, char *word, char **comp);
int		set_path_and_word(char **word, char **path);
char	*get_curent_word(char *buff, int i);
/*
** termcaps/tabkey_ls.c
*/
int		exec_ls(t_data *st, char *path, char *word);
char	*get_full_arg_ls(char *word);
int		add_tab_to_buff(char **buff, int j, char *comp, char *word);
char	**get_tbl_ls(char **fullarg);
int		ft_y_or_n(t_data *st, int i, char *path, char *word);

#endif
