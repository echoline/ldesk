#include "bottom.h"
#include <string.h>
// TODO this widget is still called bottom

gchar *hostname;

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
	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_rectangle (cr, 0, 0, width, height);
	cairo_fill (cr);

	// blue left cap
	cairo_set_source_rgb (cr, 0.6, 0.6, 0.8);
	cairo_arc (cr, x, radius, radius, M_PI / 2, 3 * M_PI / 2);
	cairo_rectangle (cr, radius, 0, radius, height);
	cairo_fill (cr);

	// ONLINE
	x += margin * 3;
	cairo_text_extents (cr, hostname, &extents);
	cairo_set_source_rgb (cr, 1, 0.6, 0);
	cairo_move_to (cr, x, height - margin * 2/3);
	cairo_show_text (cr, hostname);
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
	gchar *tmp;

	class->draw = gtk_bottom_draw;

	g_file_get_contents ("/etc/hostname", &tmp, NULL, NULL);
	hostname = g_utf8_strup(tmp, -1);
	g_free (tmp);
	hostname[strcspn(hostname, "\r\n")] = '\0';
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
