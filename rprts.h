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
