/*
 * Copyright 2017 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#include <amtk/amtk.h>

static void
test_add_entries (void)
{
	AmtkActionInfoStore *store;
	AmtkActionInfoCentralStore *central_store;
	AmtkActionInfo *info1;
	AmtkActionInfo *info2;

	const AmtkActionInfoEntry entries[] =
	{
		/* action, icon, label, accel, tooltip */

		{ "app.quit", "application-exit", "_Quit", "<Control>q",
		  "Quit the application" },

		/* Tooltip field missing, must be NULL. */
		{ "win.open", "document-open", "_Open", "<Control>o" },
	};

	store = amtk_action_info_store_new ();

	amtk_action_info_store_add_entries (store,
					    entries,
					    G_N_ELEMENTS (entries),
					    NULL);

	info1 = amtk_action_info_store_lookup (store, "win.open");
	g_assert_true (info1 != NULL);
	g_assert_cmpstr (amtk_action_info_get_icon_name (info1), ==, "document-open");
	g_assert_true (amtk_action_info_get_tooltip (info1) == NULL);

	central_store = amtk_action_info_central_store_get_singleton ();
	info2 = amtk_action_info_central_store_lookup (central_store, "win.open");
	g_assert_true (info1 == info2);

	info1 = amtk_action_info_store_lookup (store, "plouf");
	g_assert_true (info1 == NULL);

	g_object_unref (store);
}

int
main (int    argc,
      char **argv)
{
	g_test_init (&argc, &argv, NULL);

	g_test_add_func ("/action-info-store/add-entries", test_add_entries);

	return g_test_run ();
}
