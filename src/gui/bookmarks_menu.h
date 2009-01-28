/*
 * Xiphos Bible Study Tool
 * bookmarks_menu.h - gui for bookmarks 
 *
 * Copyright (C) 2003-2008 Xiphos Developer Team
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
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef ___BOOKMARKS_MENU_H_
#define ___BOOKMARKS_MENU_H_

#ifdef __cplusplus
extern "C" {
#endif
struct _bookmark_menu {
	GtkWidget *menu;
	GtkWidget *in_tab;
	GtkWidget *in_dialog;
	GtkWidget *new;
	GtkWidget *insert;
	GtkWidget *add;
	GtkWidget *edit;
	GtkWidget *point;
	GtkWidget *delete;
	GtkWidget *reorder;
	GtkWidget *save;
	GtkWidget *bibletime;
	GtkWidget *rr_submenu;
	GtkWidget *remove;
	GtkWidget *restore;
};
typedef struct _bookmark_menu BOOKMARK_MENU;
extern BOOKMARK_MENU menu;
extern GtkTreeSelection *current_selection;
extern GtkTreeStore *model;
extern gboolean use_dialog;
extern gboolean bookmarks_changed;

void gui_save_bookmarks(GtkMenuItem * menuitem, gpointer user_data);
void gui_create_bookmark_menu(void);
void gui_save_bookmarks_treeview(void);

#ifdef __cplusplus
}
#endif

#endif
