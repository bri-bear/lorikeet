#include "config.h"
#include <xcb/xcb.h>

xcb_generic_event_t *ev;

dpy = xcb_connect(NULL, NULL);
if (xcb_connection_has_error(dpy)) {
    printf("Error! Could not open display.");
    return 1;
}

int main() {
    for(;;) { // Main loop
        ev = xcb_wait_for_event(dpy);
    }
}
