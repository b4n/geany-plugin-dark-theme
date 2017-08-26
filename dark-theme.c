/*
 * Copyright 2017 Colomban Wendling <colomban@geany.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <geanyplugin.h>

#if !GTK_CHECK_VERSION (3, 0, 0)
# error "This plugin only supports GTK+ 3.0 and newer"
#endif


static gboolean     orig_setting  = FALSE;
static GtkSettings *settings      = NULL;

static gboolean
dt_init (GeanyPlugin *plugin,
         gpointer     data    G_GNUC_UNUSED)
{
  settings = gtk_widget_get_settings (plugin->geany_data->main_widgets->window);

  g_object_get (settings, "gtk-application-prefer-dark-theme", &orig_setting, NULL);
  g_object_set (settings, "gtk-application-prefer-dark-theme", TRUE, NULL);

  return TRUE;
}

static void
dt_cleanup (GeanyPlugin  *plugin  G_GNUC_UNUSED,
            gpointer      data    G_GNUC_UNUSED)
{
  g_object_set (settings, "gtk-application-prefer-dark-theme", orig_setting, NULL);
}

G_MODULE_EXPORT
void
geany_load_module (GeanyPlugin *plugin)
{
  main_locale_init (LOCALEDIR, GETTEXT_PACKAGE);

  plugin->info->name = _("Dark UI Theme");
  plugin->info->description = _("Selects a dark UI theme");
  plugin->info->version = "0";
  plugin->info->author = "Colomban Wendling <colomban@geany.org>";

  plugin->funcs->init = dt_init;
  plugin->funcs->cleanup = dt_cleanup;

  GEANY_PLUGIN_REGISTER (plugin, 225);
}
