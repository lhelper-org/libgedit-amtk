/*
 * Copyright 2018 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef AMTK_SHORTCUTS_H
#define AMTK_SHORTCUTS_H

#if !defined (AMTK_H_INSIDE) && !defined (AMTK_COMPILATION)
#error "Only <amtk/amtk.h> can be included directly."
#endif

#include <gtk/gtk.h>

G_BEGIN_DECLS

G_MODULE_EXPORT
GtkShortcutsWindow *	amtk_shortcuts_window_new	(GtkWindow *parent);

G_MODULE_EXPORT
GtkContainer *		amtk_shortcuts_section_new	(const gchar *title);

G_MODULE_EXPORT
GtkContainer *		amtk_shortcuts_group_new	(const gchar *title);

G_END_DECLS

#endif /* AMTK_SHORTCUTS_H */
