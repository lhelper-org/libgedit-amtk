/*
 * This file is part of Amtk - Actions, Menus and Toolbars Kit
 *
 * Copyright 2017 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef AMTK_MENU_ITEM_H
#define AMTK_MENU_ITEM_H

#if !defined (AMTK_H_INSIDE) && !defined (AMTK_COMPILATION)
#error "Only <amtk/amtk.h> can be included directly."
#endif

#include <gtk/gtk.h>

G_BEGIN_DECLS

G_MODULE_EXPORT
const gchar *	amtk_menu_item_get_long_description	(GtkMenuItem *menu_item);

G_MODULE_EXPORT
void		amtk_menu_item_set_long_description	(GtkMenuItem *menu_item,
							 const gchar *long_description);

G_MODULE_EXPORT
void		amtk_menu_item_set_icon_name		(GtkMenuItem *item,
							 const gchar *icon_name);

G_END_DECLS

#endif  /* AMTK_MENU_ITEM_H */
