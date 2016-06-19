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
#ifndef __CLOCK_H
#define __CLOCK_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkClock		GtkClock;
typedef struct _GtkClockClass		GtkClockClass;

struct _GtkClock
{
	GtkDrawingArea parent;

	/* private */
};

struct _GtkClockClass
{
	GtkDrawingAreaClass parent_class;
};

#define GTK_TYPE_CLOCK		(gtk_clock_get_type ())
#define GTK_CLOCK(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_CLOCK, GtkClock))
#define GTK_CLOCK_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_CLOCK,  GtkClockClass))
#define GTK_IS_CLOCK(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_CLOCK))
#define GTK_IS_CLOCK_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_CLOCK))
#define GTK_CLOCK_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_CLOCK, GtkClockClass))

GtkWidget* gtk_clock_new (void);

#endif // __CLOCK_H
