#ifndef LENV_H
#define LENV_H

/* functions related to the envirometal variables of a process */

/**
 * struct path_l - linked list of the PATH variables of a process.
 * @path: The path.
 * @next: The next element of the list.
 */
struct path_l
{
	char *path;
	struct path_l *next;
};

/**
 * path_l - type defination for struct path_l.
 */
typedef struct path_l path_l;

/* locat functoin declaratoins */
char *_getenv(const char *name);
char **split_path(void);
void _print_path(void);
path_l *init_path(void);
char *is_there(char *, path_l *);

#endif
