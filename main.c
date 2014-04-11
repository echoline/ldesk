#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include "ldesk.h"
#include "top.h"
#include "bottom.h"
#include "right.h"
#include "stats.h"
#include "comms.h"
#include "rprts.h"
#include "glitz.h"
#include "toggle.h"

GtkWidget *panes[] = { NULL, NULL, NULL, NULL };
GtkWidget *bttns[] = { NULL, NULL, NULL, };
gint width, height;

void
refresh_box()
{
	gboolean used = FALSE;
	gint i;
	for (i = 0; i < 3; i++)
		if (gtk_widget_get_visible (panes[i]))
		{
			gtk_widget_set_size_request (panes[i], width - 300,
							height - 100);
			used = TRUE;
		}
		else
			gtk_widget_set_size_request (panes[i], 0, height - 100);
	if (!used)
		gtk_widget_set_size_request (panes[3], width - 300,
						height - 100);
	else
		gtk_widget_set_size_request (panes[3], 0, height - 100);
}

int
main (int argc, char **argv)
{
	GtkWidget *root;
	GtkWidget *desktop;
	GtkWidget *box;
	GtkWidget *widget;
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

	desktop = gtk_ldesk_new ();
	gtk_container_add (GTK_CONTAINER (root), desktop);

	widget = GTK_WIDGET(gtk_clock_new ());
	gtk_widget_set_size_request (widget, width - 50, 50);
	gtk_fixed_put (GTK_FIXED (desktop), widget, 25, 25);

	box = GTK_WIDGET (gtk_box_new (GTK_ORIENTATION_HORIZONTAL, TRUE));
	panes[0] = gtk_comms_new ();
	gtk_container_add (GTK_CONTAINER (box), panes[0]);
	panes[1] = gtk_stats_new ();
	gtk_container_add (GTK_CONTAINER (box), panes[1]);
	panes[2] = gtk_rprts_new ();
	gtk_container_add (GTK_CONTAINER (box), panes[2]);
	panes[3] = gtk_glitz_new ();
	gtk_container_add (GTK_CONTAINER (box), panes[3]);
	gtk_fixed_put (GTK_FIXED (desktop), box, 25, 100);
	gtk_widget_set_size_request (box, width - 300, height - 100);

	widget = GTK_WIDGET(gtk_bubble_new ());
	gtk_widget_set_size_request (widget, width - 50, 50);
	gtk_fixed_put (GTK_FIXED (desktop), widget, 25, height - 75);

	widget = GTK_WIDGET(gtk_files_new ());
	gtk_widget_set_size_request (widget, 240, height - 150);
	gtk_fixed_put (GTK_FIXED (desktop), widget, width - 265, 75);

	bttns[0] = GTK_WIDGET(gtk_spacebutton_new ());
	gtk_button_set_label (GTK_BUTTON (bttns[0]), "COMMUNICATIONS");
	gtk_widget_set_size_request (bttns[0], 215, 50);
	gtk_fixed_put (GTK_FIXED (desktop), bttns[0], width - 240, height - 355);

	bttns[1] = GTK_WIDGET(gtk_spacebutton_new ());
	gtk_button_set_label (GTK_BUTTON (bttns[1]), "OPERATIONS");
	gtk_widget_set_size_request (bttns[1], 215, 50);
	gtk_fixed_put (GTK_FIXED (desktop), bttns[1], width - 240, height - 295);

	bttns[2] = GTK_WIDGET(gtk_spacebutton_new ());
	gtk_button_set_label (GTK_BUTTON (bttns[2]), "ENGINEERING");
	gtk_widget_set_size_request (bttns[2], 215, 50);
	gtk_fixed_put (GTK_FIXED (desktop), bttns[2], width - 240, height - 235);

	gtk_widget_show_all (root);
	for (i = 0; i < 3; i++)
		gtk_widget_hide (panes[i]);
	refresh_box ();

	gtk_main ();
}

