/*
 * GnomeSword Bible Study Tool
 * about_modules.c - Sword modules about dialog
 *
 * Copyright (C) 2000,2001,2002 GnomeSword Developer Team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gnome.h>
#include <gtkhtml/gtkhtml.h>

#include "gui/about_modules.h"
#include "gui/html.h"
#include "gui/utilities.h"
#include "gui/gnomesword.h"
#include "gui/widgets.h"

#include "main/sword.h"
#include "main/settings.h"

/******************************************************************************
 * static
 */

static GtkWidget *text_html;

/******************************************************************************
 * Name
 *   about_modules_ok
 *
 * Description
 *   Callback if about module button is clicked.
 *
 * Return value
 *   void
 */

static void about_modules_ok(GtkButton * button, gpointer user_data)
{
	GtkWidget *dlg;

	dlg = gtk_widget_get_toplevel(GTK_WIDGET(button));
	gtk_widget_destroy(dlg);
}


/******************************************************************************
 * Name
 *   about_module_display
 *
 * Synopsis
 *   #include "about_modules.h"
 *
 *   void about_module_display(gchar * to, gchar * text)
 *
 * Description
 *   to filter rtf to html
 *
 * Return value
 *   void
 */

static void about_module_display(gchar * to, gchar * text)
{
	gint len, maxlen, i;
	gboolean center = FALSE;

	len = strlen(text);

	maxlen = len * 80;


	// -------------------------------
	for (i = 0; i < strlen(text) - 1; i++) {
		if (text[i] == '\\')	// a RTF command
		{
			if ((text[i + 1] == 'p') &&
			    (text[i + 2] == 'a') &&
			    (text[i + 3] == 'r') &&
			    (text[i + 4] == 'd')) {

				if (center) {
					*to++ = '<';
					*to++ = '/';
					*to++ = 'C';
					*to++ = 'E';
					*to++ = 'N';
					*to++ = 'T';
					*to++ = 'E';
					*to++ = 'R';
					*to++ = '>';
					center = FALSE;
				}
				i += 4;
				continue;
			}
			if ((text[i + 1] == 'p') && (text[i + 2] == 'a')
			    && (text[i + 3] == 'r')) {
				*to++ = '<';
				*to++ = 'b';
				*to++ = 'r';
				*to++ = '>';
				*to++ = '\n';
				i += 3;
				continue;
			}
			if (text[i + 1] == ' ') {
				i += 1;
				continue;
			}
			if (text[i + 1] == '\n') {
				i += 1;
				continue;
			}
			if ((text[i + 1] == 'q')
			    && (text[i + 2] == 'c')) {
				if (!center) {
					*to++ = '<';
					*to++ = 'C';
					*to++ = 'E';
					*to++ = 'N';
					*to++ = 'T';
					*to++ = 'E';
					*to++ = 'R';
					*to++ = '>';
					center = TRUE;
				}
				i += 2;
				continue;
			}
		}
		*to++ = text[i];
	}
	*to++ = 0;
}


/******************************************************************************
 * Name
 *   gui_create_about_modules
 *
 * Synopsis
 *   #include "about_modules.h"
 *
 *   void gui_create_about_modules(void);
 *
 * Description
 *   Create Sword modules about dialog and return pointer on it.
 *
 * Return value
 *   GtkWidget *
 */

