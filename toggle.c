#include "toggle.h"
#include "ldesk.h"

typedef struct _GtkSpaceButtonPrivate GtkSpaceButtonPrivate;

struct _GtkSpaceButtonPrivate
{
	GtkWidget *ldesk;
};

#define GTK_SPACEBUTTON_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), GTK_TYPE_SPACEBUTTON, GtkSpaceButtonPrivate))

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
	GtkSpaceButtonPrivate *priv = GTK_SPACEBUTTON_GET_PRIVATE 
					(GTK_SPACEBUTTON (spacebutton));

	gtk_ldesk_update_buttons (priv->ldesk, (gsize)index);
	gtk_ldesk_refresh_box (priv->ldesk);
}

static void
gtk_spacebutton_class_init (GtkSpaceButtonClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_spacebutton_draw;

	g_type_class_add_private (class, sizeof (GtkSpaceButtonPrivate));
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
gtk_spacebutton_new (GtkWidget *ldesk)
{
	GtkWidget *spacebutton = g_object_new (GTK_TYPE_SPACEBUTTON, NULL);
	GtkSpaceButtonPrivate *priv = GTK_SPACEBUTTON_GET_PRIVATE 
					(GTK_SPACEBUTTON (spacebutton));
	priv->ldesk = ldesk;
	return spacebutton;
}
