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
#ifndef __STATS_H
#define __STATS_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkStats		GtkStats;
typedef struct _GtkStatsClass		GtkStatsClass;

struct _GtkStats
{
	GtkDrawingArea parent;

	/* private */
};

struct _GtkStatsClass
{
	GtkDrawingAreaClass parent_class;
};

#define GTK_TYPE_STATS		(gtk_stats_get_type ())
#define GTK_STATS(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_STATS, GtkStats))
#define GTK_STATS_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_STATS,  GtkStatsClass))
#define GTK_IS_STATS(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_STATS))
#define GTK_IS_STATS_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_STATS))
#define GTK_STATS_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_STATS, GtkStatsClass))

GtkWidget* gtk_stats_new (void);

#endif // __STATS_H
