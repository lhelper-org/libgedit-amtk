/*
 * Copyright 2018 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#include "amtk-shortcuts.h"

/**
 * SECTION:amtk-shortcuts
 * @Short_description: GtkShortcuts convenience functions
 * @Title: AmtkShortcuts
 *
 * Convenience functions to create a #GtkShortcutsWindow. At the time of writing
 * the GtkShortcuts* classes don't provide any function.
 *
 * You need to also use gtk_container_add(), and g_object_set() to set other
 * properties.
 */

/**
 * amtk_shortcuts_window_new:
 * @parent: the #GtkWindow:transient-for.
 *
 * Creates a new #GtkShortcutsWindow. The #GtkWindow:modal property is set to
 * %TRUE.
 *
 * It is on purpose that the return type is #GtkShortcutsWindow, not #GtkWidget
 * or something else, so in C when you declare the variable as
 * #GtkShortcutsWindow it's easier to find it later (searching "GtkShortcuts"
 * will return something in your codebase).
 *
 * Returns: (transfer floating): a new #GtkShortcutsWindow.
 * Since: 5.0
 */
GtkShortcutsWindow *
amtk_shortcuts_window_new (GtkWindow *parent)
{
	GtkShortcutsWindow *shortcuts_window;

	g_return_val_if_fail (GTK_IS_WINDOW (parent), NULL);

	shortcuts_window = g_object_new (GTK_TYPE_SHORTCUTS_WINDOW, NULL);
	gtk_window_set_modal (GTK_WINDOW (shortcuts_window), TRUE);
	gtk_window_set_transient_for (GTK_WINDOW (shortcuts_window), parent);

	return shortcuts_window;
}

/**
 * amtk_shortcuts_section_new:
 * @title: the #GtkShortcutsSection:title.
 *
 * Returns: (transfer floating): a new #GtkShortcutsSection.
 * Since: 5.0
 */
GtkContainer *
amtk_shortcuts_section_new (const gchar *title)
{
	GtkContainer *section;

	section = g_object_new (GTK_TYPE_SHORTCUTS_SECTION,
				"title", title,
				NULL);

	gtk_widget_show (GTK_WIDGET (section));

	return section;
}

/**
 * amtk_shortcuts_group_new:
 * @title: the #GtkShortcutsGroup:title.
 *
 * Returns: (transfer floating): a new #GtkShortcutsGroup.
 * Since: 5.0
 */
GtkContainer *
amtk_shortcuts_group_new (const gchar *title)
{
	GtkContainer *group;

	group = g_object_new (GTK_TYPE_SHORTCUTS_GROUP,
			      "title", title,
			      NULL);

	gtk_widget_show (GTK_WIDGET (group));

	return group;
}
