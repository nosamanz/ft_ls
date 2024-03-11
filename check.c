#include "ft_ls.h"

void ft_error(char *str)
{
	ft_printf("%s", BRED);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

unsigned int check_dir(char **argv, struct stat filestat)
{
	size_t i = 1;
	unsigned int dirCount = 0;
	while (argv[i] != NULL)
	{
		lstat(argv[i], &filestat);
		if (argv[i][0] == '-')
		{
			i++;
			continue;
		}
		else if (filestat.st_mode & S_IFDIR)
			dirCount++;
		i++;
	}
	return dirCount;
}

char check_flags(char **argv, int argc)
{
	char			flags = 0;
	unsigned short	j = 1;

	while (argv[j])
	{
		if (argv[j][0] == '-')
		{
			unsigned short i = 1; // the first char is '-'
			while (argv[j][i] != '\0')
			{
				if (argv[j][i] == '-' || argv[j][i] == ' ')
					ft_error("ls: invalid option -- '-'\nTry 'ls --help' for more information.");
				switch (argv[j][i])
				{
					case 'R' :
						if (!(flags & RFlag))
							flags += RFlag;
						break;
					case 'l':
						if (!(flags & lFlag))
							flags += lFlag;
						break;
					case 'a':
						if (!(flags & aFlag))
							flags += aFlag;
						break;
					case 't':
						if (!(flags & tFlag))
							flags += tFlag;
						break;
					case 'r':
						if (!(flags & lFlag))
 							flags += rFlag;
						break;
					default:
						break;
				}
				i++;
			}
		}
		j++;
	}
	if (flags & RFlag)
		ft_printf("R flag\n");
	if (flags & lFlag)
		ft_printf("l flag\n");
	if (flags & aFlag)
		ft_printf("a flag\n");
	if (flags & tFlag)
		ft_printf("t flag\n");
	if (flags & rFlag)
		ft_printf("r flag\n");

	return flags;
}