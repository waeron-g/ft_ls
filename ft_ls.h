/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waeron-g <waeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:43:04 by waeron-g          #+#    #+#             */
/*   Updated: 2019/06/10 17:20:24 by waeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <sys/ioctl.h>

/* 
	I forgot this struct, but it important
*/
typedef struct s_ls
{
	DIR				*fld;
	struct dirent	*entry;
	struct stat		buf;
} 				t_ls;

typedef struct s_path
{
	char	*path;
	struct stat stat;
}				t_path;

typedef struct s_file
{
	char			*mode;
	int				lnk;
	uid_t			usr;
	gid_t			grp;
	struct timespec	la; /*last access*/
	struct timespec	lm; /*last modified*/
	struct timespec	ls; /*last status*/
	int				blk;
	long long int	size;
	char			*name;
}				t_file;

/*List control functions*/
void *addir(void *str);
void deldir(void **cont);
void *set_params(void *rd);
void del_pars(void **rd);
void get_params(t_imp **list, t_ls *rd);
/*Sort functions*/
int s_name(void *lst1, void *lst2);
int s_pt(void *str1, void *str2);
int s_ls(void *lst1, void *lst2);
int s_la(void *lst1, void *lst2);
int s_lm(void *lst1, void *lst2);
int s_nm(void *str1, void *str2);
/*input funcs*/
int get_args(int gc, char **gv, t_imp **path, char **flags);
void output(t_imp **params, char *flags, int sum);
/*sub funcs*/
int find(char *str1, char *str2);
void sort_by_flags(t_imp **list, char *flags);
void printwspaces(int sz);
void printword(char *str);
void printnum(int nbr);
char *get_time(t_file *buf, char *flags);
/*other funcs*/
int read_folders(char **path, char *flags);
char *get_mode(struct stat file);
void recursion(t_imp **folds, char *flags);
char *changepath(char *path);
void printbuf(char *buffer, int sum, char *flags);
void get_dirs(t_imp **folds, t_ls *rd, char *path, char *flags);
int calcblock(int sum, char *flags, char *name, int size);
void printdirs(t_file *buf, char *flags, int *size);
#endif
