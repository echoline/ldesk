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
