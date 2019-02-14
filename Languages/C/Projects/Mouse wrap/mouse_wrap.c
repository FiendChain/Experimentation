#define _BSD_SOURCE
#define __USE_XOPEN

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <xdo.h>
#include <GL/glew.h>


const int WIDTH = 1920;
const int HEIGHT = 1080;
const int PAD = 5;


int main(int argc, char *argv[])
{
    int x = WIDTH/2.0f, y = HEIGHT/2.0f;
    xdo_t *handler = xdo_new(NULL);
    int screen;
    while(true)
    {   
        // get mouse position
        xdo_get_mouse_location(handler, &x, &y, &screen);
        // left wrap
        if(x <= 0)
        {
            xdo_send_keysequence_window_down(handler, screen, "ctrl", 0);
            xdo_move_mouse(handler, WIDTH-PAD, y, screen);
            xdo_send_keysequence_window_up(handler, screen, "ctrl", 0);
        }
        else if(x >= WIDTH-1)
        {
            xdo_send_keysequence_window_down(handler, screen, "ctrl", 0);
            xdo_move_mouse(handler, PAD, y, screen);
            xdo_send_keysequence_window_up(handler, screen, "ctrl", 0);
        }
        usleep(10000);
    }
    xdo_free(handler);

    return 0;
}