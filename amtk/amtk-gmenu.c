/*
 * Copyright 2018 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#include "amtk-gmenu.h"

/**
 * SECTION:amtk-gmenu
 * @Short_description: #GMenu convenience functions
 * @Title: AmtkGmenu
 *
 * #GMenu convenience functions.
 */

/**
 * amtk_gmenu_append_item:
 * @menu: a #GMenu.
 * @item: (transfer full): a #GMenuItem to append.
 *
 * Like g_menu_append_item() but with (transfer full) for the @item parameter.
 *
 * Since: 5.0
 */
void
amtk_gmenu_append_item (GMenu     *menu,
			GMenuItem *item)
{
	g_return_if_fail (G_IS_MENU (menu));
	g_return_if_fail (G_IS_MENU_ITEM (item));

	g_menu_append_item (menu, item);
	g_object_unref (item);
}

/**
 * amtk_gmenu_append_section:
 * @menu: a #GMenu.
 * @label: (nullable): the section label, or %NULL.
 * @section: (transfer full): a #GMenu with the items of the section.
 *
 * Like g_menu_append_section() but with (transfer full) and a different type
 * for the @section parameter, and calls g_menu_freeze() on @section.
 *
 * Since: 5.0
 */
void
amtk_gmenu_append_section (GMenu       *menu,
			   const gchar *label,
			   GMenu       *section)
{
	g_return_if_fail (G_IS_MENU (menu));
	g_return_if_fail (G_IS_MENU (section));

	g_menu_freeze (section);
	g_menu_append_section (menu, label, G_MENU_MODEL (section));
	g_object_unref (section);
}
