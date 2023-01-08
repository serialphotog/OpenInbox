
#include "config.h"

#include "openinbox-application.h"
#include "gtk/openinbox-window.h"

struct _OpenInboxApplication
{
  GtkApplication parent_instance;
};

G_DEFINE_TYPE (OpenInboxApplication, openinbox_application, GTK_TYPE_APPLICATION)

OpenInboxApplication* openinbox_application_new (const char* application_id, GApplicationFlags flags)
{
  g_return_val_if_fail(application_id != NULL, NULL);

  return g_object_new(OPENINBOX_TYPE_APPLICATION,
                       "application-id", application_id,
                       "flags", flags,
                       NULL);
}

static void openinbox_application_activate (GApplication* app)
{
  GtkWindow* window;

  g_assert(OPENINBOX_IS_APPLICATION(app));

  window = gtk_application_get_active_window(GTK_APPLICATION(app));
  if (window == NULL)
    window = g_object_new(OPENINBOX_TYPE_WINDOW,
                           "application", app,
                           NULL);

  gtk_window_present(window);
}

static void openinbox_application_class_init (OpenInboxApplicationClass* klass)
{
  GApplicationClass* app_class = G_APPLICATION_CLASS(klass);

  app_class->activate = openinbox_application_activate;
}

static void openinbox_application_about_action (GSimpleAction* action, GVariant* parameter, gpointer  user_data)
{
  static const char* authors[] = {"Adam Thompson", NULL};
  OpenInboxApplication* self = user_data;
  GtkWindow* window = NULL;

  g_assert(OPENINBOX_IS_APPLICATION(self));

  window = gtk_application_get_active_window(GTK_APPLICATION(self));

  gtk_show_about_dialog(window,
                         "program-name", APP_NAME,
                         "logo-icon-name", APP_ID,
                         "authors", authors,
                         "version", APP_VERSION,
                         "copyright", APP_COPYRIGHT,
                         NULL);
}

static void openinbox_application_quit_action (GSimpleAction* action, GVariant* parameter, gpointer  user_data)
{
  OpenInboxApplication* self = user_data;
 
  g_assert (OPENINBOX_IS_APPLICATION(self));

  g_application_quit(G_APPLICATION(self));
}

static const GActionEntry app_actions[] = {
  { "quit", openinbox_application_quit_action },
  { "about", openinbox_application_about_action },
};

static void openinbox_application_init (OpenInboxApplication* self)
{
  g_action_map_add_action_entries(G_ACTION_MAP(self),
                                   app_actions,
                                   G_N_ELEMENTS(app_actions),
                                   self);
  gtk_application_set_accels_for_action(GTK_APPLICATION(self),
                                         "app.quit",
                                         (const char *[]) { "<primary>q", NULL });
}

