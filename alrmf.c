/*  This file is part of LDesk
 *
 *  LDesk is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  LDesk is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with LDesk.  If not, see <http://www.gnu.org/licenses/>.
 */
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
