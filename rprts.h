#ifndef __RPRTS_H
#define __RPRTS_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkRprts		GtkRprts;
typedef struct _GtkRprtsClass		GtkRprtsClass;

struct _GtkRprts
{
	GtkDrawingArea parent;

	/* private */
};

struct _GtkRprtsClass
{
	GtkDrawingAreaClass parent_class;
};

#define GTK_TYPE_RPRTS		(gtk_rprts_get_type ())
#define GTK_RPRTS(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_RPRTS, GtkRprts))
#define GTK_RPRTS_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_RPRTS,  GtkRprtsClass))
#define GTK_IS_RPRTS(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_RPRTS))
#define GTK_IS_RPRTS_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_RPRTS))
#define GTK_RPRTS_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_RPRTS, GtkRprtsClass))

GtkWidget* gtk_rprts_new (void);

#endif // __RPRTS_H
