#include "ft_ls.h"

void print_permissions(struct stat filestat)
{
	ft_printf((S_ISDIR(filestat.st_mode)) ? "d" : "-");
	ft_printf((filestat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf(" ");
}

void print_time(time_t time)
{
	char *etime = ctime(&time);
	uint8_t i = 4;
	uint8_t maxi = ft_strlen(etime) - 9;
	while (i < maxi)
	{
		ft_printf("%c", etime[i]);
		i++;
	}
	write(1, " ", 1);
}