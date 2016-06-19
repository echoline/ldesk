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
#include "right.h"
#include "panes.h"

G_DEFINE_TYPE (GtkFiles, gtk_files, GTK_TYPE_BOX);

static gboolean
gtk_files_draw (GtkWidget *files, cairo_t *cr)
{
	cairo_text_extents_t extents;
	gint width = gtk_widget_get_allocated_width (files);
	gint height = gtk_widget_get_allocated_height (files);
	cairo_set_font_size (cr, 20);

	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_rectangle(cr, 0, 0, width, height);
	cairo_fill (cr);

	cairo_set_source_rgb (cr, .8, .4, .4);
	cairo_rectangle (cr, 0, 0, width, 30);
	cairo_fill (cr);

	cairo_set_source_rgb (cr, .8, .6, .8);
	cairo_rectangle (cr, 0, 60, width, 25);
	cairo_fill (cr);

	cairo_set_source_rgb (cr, .6, .6, .8);
	cairo_rectangle (cr, 0, 95, width,
			height - (25 + ((215 + 25) * (NUM_PANES - 1))));
	cairo_rectangle (cr, 0, height - 100, width, 100);
	cairo_fill (cr);

	// black indent
	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_rectangle(cr, 0, 25, 25, height - 50);
	cairo_arc (cr, 0, 25, 25, 0, 2 * M_PI); // TODO
	cairo_arc (cr, 0, height - 25, 25, 0, 2 * M_PI); // TODO
	cairo_fill (cr);

	return TRUE;
}

static void
gtk_files_class_init (GtkFilesClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_files_draw;
}

static void
gtk_files_init (GtkFiles *files)
{
	gtk_widget_set_has_window (GTK_WIDGET (files), FALSE);
}

GtkWidget*
gtk_files_new (void)
{
	GtkWidget *ret = g_object_new (GTK_TYPE_FILES, NULL);

	return ret;
}
