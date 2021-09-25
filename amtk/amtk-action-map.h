/*
 * Copyright 2017 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef AMTK_ACTION_MAP_H
#define AMTK_ACTION_MAP_H

#if !defined (AMTK_H_INSIDE) && !defined (AMTK_COMPILATION)
#error "Only <amtk/amtk.h> can be included directly."
#endif

#include <gio/gio.h>

G_BEGIN_DECLS

G_MODULE_EXPORT
void	amtk_action_map_add_action_entries_check_dups	(GActionMap         *action_map,
							 const GActionEntry *entries,
							 gint                n_entries,
							 gpointer            user_data);

G_END_DECLS

#endif /* AMTK_ACTION_MAP_H */
