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
