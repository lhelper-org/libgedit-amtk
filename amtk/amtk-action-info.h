/* SPDX-FileCopyrightText: 2017, 2020 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef AMTK_ACTION_INFO_H
#define AMTK_ACTION_INFO_H

#if !defined (AMTK_H_INSIDE) && !defined (AMTK_COMPILATION)
#error "Only <amtk/amtk.h> can be included directly."
#endif

#include <glib-object.h>
#include <gmodule.h>

G_BEGIN_DECLS

#define AMTK_TYPE_ACTION_INFO (amtk_action_info_get_type ())

typedef struct _AmtkActionInfo		AmtkActionInfo;
typedef struct _AmtkActionInfoEntry	AmtkActionInfoEntry;

/**
 * AmtkActionInfoEntry:
 * @action_name: the action name. Can be a detailed action name, see
 *   g_action_parse_detailed_name().
 * @icon_name: the icon name, or %NULL.
 * @label: the label (i.e. a short description) with a mnemonic, or %NULL.
 * @accel: the accelerator, in the format understood by gtk_accelerator_parse().
 *   Or %NULL.
 * @tooltip: the tooltip (i.e. a long description), or %NULL.
 *
 * This struct defines a set of information for a single action. It is for use
 * with amtk_action_info_store_add_entries().
 *
 * Like #GActionEntry, it is permissible to use an incomplete initialiser in
 * order to leave some of the later values as %NULL. Additional optional fields
 * may be added in the future.
 *
 * Since: 2.0
 */
struct _AmtkActionInfoEntry
{
	const gchar *action_name;
	const gchar *icon_name;
	const gchar *label;
	const gchar *accel;
	const gchar *tooltip;

	/*< private >*/
	gpointer padding[3];
};

G_MODULE_EXPORT
GType			amtk_action_info_get_type		(void);

G_MODULE_EXPORT
AmtkActionInfo *	amtk_action_info_new			(void);

G_MODULE_EXPORT
AmtkActionInfo *	amtk_action_info_new_from_entry		(const AmtkActionInfoEntry *info_entry,
								 const gchar               *translation_domain);

G_MODULE_EXPORT
AmtkActionInfo *	amtk_action_info_ref			(AmtkActionInfo *info);

G_MODULE_EXPORT
void			amtk_action_info_unref			(AmtkActionInfo *info);

G_MODULE_EXPORT
AmtkActionInfo *	amtk_action_info_copy			(const AmtkActionInfo *info);

G_MODULE_EXPORT
const gchar *		amtk_action_info_get_action_name	(const AmtkActionInfo *info);

G_MODULE_EXPORT
void			amtk_action_info_set_action_name	(AmtkActionInfo *info,
								 const gchar    *action_name);

G_MODULE_EXPORT
const gchar *		amtk_action_info_get_icon_name		(const AmtkActionInfo *info);

G_MODULE_EXPORT
void			amtk_action_info_set_icon_name		(AmtkActionInfo *info,
								 const gchar    *icon_name);

G_MODULE_EXPORT
const gchar *		amtk_action_info_get_label		(const AmtkActionInfo *info);

G_MODULE_EXPORT
void			amtk_action_info_set_label		(AmtkActionInfo *info,
								 const gchar    *label);

G_MODULE_EXPORT
const gchar *		amtk_action_info_get_tooltip		(const AmtkActionInfo *info);

G_MODULE_EXPORT
void			amtk_action_info_set_tooltip		(AmtkActionInfo *info,
								 const gchar    *tooltip);

G_MODULE_EXPORT
const gchar * const *	amtk_action_info_get_accels		(const AmtkActionInfo *info);

G_MODULE_EXPORT
void			amtk_action_info_set_accels		(AmtkActionInfo      *info,
								 const gchar * const *accels);

G_MODULE_EXPORT
void			amtk_action_info_mark_as_used		(AmtkActionInfo *info);

G_MODULE_EXPORT
gboolean		amtk_action_info_has_been_used		(const AmtkActionInfo *info);

G_END_DECLS

#endif  /* AMTK_ACTION_INFO_H */
