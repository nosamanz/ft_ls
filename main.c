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

//getgrgid()

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

tFiles* sortByMtime(tFiles* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	tFiles* sortedList = NULL;

	while (head != NULL) {
		tFiles* current = head;
		head = head->next;

		if (sortedList == NULL || current->mtime > sortedList->mtime) {
			current->next = sortedList;
			sortedList = current;
		} else {
			tFiles* temp = sortedList;
			while (temp->next != NULL && current->mtime < temp->next->mtime) {
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}
	}

	tFiles* temp = sortedList;
	while (temp->next != NULL) {
		ft_printf("-->%s\n", temp->name);
		temp = temp->next;
	}

	return sortedList;
}


void pushFile(tFiles** head, void* data, time_t mtime) {
	tFiles* newNode = (tFiles*)malloc(sizeof(tFiles));
	if (newNode == NULL) {
		ft_printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	newNode->name = data;
	if (mtime)
		newNode->mtime = mtime;
	newNode->next = NULL;

	if (*head == NULL) {
		*head = newNode;
	} else {
		tFiles* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

tFiles* reverse(tFiles* head) {
	tFiles* prev = NULL;
	tFiles* current = head;
	tFiles* nextNode;

	while (current != NULL) {
		nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
	}

	return prev;
}

int open_read_dir(char *dirname, char flags)
{
	if (flags & RFlag)
		ft_printf("%s%s:\n", BWHT, dirname);

	struct dirent	*entry;
	struct stat		filestat;
	struct dirName	*dirs;

	unsigned long total = 0;

	tFiles *files = NULL;
	tFiles *directories = NULL;

	char *path;

	DIR *dir = opendir(dirname);
	if (dir == NULL)
	{
		ft_printf("%sError : Directory could not be opened\n", BRED);
		return -1;
	}

	while ((entry = readdir(dir)) != NULL) {
		path = ft_strjoin(ft_strjoin(dirname, "/"), entry->d_name);
		if (lstat(path, &filestat) == -1)
			perror("lstat");
		pushFile(&files, ft_strdup(entry->d_name), filestat.st_mtime);
		if (flags & lFlag)
			total += filestat.st_blocks;
		free(path);
	}

	if (flags & tFlag)
		files = sortByMtime(files);

	if (flags & lFlag)
		ft_printf("total: %d\n", (long)(total / 2));
	if (flags & rFlag)
		files = reverse(files);

	while (files != NULL)
	{
		path = ft_strjoin(ft_strjoin(dirname, "/"), files->name);
		short int a = lstat(path, &filestat);
		if (flags & RFlag
			&& (ft_strncmp(files->name, ".", ft_strlen(files->name)) != 0
			&& ft_strncmp(files->name, "..", ft_strlen(files->name)) != 0))
		{
			if ((filestat.st_mode & S_IFDIR ) && a != -1)
			{
				pushFile(&directories, path, 0);
			}
		}
		if (!(flags & aFlag) && ft_strncmp(files->name, ".", ft_strlen(".")) == 0)
		{
			files = files->next;
			continue;
		}
		if (flags & lFlag)
		{
			print_permissions(filestat);
			ft_printf("%d %s %s\t%d ", filestat.st_nlink, (getpwuid(filestat.st_uid)->pw_name), (getgrgid(filestat.st_gid)->gr_name), filestat.st_size);
			if (ft_strlen(ft_itoa(filestat.st_size)) < 5)
				ft_printf("\t");
			print_time(filestat.st_mtime);
		}
		ft_printf("%s%s\n", BBLU, files->name);
		files = files->next;
		free(path);
	}
	if (flags & rFlag || flags & RFlag)
	{
		directories = reverse(directories);
	}
	while (directories != NULL)
	{
		open_read_dir(directories->name, flags);
		directories = directories->next;
	}
	closedir(dir);
	return 1;
}

int main(int argc, char **argv)
{
	ft_printf("%sFT_LS is runing!\n", BYEL);

	DIR *dir;
	struct dirent	*entry;
	struct stat		filestat;
	char			flags = 0;

	char **dirs = NULL;

	struct passwd	*passwd;

	t_list *dirNames = NULL;


	flags = check_flags(argv,argc);

	size_t i = argc - 1;
	while (i > 0)
	{
		if (argv[i][0] != '-' && lstat(argv[i], &filestat) != -1)
		{
			if (filestat.st_mode & S_IFDIR)
				push(&dirNames, ft_strdup(argv[i]));
		}
		else if (argv[i][0] != '-'){
			ft_printf("%s", BRED);
			perror("ls");
		}
		i--;
	}

	if (argc == 1 || dirNames == NULL)
	{
		push(&dirNames, ".");
	}

	while (dirNames != NULL)
	{
		if (argc > 2)
			ft_printf("%s%s:\n", BWHT,(char *)dirNames->data);
		open_read_dir(dirNames->data, flags);
		dirNames = dirNames->next;
	}

	return 1;
}
