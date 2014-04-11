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
