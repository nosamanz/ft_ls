#ifndef FT_LS_H
# define FT_LS_H

//0 0 0 0 0
//R l a t r

// 0  0  0  0  0 0 0 0
//128 64 32 16 8 4 2 1
// 0   0  0  0  0
// R   l  a  t  r
//+16 +8 +4 +2 +1

#define RFlag 16
#define lFlag 8
#define aFlag 4
#define tFlag 2
#define rFlag 1

#include "./libft/headers/libft.h"
//opendir
#include <dirent.h>
//perror
#include <errno.h>
//stat
#include <sys/stat.h>

//listxattr
#include <sys/types.h>

//getpwuid
#include <sys/types.h>
#include <pwd.h>

//getgrgid
#include <grp.h>

//bool
#include <stdbool.h>

//uint8_t
#include <stdint.h>
//delete this
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>

//strerror
#include <errno.h>
#include <string.h>

typedef struct sFiles
{
	char	*name;
	time_t	mtime;
	struct sFiles 	*next;
} tFiles;

//check
void			ft_error(char *str);
char			check_flags(char **argv);
unsigned int	check_dir(char **argv, struct stat filestat);
//print
void			print_permissions(struct stat filestat);
void			print_time(time_t time);
void			print_file(char *filename, char flags, struct stat filestat);
//utils
tFiles			*sortByMtime(tFiles *head);
void			pushFile(tFiles **head, void *data, time_t mtime);
void			reverse(tFiles **head_ref);
void			remove_last_slashes(char *str);
//flags
tFiles			*flag_edit(char flags, tFiles *files, char *dirname, unsigned long total, unsigned int dir_count);
void			l_flag(struct stat filestat);
#endif