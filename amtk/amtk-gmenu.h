/*
 * This file is part of Amtk - Actions, Menus and Toolbars Kit
 *
 * Copyright 2018 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef AMTK_GMENU_H
#define AMTK_GMENU_H

#if !defined (AMTK_H_INSIDE) && !defined (AMTK_COMPILATION)
#error "Only <amtk/amtk.h> can be included directly."
#endif

#include <gio/gio.h>

G_BEGIN_DECLS

G_MODULE_EXPORT
void	amtk_gmenu_append_item		(GMenu     *menu,
					 GMenuItem *item);

G_MODULE_EXPORT
void	amtk_gmenu_append_section	(GMenu       *menu,
					 const gchar *label,
					 GMenu       *section);

G_END_DECLS

#endif  /* AMTK_GMENU_H */
