
#include "config.h"

#include <glib/gi18n.h>

#include "openinbox-application.h"

int main (int argc, char* argv[])
{
	g_autoptr(OpenInboxApplication) app = NULL;
	int ret;

	bindtextdomain(GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
	textdomain(GETTEXT_PACKAGE);

	app = openinbox_application_new(APP_ID, G_APPLICATION_DEFAULT_FLAGS);
	ret = g_application_run(G_APPLICATION(app), argc, argv);

	return ret;
}
