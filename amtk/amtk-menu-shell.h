/*
 * This file is part of Amtk - Actions, Menus and Toolbars Kit
 *
 * Copyright 2017 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef AMTK_MENU_SHELL_H
#define AMTK_MENU_SHELL_H

#if !defined (AMTK_H_INSIDE) && !defined (AMTK_COMPILATION)
#error "Only <amtk/amtk.h> can be included directly."
#endif

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define AMTK_TYPE_MENU_SHELL             (amtk_menu_shell_get_type ())
#define AMTK_MENU_SHELL(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), AMTK_TYPE_MENU_SHELL, AmtkMenuShell))
#define AMTK_MENU_SHELL_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), AMTK_TYPE_MENU_SHELL, AmtkMenuShellClass))
#define AMTK_IS_MENU_SHELL(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), AMTK_TYPE_MENU_SHELL))
#define AMTK_IS_MENU_SHELL_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), AMTK_TYPE_MENU_SHELL))
#define AMTK_MENU_SHELL_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), AMTK_TYPE_MENU_SHELL, AmtkMenuShellClass))

typedef struct _AmtkMenuShell         AmtkMenuShell;
typedef struct _AmtkMenuShellClass    AmtkMenuShellClass;
typedef struct _AmtkMenuShellPrivate  AmtkMenuShellPrivate;

struct _AmtkMenuShell
{
	GObject parent;

	AmtkMenuShellPrivate *priv;
};

struct _AmtkMenuShellClass
{
	GObjectClass parent_class;

	/* Signals */

	void (* menu_item_selected)	(AmtkMenuShell *amtk_menu_shell,
					 GtkMenuItem   *menu_item);

	void (* menu_item_deselected)	(AmtkMenuShell *amtk_menu_shell,
					 GtkMenuItem   *menu_item);

	gpointer padding[12];
};

G_MODULE_EXPORT
GType		amtk_menu_shell_get_type		(void);

G_MODULE_EXPORT
AmtkMenuShell *	amtk_menu_shell_get_from_gtk_menu_shell	(GtkMenuShell *gtk_menu_shell);

G_MODULE_EXPORT
GtkMenuShell *	amtk_menu_shell_get_menu_shell		(AmtkMenuShell *amtk_menu_shell);

G_END_DECLS

#endif /* AMTK_MENU_SHELL_H */

/* ex:set ts=8 noet: */
