#include <stdio.h>

#include "config.h"
#include <xcb/xcb.h>
#include <xcb/xproto.h>

xcb_generic_event_t *ev;
xcb_screen_t *scr;
xcb_window_t root;

xcb_connection_t *dpy; 
int defaultScreen;

void LorikeetTestWindow() {

}

void LorikeetInit() {
    dpy = xcb_connect(NULL, NULL);
    if (xcb_connection_has_error(dpy)) {
        printf("Error! Could not open display.");
    }


}

int main() {
    for(;;) { // Main loop
        ev = xcb_wait_for_event(dpy);
    }
}
