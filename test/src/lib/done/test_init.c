/**
 * init_path - initialize a linked list of the path variables
 * of a the system.
 *
 * Return: The head of the list (success), NULL (error).
 */
path_l *init_path(void)
{
        char **paths = NULL;
        path_l *path_h = NULL, *tmp = NULL;
        int i;

        paths = split_path();
        if (paths == NULL)
                return (NULL);
        path_h = malloc(sizeof(path_l));
        if (path_h == NULL)
                return (NULL);
        for (i = 2, tmp = path_h; ; i++, tmp = tmp->next)
        {
                tmp->path = paths[i];
                if (paths[i + 1] != NULL)
                {
                        tmp->next = malloc(sizeof(path_l));
                        if (tmp->next == NULL)
                                return (NULL);
                }
                else
                {
                        tmp->next = NULL;
                        break;
                }
        }
        free_darray(paths);
        return (path_h);
}

