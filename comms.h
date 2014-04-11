#ifndef __COMMS_H
#define __COMMS_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkComms		GtkComms;
typedef struct _GtkCommsClass		GtkCommsClass;

struct _GtkComms
{
	GtkDrawingArea parent;

	/* private */
};

struct _GtkCommsClass
{
	GtkDrawingAreaClass parent_class;
};

#define GTK_TYPE_COMMS		(gtk_comms_get_type ())
#define GTK_COMMS(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_COMMS, GtkComms))
#define GTK_COMMS_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_COMMS,  GtkCommsClass))
#define GTK_IS_COMMS(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_COMMS))
#define GTK_IS_COMMS_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_COMMS))
#define GTK_COMMS_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_COMMS, GtkCommsClass))

GtkWidget* gtk_comms_new (void);

#endif // __COMMS_H
