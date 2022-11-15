#ifndef LSTRING_H
#define LSTRING_H
/* local string related header definations */

/* local function declarations */
int _strcmp(const char *, const char *);
char *concat_string(char **);
ssize_t _strlen(const char *);
int num_of_delim(char *, char *);
char *_strdup(const char *);
ssize_t _fputs(char *, int);
char *end_it(char *, char *);
char **_split(char *, char *);

#endif
