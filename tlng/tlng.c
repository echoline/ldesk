#include "tlng.h"
#include <string.h>

char*
tlng_translit_str (char *str)
{
	int len = strlen (str);
	char **imgs = malloc (sizeof (char*));;
	char *ret;
	int retlen = 0;
	int i, j, k;
	int offset = 0;
	char *ptr;
	char track;

	imgs[0] = NULL;

	for (i = 0; i < len; i++)
	{
		j = 0;

		while (tlng_letters[j].ltr != NULL)
		{
			track = 0;
			k = 0;

			do {
				if (tlng_letters[j].ltr[k] == str[i])
					track = 1;
				else
					track = 0;

				k++;
			} while (tlng_letter[j].ltr[k] != '\0');

			if (track) {
			}
		}

		offset += 34;
	}
}

