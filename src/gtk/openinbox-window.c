
#include "config.h"

#include "openinbox-window.h"

struct _OpenInboxWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkHeaderBar*     header_bar; // Global application header bar
  GtkPaned*         main_pane; // The main pane
};

G_DEFINE_FINAL_TYPE(OpenInboxWindow, openinbox_window, GTK_TYPE_APPLICATION_WINDOW)

static void openinbox_window_class_init (OpenInboxWindowClass* klass)
{
  GtkWidgetClass* widget_class = GTK_WIDGET_CLASS(klass);

  gtk_widget_class_set_template_from_resource(widget_class, MAIN_WINDOW_UI);
  gtk_widget_class_bind_template_child(widget_class, OpenInboxWindow, header_bar);
  gtk_widget_class_bind_template_child(widget_class, OpenInboxWindow, main_pane);
}

static void openinbox_window_init (OpenInboxWindow* self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
