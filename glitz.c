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
#include "ldesk.h"

G_DEFINE_TYPE (GtkGlitz, gtk_glitz, GTK_TYPE_DRAWING_AREA);

typedef struct _GtkGlitzPrivate GtkGlitzPrivate;

struct _GtkGlitzPrivate
{
	GdkPixbuf *pixbuf;
	gint height;
	gint width;
	GtkWidget *ldesk;
};

#define GTK_GLITZ_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), GTK_TYPE_GLITZ, GtkGlitzPrivate))

static GdkPixbuf*
load_background (gchar *image_name, gint width, gint height)
{
	GdkPixbufLoader *loader;
	gchar *data;
	gsize length;
	GdkPixbuf *pixbuf = NULL;
	GError *error = NULL;

	if (g_file_get_contents (image_name, &data, &length, NULL))
	{
		loader = gdk_pixbuf_loader_new ();
		gdk_pixbuf_loader_set_size (loader, width, height);
		gdk_pixbuf_loader_write (loader, data, length, &error);
		pixbuf = gdk_pixbuf_loader_get_pixbuf (loader);
	}

	return pixbuf;
}

static gboolean
gtk_glitz_draw (GtkWidget *glitz, cairo_t *cr)
{
	GtkGlitzPrivate *priv = GTK_GLITZ_GET_PRIVATE (glitz);

	gint width = gtk_widget_get_allocated_width (GTK_WIDGET (glitz));
	gint height = gtk_widget_get_allocated_height (GTK_WIDGET (glitz));

	if (width != priv->width || height != priv->height) {
		gdk_pixbuf_scale_simple (priv->pixbuf, width, height,
							GDK_INTERP_HYPER);
		priv->width = width;
		priv->height = height;
	}

	gdk_cairo_set_source_pixbuf (cr, priv->pixbuf, 0, 0);
	cairo_rectangle (cr, 0, 0, priv->width, priv->height); 
	cairo_fill (cr);

	return TRUE;
}

static void
gtk_glitz_class_init (GtkGlitzClass *klass)
{
	GtkWidgetClass *class = GTK_WIDGET_CLASS (klass);

	class->draw = gtk_glitz_draw;

	g_type_class_add_private (class, sizeof (GtkGlitzPrivate));
}

static void
gtk_glitz_init (GtkGlitz *glitz)
{
	gtk_widget_set_has_window (GTK_WIDGET (glitz), FALSE);

	GtkGlitzPrivate *priv = GTK_GLITZ_GET_PRIVATE (glitz);

	priv->width = gtk_widget_get_allocated_width (GTK_WIDGET (glitz));
	priv->height = gtk_widget_get_allocated_height (GTK_WIDGET (glitz));
	priv->pixbuf = load_background("./image.png",
				gtk_ldesk_get_width (GTK_LDESK (priv->ldesk)),
				gtk_ldesk_get_height (GTK_LDESK (priv->ldesk)));
}

GtkWidget*
gtk_glitz_new (GtkWidget *ldesk)
{
	GtkWidget *glitz = g_object_new (GTK_TYPE_GLITZ, NULL);

	GtkGlitzPrivate *priv = GTK_GLITZ_GET_PRIVATE (glitz);
	priv->ldesk = ldesk;

	return glitz;
}
