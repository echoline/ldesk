#include "alrmf.h"

guint nids = 0;
GSList **alrmfs = NULL;

guint
alrmf_new ()
{
	nids++;

	alrmfs = (GSList**)g_realloc(alrmfs, nids * sizeof(GSList*));
	alrmfs[nids - 1] = NULL;

	return (nids);
}

GdkRGBA*
alrmf_color (guint id)
{
	GSList *cur;
	GdkRGBA *ret;
	gboolean plural = FALSE;

	if (id >= nids)
		return NULL;

	ret = g_malloc0 (sizeof (GdkRGBA));
	ret->red = 1;
	ret->green = 0.6;

	cur = alrmfs[id];
	while (cur)
	{
		if (plural == FALSE)
			plural = TRUE;
		else
		{
			if (ret->green < 1)
			{
				ret->green += 0.2;
				ret->blue += 0.5;
			}
			else
				break;
		}

		cur = cur->next;
	}

	return ret;
}

void
alrmf_push (guint id, const char *data)
{
	GSList *cur = alrmfs[id];

	if (id >= nids)
		return;

	if ((cur != NULL) && (!g_strcmp0(data, cur->data)))
	{
		while (cur->next != NULL)
			cur = cur->next;

		alrmfs[id] = g_slist_remove (alrmfs[id], cur->data);
	}
	else
		alrmfs[id] = g_slist_prepend (alrmfs[id], g_strdup (data));
}
