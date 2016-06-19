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
#ifndef __SPACEBUTTON_H
#define __SPACEBUTTON_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkSpaceButton		GtkSpaceButton;
typedef struct _GtkSpaceButtonClass		GtkSpaceButtonClass;

struct _GtkSpaceButton
{
	GtkToggleButton parent;

	/* private */
};

struct _GtkSpaceButtonClass
{
	GtkToggleButtonClass parent_class;
};

#define GTK_TYPE_SPACEBUTTON		(gtk_spacebutton_get_type ())
#define GTK_SPACEBUTTON(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_SPACEBUTTON, GtkSpaceButton))
#define GTK_SPACEBUTTON_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_SPACEBUTTON,  GtkSpaceButtonClass))
#define GTK_IS_SPACEBUTTON(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_SPACEBUTTON))
#define GTK_IS_SPACEBUTTON_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_SPACEBUTTON))
#define GTK_SPACEBUTTON_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_SPACEBUTTON, GtkSpaceButtonClass))

GtkWidget* gtk_spacebutton_new ();

#endif // __SPACEBUTTON_H
