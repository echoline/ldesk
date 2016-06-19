#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include "ldesk.h"
#include "screens.h"

int
main (int argc, char **argv)
{
	GtkWidget *root;
	GtkWidget *fixed;
	GtkWidget *desktop;
	gint i;
	gint width, height;

	gtk_init (&argc, &argv);

	width = gdk_screen_width ();
	height = gdk_screen_height ();

	root = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	g_signal_connect (root, "destroy",
			G_CALLBACK (gtk_main_quit), NULL);

	gtk_window_set_type_hint (GTK_WINDOW (root),
				GDK_WINDOW_TYPE_HINT_DESKTOP);
	gtk_window_set_resizable (GTK_WINDOW (root), FALSE);

	gtk_widget_set_size_request (root, width, height);

	fixed = gtk_screens_new ();
	gtk_container_add (GTK_CONTAINER (root), fixed);

	GdkScreen *screen = gdk_screen_get_default ();

	for (i = 0; i < gdk_screen_get_n_monitors (screen); i++) {
		GdkRectangle rect;

		gdk_screen_get_monitor_geometry (screen, i, &rect);

		desktop = gtk_ldesk_new (rect.width, rect.height);
		
		gtk_fixed_put (GTK_FIXED (fixed), desktop, rect.x, rect.y);
	}

	gtk_widget_show_all (root);

	gtk_main ();
}

