#include <stdio.h>

#include "config.h"
#include <xcb/xcb.h>
#include <xcb/xproto.h>

xcb_generic_event_t *ev;
xcb_screen_t *scr;
xcb_window_t root;

xcb_connection_t *dpy; 
int defaultScreen;

void LorikeetTestWindow() 
{


}

void LorikeetInit() 
{

    root = scr->root;

    xcb_grab_key(dpy, 1, root, MODKEY, XCB_NO_SYMBOL,
    XCB_GRAB_MODE_ASYNC, XCB_GRAB_MODE_ASYNC);

    dpy = xcb_connect(NULL, NULL);
    if (xcb_connection_has_error(dpy)) {
        printf("Error! Could not open display.");
    }


}

void LorikeetLoop() 
{
    for(;;) 
    { // Main loop
        ev = xcb_wait_for_event(dpy);
        case XCB_BUTTON_PRESS: printf("button-press"); 

    }
}

int main() 
{
    LorikeetInit();
    LorikeetLoop();
}
