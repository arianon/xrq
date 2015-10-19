#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xresource.h>

void xrdb_print_value(XrmDatabase db, char* resource) {
	char *type;
	XrmValue xvalue;

	XrmGetResource(db, resource, "String", &type, &xvalue);

	if (xvalue.addr != NULL && (strcmp("String", type) == 0)) {
		printf("%s\n", xvalue.addr);
	} else {
		fprintf(stderr, "Failed to get xrdb value '%s'.\n", resource);
	}
}

int main(int argc, char* argv[]) {
	XrmDatabase xrdb;
	Display *dpy;
	char *xrm;
	int i;

	if (argv[1] == NULL || !strcmp(argv[1], "-h")) {
		printf("Usage: %s <resource names>...\n", argv[0]);
		exit(1);
	} else {
		/* Shift the program name out of the argument vector */
		++argv;
		--argc;
	}


	if ((dpy = XOpenDisplay(NULL)) == NULL) {
		fprintf(stderr, "Couldn't open the display!\n");
		exit(1);
	};

	XrmInitialize();
	xrm = XResourceManagerString(dpy);

	if (xrm != NULL) {
		xrdb = XrmGetStringDatabase(xrm);

		for (i = 0; i < argc; i++)
			xrdb_print_value(xrdb, argv[i]);

		XrmDestroyDatabase(xrdb);
		return 0;
	} else {
		fprintf(stderr, "Couldn't get the RESOURCE_MANAGER property from the root window.\n");
		return 1;
	}
}
