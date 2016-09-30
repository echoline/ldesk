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
#include "top.h"

typedef struct _GtkClockPrivate GtkClockPrivate;

struct _GtkClockPrivate
{
	struct tm time;
};

#define GTK_CLOCK_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), GTK_TYPE_CLOCK, GtkClockPrivate))

G_DEFINE_TYPE (GtkClock, gtk_clock, GTK_TYPE_DRAWING_AREA);

static void
gtk_clock_redraw_canvas (GtkClock *clock)
{
	GtkWidget *widget = GTK_WIDGET (clock);
	GtkAllocation allocation;

	gtk_widget_get_allocation (widget, &allocation);

	gtk_widget_queue_draw_area (widget, allocation.x, allocation.y,
				allocation.width, allocation.height);
}

static gboolean
gtk_clock_update (gpointer data)
{
	GtkClock *clock = GTK_CLOCK (data);
	GtkClockPrivate *priv = GTK_CLOCK_GET_PRIVATE (clock);
	time_t timet;

	time (&timet);
	localtime_r (&timet, &priv->time);

	gtk_clock_redraw_canvas (clock);

	return TRUE;
}

static gboolean
gtk_clock_draw (GtkWidget *clock, cairo_t *cr)
{
	gint width = gtk_widget_get_allocated_width (clock);
	gint height = gtk_widget_get_allocated_height (clock);
	gdouble radius = height/2;
	gdouble margin = 10;
	gdouble x = radius;

	cairo_text_extents_t extents;
	GtkClockPrivate *priv = GTK_CLOCK_GET_PRIVATE (clock);
	struct tm *now = &priv->time;
	gchar *nowstr = asctime (now);
	gchar *ptr;

	g_strstrip (nowstr);
	ptr = g_utf8_strup (nowstr, -1);
	nowstr = ptr;

	cairo_set_font_size (cr, height);

	// left cap
	cairo_set_source_rgb (cr, 0.8, 0.4, 0.4);
	cairo_arc (cr, x, radius, radius, M_PI / 2, 3 * M_PI / 2);
	cairo_rectangle (cr, radius, 0, radius, height);
	cairo_fill (cr);

	x += 3 * margin;
	cairo_text_extents (cr, nowstr, &extents);
	cairo_set_source_rgb (cr, 1, 0.6, 0);
	cairo_move_to (cr, x, height - margin * 2/3);
	cairo_show_text (cr, nowstr);
	cairo_fill (cr);

	x += extents.width + margin;
	// right end
	cairo_set_source_rgb (cr, 0.8, 0.4, 0.4);
	cairo_rectangle (cr, x, 0, width - x - radius, height);
	cairo_rectangle (cr, width - radius, radius, radius, height);
	cairo_arc (cr, width - radius, radius, radius, 3 * M_PI / 2, 4 * M_PI / 2);
	cairo_fill (cr);

	return TRUE;
}

static void
gtk_clock_class_init (GtkClockClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_clock_draw;

	g_type_class_add_private (class, sizeof (GtkClockPrivate));
}

static void
gtk_clock_init (GtkClock *clock)
{
	gtk_widget_set_has_window (GTK_WIDGET (clock), FALSE);

	gtk_clock_update (clock);

	g_timeout_add (1000, gtk_clock_update, clock);
}

GtkWidget*
gtk_clock_new (void)
{
	return g_object_new (GTK_TYPE_CLOCK, NULL);
}
