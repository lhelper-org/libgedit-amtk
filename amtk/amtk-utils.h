/* SPDX-FileCopyrightText: 2017 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef AMTK_UTILS_H
#define AMTK_UTILS_H

#if !defined (AMTK_H_INSIDE) && !defined (AMTK_COMPILATION)
#error "Only <amtk/amtk.h> can be included directly."
#endif

#include <gtk/gtk.h>

G_BEGIN_DECLS

/* File utilities */

G_GNUC_INTERNAL
gchar *		_amtk_utils_replace_home_dir_with_tilde		(const gchar *filename);

/* String utilities */

G_MODULE_EXPORT
gchar *		amtk_utils_remove_mnemonic			(const gchar *str);

/* GTK utilities */

G_MODULE_EXPORT
gchar *		amtk_utils_recent_chooser_menu_get_item_uri	(GtkRecentChooserMenu *menu,
								 GtkMenuItem          *item);

G_GNUC_BEGIN_IGNORE_DEPRECATIONS
G_MODULE_EXPORT
void		amtk_utils_bind_g_action_to_gtk_action		(GActionMap     *g_action_map,
								 const gchar    *detailed_g_action_name_without_prefix,
								 GtkActionGroup *gtk_action_group,
								 const gchar    *gtk_action_name);

G_MODULE_EXPORT
void		amtk_utils_create_gtk_action			(GActionMap     *g_action_map,
								 const gchar    *detailed_g_action_name_with_prefix,
								 GtkActionGroup *gtk_action_group,
								 const gchar    *gtk_action_name);
G_GNUC_END_IGNORE_DEPRECATIONS

G_MODULE_EXPORT
GtkWidget *	amtk_utils_get_shrinkable_menubar		(GtkMenuBar *menubar);

G_END_DECLS

#endif /* AMTK_UTILS_H */
