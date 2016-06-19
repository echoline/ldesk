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
