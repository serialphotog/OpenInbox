
#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define OPENINBOX_TYPE_APPLICATION (openinbox_application_get_type())

G_DECLARE_FINAL_TYPE (OpenInboxApplication, openinbox_application, OPENINBOX, APPLICATION, GtkApplication)

OpenInboxApplication* openinbox_application_new(const char* application_id, GApplicationFlags flags);

G_END_DECLS
