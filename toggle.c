#include "toggle.h"

void refresh_box ();
extern GtkWidget *panes[];
extern GtkWidget *bttns[];

G_DEFINE_TYPE (GtkSpaceButton, gtk_spacebutton, GTK_TYPE_TOGGLE_BUTTON);

static gboolean
gtk_spacebutton_draw (GtkWidget *spacebutton, cairo_t *cr)
{
	cairo_text_extents_t extents;
	gint width = gtk_widget_get_allocated_width (spacebutton);
	gint height = gtk_widget_get_allocated_height (spacebutton);
	cairo_set_font_size (cr, 20);

	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (
						spacebutton)))
		cairo_set_source_rgb (cr, 1, .6, 0);
	else
		cairo_set_source_rgb (cr, 1, .8, .6);

	cairo_rectangle (cr, 0, 0, width, height);
	cairo_fill (cr);
	cairo_text_extents (cr, gtk_button_get_label (
			GTK_BUTTON (spacebutton)), &extents);
	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_move_to (cr, width - extents.width - 5, extents.height + 5);
	cairo_show_text (cr, gtk_button_get_label (
			GTK_BUTTON (spacebutton)));

	return TRUE;
}

static void
gtk_spacebutton_toggled (GtkWidget *spacebutton, gpointer index)
{
	gint i;

	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (
					bttns[(gsize)index])))
		for (i = 0; i < 3; i++)
		{
			if (i == (gsize)index)
			{
				gtk_widget_show (panes[i]);
				gtk_widget_hide (panes[3]);
			}
			else
			{
				gtk_toggle_button_set_active (
					GTK_TOGGLE_BUTTON (bttns[i]), FALSE);
				gtk_widget_hide (panes[i]);
			}
		}
	else {
		gtk_widget_hide (panes[(gsize)index]);
		gtk_widget_show (panes[3]);
	}

	refresh_box ();
}

static void
gtk_spacebutton_class_init (GtkSpaceButtonClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_spacebutton_draw;
}

static void
gtk_spacebutton_init (GtkSpaceButton *spacebutton)
{
	static gsize index = 0;

	gtk_widget_set_has_window (GTK_WIDGET (spacebutton), FALSE);

	g_signal_connect (spacebutton, "toggled",
			G_CALLBACK (gtk_spacebutton_toggled), (gpointer)index);
	index++;
}

GtkWidget*
gtk_spacebutton_new ()
{
	return g_object_new (GTK_TYPE_SPACEBUTTON, NULL);
}
