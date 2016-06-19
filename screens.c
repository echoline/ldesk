#include "screens.h"

typedef struct _GtkScreensPrivate GtkScreensPrivate;

struct _GtkScreensPrivate
{
	char unused;
};

#define GTK_SCREENS_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), GTK_TYPE_SCREENS, GtkScreensPrivate))

G_DEFINE_TYPE (GtkScreens, gtk_screens, GTK_TYPE_FIXED);

static gboolean
gtk_screens_draw (GtkWidget *screens, cairo_t *cr)
{
	gint width = gtk_widget_get_allocated_width (screens);
	gint height = gtk_widget_get_allocated_height (screens);

	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_rectangle (cr, 0, 0, width, height);
	cairo_fill (cr);

	GTK_WIDGET_CLASS (gtk_screens_parent_class)->draw (screens, cr);

	return FALSE;
}

static void
gtk_screens_class_init (GtkScreensClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_screens_draw;

	g_type_class_add_private (class, sizeof (GtkScreensPrivate));
}

static void
gtk_screens_init (GtkScreens *screens)
{
}

GtkWidget*
gtk_screens_new ()
{
	GtkWidget *desktop = g_object_new (GTK_TYPE_SCREENS, NULL);
	GtkScreensPrivate *priv = GTK_SCREENS_GET_PRIVATE (GTK_SCREENS (desktop));
	return desktop;
}
