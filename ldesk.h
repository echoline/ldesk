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
#ifndef __LDESK_H
#define __LDESK_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkLDesk		GtkLDesk;
typedef struct _GtkLDeskClass		GtkLDeskClass;

struct _GtkLDesk
{
	GtkFixed parent;

	/* private */
};

struct _GtkLDeskClass
{
	GtkFixedClass parent_class;
};

#define GTK_TYPE_LDESK		(gtk_ldesk_get_type ())
#define GTK_LDESK(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_LDESK, GtkLDesk))
#define GTK_LDESK_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_LDESK,  GtkLDeskClass))
#define GTK_IS_LDESK(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_LDESK))
#define GTK_IS_LDESK_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_LDESK))
#define GTK_LDESK_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_LDESK, GtkLDeskClass))

GtkWidget* gtk_ldesk_new (gint width, gint height);
void gtk_ldesk_refresh_box (GtkWidget *ldesk);
void gtk_ldesk_update_buttons(GtkWidget *ldesk, gsize index);

#endif // __LDESK_H
