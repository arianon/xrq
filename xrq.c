#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <X11/Xresource.h>

void xrdb_print_value(XrmDatabase db, char* resource) {
	char *type;
	XrmValue xvalue;

	XrmGetResource(db, resource, "*", &type, &xvalue);

	if (xvalue.addr != NULL)
		puts(xvalue.addr);
	else
		errx(1, "failed to get xrdb value '%s'.", resource);
}

int main(int argc, char* argv[]) {
	XrmDatabase xrdb;
	Display *dpy;
	char *xrm;
	int i;

	if (argv[1] == NULL || !strcmp(argv[1], "-h"))
		errx(1, "usage: %s <resource names>...", argv[0]);
	else
		++argv;	--argc; /* Shift the program name out of the argument vector */


	if (!(dpy = XOpenDisplay(NULL)))
		errx(1, "could not open the display!");

	XrmInitialize();
	xrm = XResourceManagerString(dpy);

	if (xrm != NULL) {
		xrdb = XrmGetStringDatabase(xrm);

		for (i = 0; i < argc; i++)
			xrdb_print_value(xrdb, argv[i]);

		XrmDestroyDatabase(xrdb);
		return 0;
	} else {
		warnx("could not get the resource properties.");
		return 1;
	}
}
