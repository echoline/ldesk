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
#include "bottom.h"

G_DEFINE_TYPE (GtkBottom, gtk_bottom, GTK_TYPE_DRAWING_AREA);

static gboolean
gtk_bottom_draw (GtkWidget *bottom, cairo_t *cr)
{
	gint width = gtk_widget_get_allocated_width (bottom);
	gint height = gtk_widget_get_allocated_height (bottom);
	gdouble radius = height/2;
	gdouble margin = 10;
	gdouble x = radius;

	cairo_text_extents_t extents;
	cairo_set_font_size (cr, height);

	// blue left cap
	cairo_set_source_rgb (cr, 0.6, 0.6, 0.8);
	cairo_arc (cr, x, radius, radius, M_PI / 2, 3 * M_PI / 2);
	cairo_rectangle (cr, radius, 0, radius, height);
	cairo_fill (cr);

	// ONLINE
	x += margin * 3;
	cairo_text_extents (cr, "CONSOLE X11", &extents);
	cairo_set_source_rgb (cr, 1, 0.6, 0);
	cairo_move_to (cr, x, height - margin * 2/3);
	cairo_show_text (cr, "CONSOLE X11");
	cairo_fill (cr);

	// moar blue
	x += extents.width + margin;
	cairo_set_source_rgb (cr, 0.6, 0.6, 0.8);
	cairo_rectangle (cr, x, 0, width - x - radius, height);
	cairo_rectangle (cr, width - radius, 0, radius, radius);
	cairo_arc (cr, width - radius, radius, radius, 2 * M_PI, 5 * M_PI / 2);
	cairo_fill (cr);

	return TRUE;
}

static void
gtk_bottom_class_init (GtkBottomClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_bottom_draw;
}

static void
gtk_bottom_init (GtkBottom *bottom)
{
	gtk_widget_set_has_window (GTK_WIDGET (bottom), FALSE);
}

GtkWidget*
gtk_bottom_new (void)
{
	return g_object_new (GTK_TYPE_BOTTOM, NULL);
}
