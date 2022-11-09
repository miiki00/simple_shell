#include "main.h"

/**
 * num_of_delim - calculates the no of existence of given delimeteres
 * in a given string.
 * @str: The string to search delimeters in.
 * @delim: The delimeteres to search on the string.
 *
 * Return: The number of delimeteres int the string (success)
 * -1 (error).
 */
int num_of_delim(char *str, char *delim)
{
	int i, j, num_delim = 0;

	if (str == NULL || delim == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
		for (j = 0; delim[j] != '\0'; j++)
			if (str[i] == delim[j])
				num_delim++;
	return (num_delim);
}

/**
 * delim_indexs - searches for the indexs of delimeters
 * in a string and returns array of indexs of the delimeters.
 * @str: The string to search delimeters in.
 * @delim: The delimeters to search for.
 * Description: The array returned is terminated by -1 thinking
 * that there is no -1 in indexing.
 *
 * Return: The array of the indexs of the delimeters (success)
 * NULL (error) no matching delims found or invalid input.
 */
int *delim_indexs(char *str, char *delim)
{
	unsigned int idx, i, j;
	int *indexs = NULL;

	if ( str == NULL || delim == NULL)
		return (NULL);
	if ((i = num_of_delim(str, delim)) == 0)
		return (NULL);
	indexs = malloc(sizeof(int) * i + 1);
	if (indexs == NULL)
		return (NULL);
	for (i = 0, idx = 0; str[i] != '\0'; i++)
		for (j = 0; delim[j] != '\0'; j++)
			if (str[i] == delim[j])
			{
				indexs[idx] = i;
				idx++;
				break;
			}
	indexs[idx] = -1;
	return (indexs);
}

/**
 * extract_len - extrancts the valid lengths in a given string
 * to be splited with a fiven delimeters.
 * @delim: The index of the delimeters in the string.
 * @ndelim: The number of delimeters in the string.
 *
 * Return: The array of the valid lengths in the string. (success)
 * NULL (error)
 */
int *extract_len(int *delim, int ndelim)
{
	int i, j, idx, tmp;
	int *len;

	if (delim == NULL || ndelim < 2)
		return (NULL);
	len = malloc(sizeof(char *) * ndelim + 1);
	if (len == NULL)
		return (NULL);
	for (j = 1, i = idx = 0; delim[j] != -1; j++, i++)
	{
		if (i == 0 && (tmp = delim[i] + 1) > 1)
			len[idx++] = tmp;
		else if ((tmp = delim[j] - delim[i]) > 1)
			len[idx++] = tmp;
        }
        len[idx] = -1;
        return (len);
}

/**
 * main - test the code.
 * @ac: The number of argumets.
 * @av: NULL terminated array of strings passed to main as argumet.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *p = "mi ki kk jj";
	int len, *tmp, *tmp2, i;

	len = num_of_delim(p, " ");
	printf("%d: number of delimeters in:\n%s\n", len, p);
	tmp = delim_indexs(p, " ");
	for (i = 0; tmp[i] != -1; i++)
		printf("idx[%d] = %d\n", i, tmp[i]);
	tmp2 = extract_len(tmp, len);
	printf("length of every string in the middle excluding the delimeters\n");
	for (i = 0; tmp2[i] != -1; i++)
		printf("idx[%d] = %d\n", i, tmp2[i] - 1);
	return (0);
}
