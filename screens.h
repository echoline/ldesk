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
