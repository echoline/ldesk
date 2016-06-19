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
#include "stats.h"
#include "alrmf.h"
#include <string.h>

G_DEFINE_TYPE (GtkStats, gtk_stats, GTK_TYPE_DRAWING_AREA);

static void
gtk_stats_redraw_canvas (GtkStats *stats)
{
	GtkWidget *widget = GTK_WIDGET (stats);
	GtkAllocation allocation;

	gtk_widget_get_allocation (widget, &allocation);

	gtk_widget_queue_draw_area (widget, allocation.x, allocation.y,
				allocation.width, allocation.height);
}

static gboolean
gtk_stats_update (gpointer data)
{
	GtkStats *stats = GTK_STATS (data);

	gtk_stats_redraw_canvas (stats);

	return TRUE;
}

static gboolean
gtk_stats_draw (GtkWidget *stats, cairo_t *cr)
{
	gint width = gtk_widget_get_allocated_width (stats);
	gint height = gtk_widget_get_allocated_height (stats);
	gdouble radius = height / 2.0;
	cairo_text_extents_t extents;
	gchar *str;
	gchar **strs;
	gchar *ptr;
	gchar *ttr;
	gint i, j, ovf, alrmfoffs;
	gsize len;
	GdkRGBA *color;
	static gint loadavgid;
	static gboolean newalrmfs = TRUE;

	g_file_get_contents ("/proc/loadavg", &str, NULL, NULL);
	g_strstrip (str);

	if (newalrmfs)
		loadavgid = alrmf_new() - 1;

	alrmf_push (loadavgid, str);
	color = alrmf_color (loadavgid);
	alrmfoffs = loadavgid + 1;

	cairo_set_font_size (cr, 25);

	cairo_text_extents (cr, str, &extents);
	cairo_set_source_rgb (cr, color->red, color->green, color->blue);
	g_free (color);
	cairo_move_to (cr, 25, 25);
	cairo_show_text (cr, str);

	g_free (str);

	cairo_set_font_size (cr, 11);
	g_file_get_contents ("/proc/meminfo", &str, NULL, NULL);

	g_strstrip (str);
	strs = g_strsplit (str, "\n", 0);

	if (newalrmfs) for (i = 0; strs[i] != NULL; i++)
		alrmf_new();

	for (i = 0; strs[i] != NULL; i++)
	{
		len = strlen(strs[i]);

		ptr = g_strstr_len(strs[i], -1, ":");
		if (ptr != NULL)
		{
			*ptr = '\0';

			if (ptr < &strs[i][len-1])
			{
				cairo_set_source_rgb (cr, .8, .8, 1);
				cairo_text_extents (cr, strs[i], &extents);
				cairo_move_to (cr, 25, 50 + i * 16);
				cairo_show_text (cr, strs[i]);

				ptr++;
				while (*ptr == ' ')
					ptr++;

				if (*ptr != '\0')
				{
					alrmf_push (alrmfoffs, ptr);
					color = alrmf_color (alrmfoffs++);
					cairo_set_source_rgb (cr, color->red,
								color->green,
								color->blue);
					g_free (color);

					cairo_text_extents (cr, ptr, &extents);
					cairo_move_to (cr, 150, 50 + i * 16);
					cairo_show_text (cr, ptr);
				}
			}
		}
	}

	g_strfreev (strs);
	g_free (str);

	cairo_set_font_size (cr, 13);
	cairo_set_source_rgb (cr, .8, .8, 1);

	gchar *titles[] = { "major", "minor", "filename", "n ok rd",
		"n mrg rd", "n sctr rd", "tm ms rd", "n ok wr",
		"n mrg wr", "n sctr wr", "tm ms wr", "n cur io",
		"tm ms io", "avg ms io", NULL };
	for (i = 0; titles[i] != NULL; i++)
	{
		cairo_move_to (cr, 335 + i * 68, 50);
		cairo_show_text (cr, titles[i]);
	}

	g_file_get_contents ("/proc/diskstats", &str, NULL, NULL);
	g_strstrip (str);
	strs = g_strsplit (str, "\n", 0);

	cairo_set_font_size (cr, 13);

	for (i = 0; strs[i] != NULL; i++)
	{
		ptr = strs[i];

		j = 0;
		ovf = 0;
		do {
			while (*ptr == ' ')
				ptr++;

			if (*ptr != '\0')
			{
				ttr = g_strdup (ptr);
				ttr[strcspn(ttr, " ")] = '\0';

				cairo_text_extents (cr, ttr, &extents);
				cairo_move_to (cr, 350 + j, 71 + i * 21);

				if (extents.width > 58)
				{
					j += extents.width + 10;
					ovf += extents.width - 58;
				}
				else if ((extents.width < 58) && (ovf > 0))
				{
					if (ovf < 58)
					{
						j += 68 - ovf;
						ovf = 0;
					}
					else
					{
						j += extents.width + 10;
						ovf -= 58 - extents.width;
					}
				}
				else
				{
					j += 68;
				}

				if (newalrmfs)
					alrmf_new();

				alrmf_push (alrmfoffs, ttr);
				color = alrmf_color (alrmfoffs++);
				cairo_set_source_rgb (cr, color->red,
							color->green,
							color->blue);
				g_free (color);
				cairo_show_text (cr, ttr);

				g_free(ttr);
			}	
		} while (ptr = g_strstr_len(ptr, -1, " "));
	}

	g_strfreev (strs);
	g_free (str);

	newalrmfs = FALSE;

	return TRUE;
}

static void
gtk_stats_class_init (GtkStatsClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_stats_draw;
}

static void
gtk_stats_init (GtkStats *stats)
{
	gtk_widget_set_has_window (GTK_WIDGET (stats), FALSE);

	gtk_stats_update (stats);

	g_timeout_add (1000, gtk_stats_update, stats);
}

GtkWidget*
gtk_stats_new (void)
{
	return g_object_new (GTK_TYPE_STATS, NULL);
}
