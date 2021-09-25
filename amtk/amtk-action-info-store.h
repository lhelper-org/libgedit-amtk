/* SPDX-FileCopyrightText: 2017, 2018 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef AMTK_ACTION_INFO_STORE_H
#define AMTK_ACTION_INFO_STORE_H

#if !defined (AMTK_H_INSIDE) && !defined (AMTK_COMPILATION)
#error "Only <amtk/amtk.h> can be included directly."
#endif

#include <gtk/gtk.h>
#include <amtk/amtk-action-info.h>

G_BEGIN_DECLS

#define AMTK_TYPE_ACTION_INFO_STORE             (amtk_action_info_store_get_type ())
#define AMTK_ACTION_INFO_STORE(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), AMTK_TYPE_ACTION_INFO_STORE, AmtkActionInfoStore))
#define AMTK_ACTION_INFO_STORE_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), AMTK_TYPE_ACTION_INFO_STORE, AmtkActionInfoStoreClass))
#define AMTK_IS_ACTION_INFO_STORE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), AMTK_TYPE_ACTION_INFO_STORE))
#define AMTK_IS_ACTION_INFO_STORE_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), AMTK_TYPE_ACTION_INFO_STORE))
#define AMTK_ACTION_INFO_STORE_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), AMTK_TYPE_ACTION_INFO_STORE, AmtkActionInfoStoreClass))

typedef struct _AmtkActionInfoStore         AmtkActionInfoStore;
typedef struct _AmtkActionInfoStoreClass    AmtkActionInfoStoreClass;
typedef struct _AmtkActionInfoStorePrivate  AmtkActionInfoStorePrivate;

struct _AmtkActionInfoStore
{
	GObject parent;

	AmtkActionInfoStorePrivate *priv;
};

struct _AmtkActionInfoStoreClass
{
	GObjectClass parent_class;

	gpointer padding[12];
};

G_MODULE_EXPORT
GType			amtk_action_info_store_get_type			(void);

G_MODULE_EXPORT
AmtkActionInfoStore *	amtk_action_info_store_new			(void);

G_MODULE_EXPORT
void			amtk_action_info_store_add			(AmtkActionInfoStore *store,
									 AmtkActionInfo      *info);

G_MODULE_EXPORT
void			amtk_action_info_store_add_entries		(AmtkActionInfoStore       *store,
									 const AmtkActionInfoEntry *entries,
									 gint                       n_entries,
									 const gchar               *translation_domain);

G_MODULE_EXPORT
AmtkActionInfo *	amtk_action_info_store_lookup			(AmtkActionInfoStore *store,
									 const gchar         *action_name);

G_MODULE_EXPORT
void			amtk_action_info_store_set_all_accels_to_app	(AmtkActionInfoStore *store,
									 GtkApplication      *application);

G_MODULE_EXPORT
void			amtk_action_info_store_check_all_used		(AmtkActionInfoStore *store);

G_END_DECLS

#endif /* AMTK_ACTION_INFO_STORE_H */
