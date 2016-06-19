#ifndef __BOTTOM_H
#define __BOTTOM_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkBottom		GtkBottom;
typedef struct _GtkBottomClass		GtkBottomClass;

struct _GtkBottom
{
	GtkDrawingArea parent;

	/* private */
};

struct _GtkBottomClass
{
	GtkDrawingAreaClass parent_class;
};

#define GTK_TYPE_BOTTOM		(gtk_bottom_get_type ())
#define GTK_BOTTOM(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_BOTTOM, GtkBottom))
#define GTK_BOTTOM_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_BOTTOM,  GtkBottomClass))
#define GTK_IS_BOTTOM(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_BOTTOM))
#define GTK_IS_BOTTOM_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_BOTTOM))
#define GTK_BOTTOM_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_BOTTOM, GtkBottomClass))

GtkWidget* gtk_bottom_new (void);

#endif // __BOTTOM_H
