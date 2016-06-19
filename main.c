#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include "ldesk.h"

gint width, height;

int
main (int argc, char **argv)
{
	GtkWidget *root;
	GtkWidget *desktop;
	gint i;

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

	desktop = gtk_ldesk_new (width, height);
	gtk_container_add (GTK_CONTAINER (root), desktop);

	gtk_widget_show_all (root);

	gtk_main ();
}

