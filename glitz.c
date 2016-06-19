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
#include "glitz.h"
#include "image.h"

static char *lines[] = { "ALL SYSTEMS TREKKED OUT",
			 "(AUTHOR OF PICTURE NOT ON FILE:",
			 "PLEASE CONTACT ME FOR RECOGNITION)",
			NULL };

G_DEFINE_TYPE (GtkGlitz, gtk_glitz, GTK_TYPE_DRAWING_AREA);

static gboolean
gtk_glitz_draw (GtkWidget *glitz, cairo_t *cr)
{
	GdkPixbuf *pixbuf;
	gint x, y, i;
	gint width = gtk_widget_get_allocated_width (glitz);
	gint height = gtk_widget_get_allocated_height (glitz);
	cairo_text_extents_t extents;

	pixbuf = gdk_pixbuf_new_from_xpm_data ((const char**)image_xpm);
	x = 100;
	y = (height - gdk_pixbuf_get_height (pixbuf) - 100) / 2;
	gdk_cairo_set_source_pixbuf (cr, pixbuf, x, y);
	cairo_paint (cr);

	x += gdk_pixbuf_get_width (pixbuf);
	y += 100;
	cairo_set_source_rgb (cr, 1, .6, 0);
	cairo_set_font_size (cr, 30);
	i = 0;
	while (lines[i])
	{
		cairo_move_to (cr, x, y);
		cairo_text_extents (cr, lines[i], &extents);
		cairo_show_text (cr, lines[i]);
		y += 40;
		i++;
	}

	g_object_unref (pixbuf);

	return FALSE;
}

static void
gtk_glitz_class_init (GtkGlitzClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_glitz_draw;
}

static void
gtk_glitz_init (GtkGlitz *glitz)
{
	gtk_widget_set_has_window (GTK_WIDGET (glitz), FALSE);
}

GtkWidget*
gtk_glitz_new (void)
{
	return g_object_new (GTK_TYPE_GLITZ, NULL);
}
