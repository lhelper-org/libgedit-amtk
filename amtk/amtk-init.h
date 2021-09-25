/*
 * Copyright 2017 - Sébastien Wilmet <swilmet@gnome.org>
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef AMTK_INIT_H
#define AMTK_INIT_H

#if !defined (AMTK_H_INSIDE) && !defined (AMTK_COMPILATION)
#error "Only <amtk/amtk.h> can be included directly."
#endif

#include <gmodule.h>

G_BEGIN_DECLS

G_MODULE_EXPORT
void	amtk_init		(void);

G_MODULE_EXPORT
void	amtk_finalize		(void);

G_END_DECLS

#endif /* AMTK_INIT_H */
