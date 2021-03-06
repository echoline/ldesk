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
#include "rprts.h"
#include <string.h>

typedef struct _GtkRprtsPrivate GtkRprtsPrivate;

struct _GtkRprtsPrivate
{
	struct tm time;
};

#define GTK_RPRTS_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), GTK_TYPE_RPRTS, GtkRprtsPrivate))

G_DEFINE_TYPE (GtkRprts, gtk_rprts, GTK_TYPE_DRAWING_AREA);

static void
gtk_rprts_redraw_canvas (GtkRprts *rprts)
{
	GtkWidget *widget = GTK_WIDGET (rprts);
	GtkAllocation allocation;

	gtk_widget_get_allocation (widget, &allocation);

	gtk_widget_queue_draw_area (widget, allocation.x, allocation.y,
				allocation.width, allocation.height);
}

static gboolean
gtk_rprts_update (gpointer data)
{
	GtkRprts *rprts = GTK_RPRTS (data);
	GtkRprtsPrivate *priv = GTK_RPRTS_GET_PRIVATE (rprts);
	time_t timet;

	time (&timet);
	localtime_r (&timet, &priv->time);

	gtk_rprts_redraw_canvas (rprts);

	return TRUE;
}

static gboolean
gtk_rprts_draw (GtkWidget *rprts, cairo_t *cr)
{
	gint width = gtk_widget_get_allocated_width (rprts);
	gint height = gtk_widget_get_allocated_height (rprts);
	cairo_text_extents_t extents;

	cairo_set_font_size (cr, 25);
	cairo_set_source_rgb (cr, 1, .6, 0);

	cairo_text_extents (cr, MODULES_MESSAGE, &extents);
	cairo_move_to (cr, 25, 25);
	cairo_show_text (cr, MODULES_MESSAGE);

	return TRUE;
}

static void
gtk_rprts_class_init (GtkRprtsClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_rprts_draw;

	g_type_class_add_private (class, sizeof (GtkRprtsPrivate));
}

static void
gtk_rprts_init (GtkRprts *rprts)
{
	gtk_widget_set_has_window (GTK_WIDGET (rprts), FALSE);

	gtk_rprts_update (rprts);

	g_timeout_add (1000, gtk_rprts_update, rprts);
}

GtkWidget*
gtk_rprts_new (void)
{
	return g_object_new (GTK_TYPE_RPRTS, NULL);
}
