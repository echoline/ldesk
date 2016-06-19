#ifndef __SCREENS_H
#define __SCREENS_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkScreens		GtkScreens;
typedef struct _GtkScreensClass		GtkScreensClass;

struct _GtkScreens
{
	GtkFixed parent;

	/* private */
};

struct _GtkScreensClass
{
	GtkFixedClass parent_class;
};

#define GTK_TYPE_SCREENS		(gtk_screens_get_type ())
#define GTK_SCREENS(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_SCREENS, GtkScreens))
#define GTK_SCREENS_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_SCREENS,  GtkScreensClass))
#define GTK_IS_SCREENS(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_SCREENS))
#define GTK_IS_SCREENS_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_SCREENS))
#define GTK_SCREENS_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_SCREENS, GtkScreensClass))

GtkWidget* gtk_screens_new ();

#endif // __SCREENS_H