static GtkWidget *gui_create_about_modules(void)
{
	GtkWidget *dialog_about_mods;
	GtkWidget *dialog_vbox28;
	GtkWidget *vbox25;
	GtkWidget *hbox21;
	GtkWidget *pixmap;
	GtkWidget *frame73;
	GtkWidget *scrolledwindow30;
	GtkWidget *dialog_action_area28;
	GtkWidget *hbuttonbox7;
	GtkWidget *button_ok;

	dialog_about_mods = gtk_dialog_new();
	gtk_object_set_data(GTK_OBJECT(dialog_about_mods),
			    "dialog_about_mods", dialog_about_mods);
	gtk_window_set_title(GTK_WINDOW(dialog_about_mods),
			     _("About Sword Module"));
	gtk_window_set_default_size(GTK_WINDOW(dialog_about_mods), 324,
				    304);
	gtk_window_set_policy(GTK_WINDOW(dialog_about_mods), TRUE, TRUE,
			      FALSE);

	dialog_vbox28 = GTK_DIALOG(dialog_about_mods)->vbox;
	gtk_object_set_data(GTK_OBJECT(dialog_about_mods),
			    "dialog_vbox28", dialog_vbox28);
	gtk_widget_show(dialog_vbox28);

	vbox25 = gtk_vbox_new(FALSE, 0);
	gtk_widget_show(vbox25);
	gtk_box_pack_start(GTK_BOX(dialog_vbox28), vbox25, TRUE, TRUE,
			   0);

	hbox21 = gtk_hbox_new(FALSE, 0);
	gtk_widget_show(hbox21);
	gtk_box_pack_start(GTK_BOX(vbox25), hbox21, TRUE, TRUE, 0);

	pixmap =
	    gnome_pixmap_new_from_file(PACKAGE_PIXMAPS_DIR
				       "/sword3.xpm");
	gtk_widget_show(pixmap);
	gtk_box_pack_start(GTK_BOX(hbox21), pixmap, TRUE, TRUE, 0);

	frame73 = gtk_frame_new(NULL);
	gtk_widget_show(frame73);
	gtk_box_pack_start(GTK_BOX(vbox25), frame73, TRUE, TRUE, 0);

	scrolledwindow30 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_show(scrolledwindow30);
	gtk_container_add(GTK_CONTAINER(frame73), scrolledwindow30);
	gtk_widget_set_usize(scrolledwindow30, 304, 183);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW
				       (scrolledwindow30),
				       GTK_POLICY_NEVER,
				       GTK_POLICY_ALWAYS);


	text_html = gtk_html_new();
	gtk_widget_show(text_html);
	gtk_container_add(GTK_CONTAINER(scrolledwindow30), text_html);


	dialog_action_area28 =
	    GTK_DIALOG(dialog_about_mods)->action_area;
	gtk_object_set_data(GTK_OBJECT(dialog_about_mods),
			    "dialog_action_area28",
			    dialog_action_area28);
	gtk_widget_show(dialog_action_area28);
	gtk_container_set_border_width(GTK_CONTAINER
				       (dialog_action_area28), 10);

	hbuttonbox7 = gtk_hbutton_box_new();
	gtk_widget_show(hbuttonbox7);
	gtk_box_pack_start(GTK_BOX(dialog_action_area28), hbuttonbox7,
			   TRUE, TRUE, 0);
	gtk_button_box_set_layout(GTK_BUTTON_BOX(hbuttonbox7),
				  GTK_BUTTONBOX_END);

	button_ok = gnome_stock_button(GNOME_STOCK_BUTTON_OK);
	gtk_widget_show(button_ok);
	gtk_container_add(GTK_CONTAINER(hbuttonbox7), button_ok);
	GTK_WIDGET_SET_FLAGS(button_ok, GTK_CAN_DEFAULT);

	gtk_signal_connect(GTK_OBJECT(button_ok), "clicked",
			   GTK_SIGNAL_FUNC(about_modules_ok), NULL);
	return dialog_about_mods;

}

/******************************************************************************
 * public
 *****************************************************************************/

/******************************************************************************
 * Name
 *   gui_display_about_module_dialog
 *
 * Synopsis
 *   #include "about_modules.h"
 *
 *   void gui_display_about_module_dialog(gchar * modname, gboolean isGBS)
 *
 * Description
 *   
 *
 * Return value
 *   void
 */

void gui_display_about_module_dialog(gchar * modname, gboolean isGBS)
{
	GtkWidget *aboutbox = NULL;	//-- pointer to about dialog        
	GtkWidget *text;	//-- pointer to text widget of dialog
	gchar *buf, *to = NULL,	//-- pointer to text buffer for label (mod name)
	*bufabout,		//-- pointer to text buffer for text widget (mod about)
	 discription[500];
	gint len, maxlen;

	bufabout = NULL;

	buf = get_module_description(modname);
	bufabout = get_mod_about_info(modname);

	sprintf(discription,
		"<FONT COLOR=\"#000FCF\"><center><b>%s</b></center></font><HR>",
		buf);
	if (!isGBS) {
		aboutbox = gui_create_about_modules();
		gtk_widget_show(aboutbox);
	}

	if (bufabout) {

		len = strlen(bufabout);
		maxlen = len * 8;

		if ((to = (gchar *) malloc(maxlen)) == NULL) {
			return;
		}

		if (!isGBS) {
			text = text_html;	/* get text widget */
		} else {
			text = widgets.html_book;
		}

		about_module_display(to, bufabout);	/* send about info to display function */
		gui_begin_html(text, FALSE);
		gui_display_html(text, "<html><body>",
				 strlen("<html><body>"));
		gui_display_html(text, discription,
				 strlen(discription));
		if (to)
			gui_display_html(text, to, strlen(to));
		gui_display_html(text, "</body></html>",
				 strlen("</body></html>"));
		gui_end_html(text);
	}

	else
		g_warning("oops");

	if (bufabout)
		g_free(bufabout);
	if (to)
		free(to);
}
