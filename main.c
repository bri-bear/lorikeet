#include <stdio.h>

#include "config.h"
#include <xcb/xcb.h>
#include <xcb/xproto.h>

xcb_generic_event_t *mainEvent;
xcb_screen_t *scr;
xcb_window_t root;

xcb_connection_t *dpy; 
int defaultScreen;

static void LorikeetTestWindow() 
{


}

static void LorikeetInit() 
{

    root = scr->root;

    xcb_grab_key(dpy, 1, root, MODKEY, XCB_NO_SYMBOL,
    XCB_GRAB_MODE_ASYNC, XCB_GRAB_MODE_ASYNC);

    dpy = xcb_connect(NULL, NULL);
    if (xcb_connection_has_error(dpy)) {
        printf("Error! Could not open display.");
    }


}

static void LorikeetFocus(xcb_generic_event_t *ev) 
{
    xcb_enter_notify_event_t *e = ( xcb_enter_notify_event_t *) ev;
    xcb_drawable_t client = e->event;

    if ((client) && (client != scr->root)) {
        xcb_set_input_focus(dpy, XCB_INPUT_FOCUS_POINTER_ROOT, client, XCB_CURRENT_TIME);
    }
}

static void LorikeetLoop() 
{
    for(;;) 
    { // Main loop
        mainEvent = xcb_wait_for_event(dpy);
        switch(mainEvent->response_type) 
        {
         case (XCB_BUTTON_PRESS): printf("button-press"); 
         case (XCB_KEY_PRESS): printf("key-press");
         case (XCB_ENTER_NOTIFY): LorikeetFocus(mainEvent); 
        }
    }
}

int main() 
{
    LorikeetInit();
    LorikeetLoop();
}
