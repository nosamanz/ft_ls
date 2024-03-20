// -R flag : show subdirectories

// -l flag : show long format

// -a flag : show hidden files

// -r flag : reverse sort

// -t flag : sort by time modified

// ********************************************************************************** //

// struct dirent {
//     ino_t          d_ino;       /* inode number */
//     off_t          d_off;       /* offset to the next dirent */
//     unsigned short d_reclen;    /* length of this record */
//     unsigned char  d_type;      /* type of file */
//     char           d_name[256]; /* filename */
// };

// ********************************************************************************** //

// getpwnam()

// The getpwnam() function returns a pointer to a structure containing the broken-out fields of the record in
// the password database (e.g., the local password file /etc/passwd, NIS, and LDAP) that matches the username name.
// The getpwuid() function returns a pointer to a structure containing the broken-out fields of the record in the password database that matches the user ID uid.

// The passwd structure is defined in <pwd.h> as follows:
// struct passwd {
//     char   *pw_name;       /* username */
//     char   *pw_passwd;     /* user password */
//     uid_t   pw_uid;        /* user ID */
//     gid_t   pw_gid;        /* group ID */
//     char   *pw_gecos;      /* user information */
//     char   *pw_dir;        /* home directory */
//     char   *pw_shell;      /* shell program */
// };

//-----------------------

// getgrgid()

// The getgrgid() function returns a pointer to a structure containing the broken-out fields of the record in the group database that matches the group ID gid.
// The group structure is defined in <grp.h> as follows:

// struct group {
//     char   *gr_name;       /* group name */
//     char   *gr_passwd;     /* group password */
//     gid_t   gr_gid;        /* group ID */
//     char  **gr_mem;        /* group members */
// };

// ********************************************************************************** //

// stat()
// stat() stats the file pointed to by path and fills in buf.
// lstat() is identical to stat(), except that if path is a symbolic link, then the link itself is stat-ed, not the file that it refers to.

// struct stat {
//     dev_t     st_dev;     /* ID of device containing file */
//     ino_t     st_ino;     /* inode number */
//     mode_t    st_mode;    /* protection */
//     nlink_t   st_nlink;   /* number of hard links */
//     uid_t     st_uid;     /* user ID of owner */
//     gid_t     st_gid;     /* group ID of owner */
//     dev_t     st_rdev;    /* device ID (if special file) */
//     off_t     st_size;    /* total size, in bytes */
//     blksize_t ; /* blocksize for file system I/O */
//     blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
//     time_t    st_atime;   /* time of last access */
//     time_t    st_mtime;   /* time of last modification */
//     time_t    st_ctime;   /* time of last status change */
// };

// ********************************************************************************** //

#include "ft_ls.h"

tFiles *take_files(char *dirname, unsigned long *total, struct stat filestat, char flags)
{
	char *path;
	char *temp;
	struct dirent *entry;
	tFiles *files;
	files = NULL;
	DIR *dir;
	dir = opendir(dirname);

	if (dir == NULL)
	{
		ft_printf("%sError : Directory could not be opened\n", BRED);
		return NULL;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		temp = ft_strjoin(dirname, "/");
		path = ft_strjoin(temp, entry->d_name);
		if (lstat(path, &filestat) == -1)
		{
			perror("lstat");
		}
		free(temp);
		free(path);
		if (!(flags & aFlag) && ft_strncmp(entry->d_name, ".", ft_strlen(".")) == 0)
			continue;
		pushFile(&files, ft_strdup(entry->d_name), filestat.st_mtime);
		if (flags & lFlag)
			*total += filestat.st_blocks;
	}
	closedir(dir);
	return files;
}

tFiles *take_directories(tFiles *files, tFiles *directories, char *dirname, char flags)
{
	char *path;
	char *temp;
	struct stat filestat;

	while (files != NULL)
	{
		temp = ft_strjoin(dirname, "/");
		path = ft_strjoin(temp, files->name);
		free(temp);
		short int a = lstat(path, &filestat);
		if (flags & RFlag && (ft_strncmp(files->name, ".", ft_strlen(files->name)) != 0 && ft_strncmp(files->name, "..", ft_strlen(files->name)) != 0))
		{
			if ((filestat.st_mode & S_IFDIR) && a != -1)
				pushFile(&directories, ft_strdup(path), 0);
		}
		free(path);
		if (!(flags & aFlag) && ft_strncmp(files->name, ".", ft_strlen(".")) == 0)
		{
			free(files->name);
			files = files->next;
			continue;
		}
		if (flags & lFlag)
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
		ft_printf("%s%s\n", BGRN, files->name);
		void *next = files->next;
		free(files->name);
		free(files);
		files = next;
	}
	return directories;
}

void open_read_dir(char *dirname, char flags, unsigned int dir_count)
{
	if (flags & RFlag)
		ft_printf("%s%s:\n", BWHT, dirname);
	struct stat filestat;
	unsigned long total = 0;
	tFiles *files = NULL;
	tFiles *directories = NULL;

	files = take_files(dirname, &total, filestat, flags);

	if (flags & tFlag)
		files = sortByMtime(files);
	// if given multiple directories, print the directory name
	if (dir_count > 1)
		ft_printf("%s:\n", dirname);
	if (flags & lFlag)
		ft_printf("total: %d\n", (long)(total / 2));
	if (flags & rFlag)
		reverse(&files);
	directories = take_directories(files, directories, dirname, flags);
	if (flags & rFlag || flags & RFlag)
		reverse(&directories);
	while (directories != NULL)
	{
		open_read_dir(directories->name, flags, dir_count);
		void *next = directories->next;
		free(directories->name);
		free(directories);
		directories = next;
	}
}

unsigned int dir_args(size_t i, char **argv, t_list **dirNames)
{
	struct stat filestat;
	unsigned int counter = 0;
	while (i > 0)
	{
		if (argv[i][0] != '-' && lstat(argv[i], &filestat) != -1)
		{
			if (filestat.st_mode & S_IFDIR)
			{
				push(dirNames, argv[i]);
				counter++;
			}
		}
		else if (argv[i][0] != '-')
		{
			ft_printf("%s", BRED);
			perror("ls");
			counter++;
		}
		i--;
	}
	return counter;
}

int main(int argc, char **argv)
{
	ft_printf("%sFT_LS is runing!\n", BYEL);

	char flags;
	t_list *dirNames;
	unsigned int dir_count = 0;

	dirNames = NULL;

	flags = 0;
	flags = check_flags(argv);

	if (argc > 1)
		dir_count = dir_args((size_t)argc - 1, argv, &dirNames);

	if (argc == 1 || dirNames == NULL)
		push(&dirNames, ".");

	while (dirNames != NULL)
	{
		open_read_dir(dirNames->data, flags, dir_count);
		void *next = dirNames->next;
		free(dirNames);
		dirNames = next;
	}

	return 1;
}
