#include "ft_ls.h"

tFiles	*flag_edit(char flags, tFiles *files, char *dirname, unsigned long total, unsigned int dir_count)
{
	// if given multiple directories, print the directory name
	if (dir_count > 1 || (flags & RFlag))
		ft_printf("%s%s%s:\n", BWHT, dirname, RESET);
	if (flags & tFlag)
		files = sortByMtime(files);
	if (flags & lFlag)
		ft_printf("total: %d\n", (long)(total / 2));
	if (flags & rFlag)
		reverse(&files);
	return files;
}

void	l_flag(struct stat filestat)
{
	ft_printf("%s", BBLU);
	print_permissions(filestat);
	ft_printf("%d %s %s\t%d ", filestat.st_nlink, (getpwuid(filestat.st_uid)->pw_name), (getgrgid(filestat.st_gid)->gr_name), filestat.st_size);
	char *st_str = ft_itoa(filestat.st_size);
	if (ft_strlen(st_str) < 6)
		ft_printf("\t");
	free(st_str);
	print_time(filestat.st_mtime);
}