#include "comms.h"
#include "alrmf.h"
#include <string.h>

G_DEFINE_TYPE (GtkComms, gtk_comms, GTK_TYPE_DRAWING_AREA);

static void
gtk_comms_redraw_canvas (GtkComms *comms)
{
	GtkWidget *widget = GTK_WIDGET (comms);
	GtkAllocation allocation;

	gtk_widget_get_allocation (widget, &allocation);

	gtk_widget_queue_draw_area (widget, allocation.x, allocation.y,
				allocation.width, allocation.height);
}

static gboolean
gtk_comms_update (gpointer data)
{
	GtkComms *comms = GTK_COMMS (data);

	gtk_comms_redraw_canvas (comms);

	return TRUE;
}

static gboolean
gtk_comms_draw (GtkWidget *comms, cairo_t *cr)
{
	gint width = gtk_widget_get_allocated_width (comms);
	gint height = gtk_widget_get_allocated_height (comms);
	gchar *contents;
	gchar **lines;
	gchar **fields;
	gint x, y, xoffs, i, j;
	static gint alrmf0 = -1;
	gint alrmfoffs = alrmf0;
	GdkRGBA *color;

	cairo_set_font_size (cr, 13);

	x = y = 50;

	g_file_get_contents ("/proc/net/dev", &contents, NULL, NULL);
	lines = g_strsplit (contents, "\n", -1);
	g_free (contents);

	cairo_set_source_rgb (cr, .8, .8, 1);
	cairo_move_to (cr, x, y);
	cairo_show_text (cr, "Received");
	x += 720;
	cairo_move_to (cr, x, y);
	cairo_show_text (cr, "Transmitted");
	y += 16;
	cairo_move_to (cr, 42, y);
	cairo_show_text (cr, "'");
	for (i = 1; lines[i] != NULL && i != 2; i++)
	{
		fields = g_strsplit_set (lines[i], " |", -1); 
		x = 50;
		for (j = 0; fields[j] != NULL; j++)
		{
			g_strstrip(fields[j]);
			if (fields[j][0] != '\0')
			{
				cairo_move_to (cr, x, y);
				cairo_show_text (cr, fields[j]);

				x += 80;
			}
		}
		g_strfreev(fields);
		y += 16;
		// hope ur not too slow, funcy...?
		cairo_set_source_rgb (cr, 1, .6, 0);
	}

	g_strfreev(lines);

	return TRUE;
}

static void
gtk_comms_class_init (GtkCommsClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_comms_draw;
}

static void
gtk_comms_init (GtkComms *comms)
{
	gtk_widget_set_has_window (GTK_WIDGET (comms), FALSE);

	gtk_comms_update (comms);

	g_timeout_add (1000, gtk_comms_update, comms);
}

GtkWidget*
gtk_comms_new (void)
{
	return g_object_new (GTK_TYPE_COMMS, NULL);
}
