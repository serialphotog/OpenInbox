
#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define OPENINBOX_TYPE_WINDOW (openinbox_window_get_type())

G_DECLARE_FINAL_TYPE (OpenInboxWindow, openinbox_window, OPENINBOX, WINDOW, GtkApplicationWindow)

G_END_DECLS
