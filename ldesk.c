#include "ldesk.h"
#include "bottom.h"
#include "comms.h"
#include "glitz.h"
#include "right.h"
#include "rprts.h"
#include "stats.h"
#include "toggle.h"
#include "top.h"

typedef struct _GtkLDeskPrivate GtkLDeskPrivate;

struct _GtkLDeskPrivate
{
	GtkWidget **panes;
	GtkWidget **bttns;
	gint width;
	gint height;
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

void
gtk_ldesk_refresh_box(GtkWidget *ldesk)
{
	GtkLDeskPrivate *priv = GTK_LDESK_GET_PRIVATE (GTK_LDESK (ldesk));
	gboolean used = FALSE;
	gint i;

	for (i = 0; i < 3; i++)
		if (gtk_widget_get_visible (priv->panes[i]))
		{
			gtk_widget_set_size_request (priv->panes[i],
							priv->width - 300,
							priv->height - 100);
			used = TRUE;
		}
		else
			gtk_widget_set_size_request (priv->panes[i], 0,
							priv->height - 100);
	if (!used)
		gtk_widget_set_size_request (priv->panes[3], priv->width - 300,
						priv->height - 100);
	else
		gtk_widget_set_size_request (priv->panes[3], 0,
						priv->height - 100);
}

void
gtk_ldesk_update_buttons(GtkWidget *ldesk, gsize index)
{
	GtkLDeskPrivate *priv = GTK_LDESK_GET_PRIVATE (GTK_LDESK (ldesk));
	gint i;

	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (
					priv->bttns[index])))
		for (i = 0; i < 3; i++)
		{
			if (i == index)
			{
				gtk_widget_show (priv->panes[i]);
				gtk_widget_hide (priv->panes[3]);
			}
			else
			{
				gtk_toggle_button_set_active (
					GTK_TOGGLE_BUTTON (priv->bttns[i]),
									FALSE);
				gtk_widget_hide (priv->panes[i]);
			}
		}
	else {
		gtk_widget_hide (priv->panes[index]);
		gtk_widget_show (priv->panes[3]);
	}
}

GtkWidget*
gtk_ldesk_new (gint width, gint height)
{
	gint i;
	GtkWidget *box;
	GtkWidget *widget;
	GtkWidget *desktop = g_object_new (GTK_TYPE_LDESK, NULL);
	GtkLDeskPrivate *priv = GTK_LDESK_GET_PRIVATE (GTK_LDESK (desktop));
	priv->panes = g_malloc0(sizeof(GtkWidget*) * 4);
	priv->bttns = g_malloc0(sizeof(GtkWidget*) * 4);
	priv->width = width;
	priv->height = height;

	widget = GTK_WIDGET(gtk_clock_new ());
	gtk_widget_set_size_request (widget, width - 50, 50);
	gtk_fixed_put (GTK_FIXED (desktop), widget, 25, 25);

	box = GTK_WIDGET (gtk_box_new (GTK_ORIENTATION_HORIZONTAL, TRUE));
	priv->panes[0] = gtk_comms_new ();
	gtk_container_add (GTK_CONTAINER (box), priv->panes[0]);
	priv->panes[1] = gtk_stats_new ();
	gtk_container_add (GTK_CONTAINER (box), priv->panes[1]);
	priv->panes[2] = gtk_rprts_new ();
	gtk_container_add (GTK_CONTAINER (box), priv->panes[2]);
	priv->panes[3] = gtk_glitz_new ();
	gtk_container_add (GTK_CONTAINER (box), priv->panes[3]);
	gtk_fixed_put (GTK_FIXED (desktop), box, 25, 100);
	gtk_widget_set_size_request (box, width - 300, height - 100);

	widget = GTK_WIDGET(gtk_bubble_new ());
	gtk_widget_set_size_request (widget, width - 50, 50);
	gtk_fixed_put (GTK_FIXED (desktop), widget, 25, height - 75);

	widget = GTK_WIDGET(gtk_files_new ());
	gtk_widget_set_size_request (widget, 240, height - 150);
	gtk_fixed_put (GTK_FIXED (desktop), widget, width - 265, 75);

	priv->bttns[0] = GTK_WIDGET(gtk_spacebutton_new (desktop));
	gtk_button_set_label (GTK_BUTTON (priv->bttns[0]), "COMMUNICATIONS");
	gtk_widget_set_size_request (priv->bttns[0], 215, 50);
	gtk_fixed_put (GTK_FIXED (desktop), priv->bttns[0], width - 240, height - 355);

	priv->bttns[1] = GTK_WIDGET(gtk_spacebutton_new (desktop));
	gtk_button_set_label (GTK_BUTTON (priv->bttns[1]), "OPERATIONS");
	gtk_widget_set_size_request (priv->bttns[1], 215, 50);
	gtk_fixed_put (GTK_FIXED (desktop), priv->bttns[1], width - 240, height - 295);

	priv->bttns[2] = GTK_WIDGET(gtk_spacebutton_new (desktop));
	gtk_button_set_label (GTK_BUTTON (priv->bttns[2]), "ENGINEERING");
	gtk_widget_set_size_request (priv->bttns[2], 215, 50);
	gtk_fixed_put (GTK_FIXED (desktop), priv->bttns[2], width - 240, height - 235);

	for (i = 0; i < 3; i++)
		gtk_widget_hide (priv->panes[i]);
	gtk_ldesk_refresh_box(desktop);
	
	return desktop;
}
