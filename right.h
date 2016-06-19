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
#ifndef __FILES_H
#define __FILES_H

#include <gtk/gtk.h>
#include <math.h>

typedef struct _GtkFiles		GtkFiles;
typedef struct _GtkFilesClass		GtkFilesClass;

struct _GtkFiles
{
	GtkBox parent;

	/* private */
};

struct _GtkFilesClass
{
	GtkBoxClass parent_class;
};

#define GTK_TYPE_FILES		(gtk_files_get_type ())
#define GTK_FILES(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_FILES, GtkFiles))
#define GTK_FILES_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GTK_FILES,  GtkFilesClass))
#define GTK_IS_FILES(obj)	(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_FILES))
#define GTK_IS_FILES_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_FILES))
#define GTK_FILES_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_FILES, GtkFilesClass))

GtkWidget* gtk_files_new (void);

#endif // __FILES_H
