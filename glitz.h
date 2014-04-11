#ifndef __GLITZ_H
#define __GLITZ_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkGlitz		GtkGlitz;
typedef struct _GtkGlitzClass		GtkGlitzClass;

struct _GtkGlitz
{
	GtkDrawingArea parent;

	/* private */
};

struct _GtkGlitzClass
{
	GtkDrawingAreaClass parent_class;
};

#define GTK_TYPE_GLITZ		(gtk_glitz_get_type ())
#define GTK_GLITZ(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_GLITZ, GtkGlitz))
#define GTK_GLITZ_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_GLITZ,  GtkGlitzClass))
#define GTK_IS_GLITZ(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_GLITZ))
#define GTK_IS_GLITZ_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_GLITZ))
#define GTK_GLITZ_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_GLITZ, GtkGlitzClass))

GtkWidget* gtk_glitz_new (void);

#endif // __GLITZ_H
