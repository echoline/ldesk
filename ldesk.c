#include "ldesk.h"
#include "image.xpm"

typedef struct _GtkLDeskPrivate GtkLDeskPrivate;

struct _GtkLDeskPrivate
{
	GtkWidget **panes;
};

#define GTK_LDESK_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), GTK_TYPE_LDESK, GtkLDeskPrivate))

G_DEFINE_TYPE (GtkLDesk, gtk_ldesk, GTK_TYPE_FIXED);

static gboolean
gtk_ldesk_draw (GtkWidget *ldesk, cairo_t *cr)
{
	gint width = gtk_widget_get_allocated_width (ldesk);
	gint height = gtk_widget_get_allocated_height (ldesk);

	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_rectangle (cr, 0, 0, width, height);
	cairo_fill (cr);

	GTK_WIDGET_CLASS (gtk_ldesk_parent_class)->draw (ldesk, cr);

	return FALSE;
}

static void
gtk_ldesk_class_init (GtkLDeskClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_ldesk_draw;

	g_type_class_add_private (class, sizeof (GtkLDeskPrivate));
}

static void
gtk_ldesk_init (GtkLDesk *ldesk)
{
}

GtkWidget*
gtk_ldesk_new (GtkWidget **panes)
{
	GtkWidget *ret = g_object_new (GTK_TYPE_LDESK, NULL);
	GtkLDeskPrivate *priv = GTK_LDESK_GET_PRIVATE (GTK_LDESK (ret));

	priv->panes = panes;
	
	return ret;
}
