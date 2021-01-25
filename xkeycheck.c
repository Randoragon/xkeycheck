#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Display *dpy;
char keys_return[32] = {0};

void die(char *msg)
{
    fprintf(stderr, "xkeycheck: %s\n", msg);
    exit(1);
}

int getKeySym(char *str)
{
    if        (strcmp(str, "a") == 0) {
        return XK_a;
    } else if (strcmp(str, "b") == 0) {
        return XK_b;
    } else if (strcmp(str, "c") == 0) {
        return XK_c;
    } else if (strcmp(str, "d") == 0) {
        return XK_d;
    } else if (strcmp(str, "e") == 0) {
        return XK_e;
    } else if (strcmp(str, "f") == 0) {
        return XK_f;
    } else if (strcmp(str, "g") == 0) {
        return XK_g;
    } else if (strcmp(str, "h") == 0) {
        return XK_h;
    } else if (strcmp(str, "i") == 0) {
        return XK_i;
    } else if (strcmp(str, "j") == 0) {
        return XK_j;
    } else if (strcmp(str, "k") == 0) {
        return XK_k;
    } else if (strcmp(str, "l") == 0) {
        return XK_l;
    } else if (strcmp(str, "m") == 0) {
        return XK_m;
    } else if (strcmp(str, "n") == 0) {
        return XK_n;
    } else if (strcmp(str, "o") == 0) {
        return XK_o;
    } else if (strcmp(str, "p") == 0) {
        return XK_p;
    } else if (strcmp(str, "q") == 0) {
        return XK_q;
    } else if (strcmp(str, "r") == 0) {
        return XK_r;
    } else if (strcmp(str, "s") == 0) {
        return XK_s;
    } else if (strcmp(str, "t") == 0) {
        return XK_t;
    } else if (strcmp(str, "u") == 0) {
        return XK_u;
    } else if (strcmp(str, "v") == 0) {
        return XK_v;
    } else if (strcmp(str, "w") == 0) {
        return XK_w;
    } else if (strcmp(str, "x") == 0) {
        return XK_x;
    } else if (strcmp(str, "y") == 0) {
        return XK_y;
    } else if (strcmp(str, "z") == 0) {
        return XK_z;
    } else if (strcmp(str, "0") == 0) {
        return XK_0;
    } else if (strcmp(str, "1") == 0) {
        return XK_1;
    } else if (strcmp(str, "2") == 0) {
        return XK_2;
    } else if (strcmp(str, "3") == 0) {
        return XK_3;
    } else if (strcmp(str, "4") == 0) {
        return XK_4;
    } else if (strcmp(str, "5") == 0) {
        return XK_5;
    } else if (strcmp(str, "6") == 0) {
        return XK_6;
    } else if (strcmp(str, "7") == 0) {
        return XK_7;
    } else if (strcmp(str, "8") == 0) {
        return XK_8;
    } else if (strcmp(str, "9") == 0) {
        return XK_9;
    } else if (strcmp(str, "`") == 0) {
        return XK_grave;
    } else if (strcmp(str, "-") == 0) {
        return XK_minus;
    } else if (strcmp(str, "+") == 0) {
        return XK_plus;
    } else if (strcmp(str, "backspace") == 0) {
        return XK_BackSpace;
    } else if (strcmp(str, "tab") == 0) {
        return XK_Tab;
    } else if (strcmp(str, "capslock") == 0) {
        return XK_Caps_Lock;
    } else if (strcmp(str, "lshift") == 0) {
        return XK_Shift_L;
    } else if (strcmp(str, "rshift") == 0) {
        return XK_Shift_R;
    } else if (strcmp(str, "lctrl") == 0) {
        return XK_Control_L;
    } else if (strcmp(str, "rctrl") == 0) {
        return XK_Control_R;
    } else if (strcmp(str, "lsuper") == 0 || strcmp(str, "lwin") == 0) {
        return XK_Super_L;
    } else if (strcmp(str, "rsuper") == 0 || strcmp(str, "rwin") == 0) {
        return XK_Super_R;
    } else if (strcmp(str, "lalt") == 0) {
        return XK_Alt_L;
    } else if (strcmp(str, "ralt") == 0) {
        return XK_Alt_R;
    } else if (strcmp(str, "space") == 0 || strcmp(str, " ") == 0) {
        return XK_space;
    } else if (strcmp(str, "menu") == 0) {
        return XK_Menu;
    } else if (strcmp(str, "[") == 0) {
        return XK_bracketleft;
    } else if (strcmp(str, "]") == 0) {
        return XK_bracketright;
    } else if (strcmp(str, ";") == 0) {
        return XK_semicolon;
    } else if (strcmp(str, "'") == 0) {
        return XK_quotedbl;
    } else if (strcmp(str, "\\") == 0) {
        return XK_backslash;
    } else if (strcmp(str, "return") == 0 || strcmp(str, "enter") == 0) {
        return XK_Return;
    } else if (strcmp(str, ",") == 0) {
        return XK_comma;
    } else if (strcmp(str, ".") == 0) {
        return XK_period;
    } else if (strcmp(str, "/") == 0) {
        return XK_slash;
    } else if (strcmp(str, "escape") == 0) {
        return XK_Escape;
    } else if (strcmp(str, "F1") == 0) {
        return XK_F1;
    } else if (strcmp(str, "F2") == 0) {
        return XK_F2;
    } else if (strcmp(str, "F3") == 0) {
        return XK_F3;
    } else if (strcmp(str, "F4") == 0) {
        return XK_F4;
    } else if (strcmp(str, "F5") == 0) {
        return XK_F5;
    } else if (strcmp(str, "F6") == 0) {
        return XK_F6;
    } else if (strcmp(str, "F7") == 0) {
        return XK_F7;
    } else if (strcmp(str, "F8") == 0) {
        return XK_F8;
    } else if (strcmp(str, "F9") == 0) {
        return XK_F9;
    } else if (strcmp(str, "F10") == 0) {
        return XK_F10;
    } else if (strcmp(str, "F11") == 0) {
        return XK_F11;
    } else if (strcmp(str, "F12") == 0) {
        return XK_F12;
    } else if (strcmp(str, "num0") == 0) {
        return XK_KP_0;
    } else if (strcmp(str, "num1") == 0) {
        return XK_KP_1;
    } else if (strcmp(str, "num2") == 0) {
        return XK_KP_2;
    } else if (strcmp(str, "num3") == 0) {
        return XK_KP_3;
    } else if (strcmp(str, "num4") == 0) {
        return XK_KP_4;
    } else if (strcmp(str, "num5") == 0) {
        return XK_KP_5;
    } else if (strcmp(str, "num6") == 0) {
        return XK_KP_6;
    } else if (strcmp(str, "num7") == 0) {
        return XK_KP_7;
    } else if (strcmp(str, "num8") == 0) {
        return XK_KP_8;
    } else if (strcmp(str, "num9") == 0) {
        return XK_KP_9;
    } else if (strcmp(str, "num-") == 0) {
        return XK_KP_Subtract;
    } else if (strcmp(str, "num+") == 0) {
        return XK_KP_Add;
    } else if (strcmp(str, "num*") == 0) {
        return XK_KP_Multiply;
    } else if (strcmp(str, "num/") == 0) {
        return XK_KP_Divide;
    } else if (strcmp(str, "numlock") == 0) {
        return XK_Num_Lock;
    } else if (strcmp(str, "num.") == 0) {
        return XK_KP_Decimal;
    } else if (strcmp(str, "printscreen") == 0) {
        return XK_Print;
    } else if (strcmp(str, "scrolllock") == 0) {
        return XK_Scroll_Lock;
    } else if (strcmp(str, "pause") == 0) {
        return XK_Pause;
    } else if (strcmp(str, "insert") == 0) {
        return XK_Insert;
    } else if (strcmp(str, "home") == 0) {
        return XK_Home;
    } else if (strcmp(str, "pageup") == 0) {
        return XK_Page_Up;
    } else if (strcmp(str, "pagedown") == 0) {
        return XK_Page_Down;
    } else if (strcmp(str, "delete") == 0) {
        return XK_Delete;
    } else if (strcmp(str, "end") == 0) {
        return XK_End;
    } else if (strcmp(str, "up") == 0) {
        return XK_Up;
    } else if (strcmp(str, "left") == 0) {
        return XK_Left;
    } else if (strcmp(str, "down") == 0) {
        return XK_Down;
    } else if (strcmp(str, "right") == 0) {
        return XK_Right;
    } else {
        XCloseDisplay(dpy);
        die("unknown keysym");
    }
    return 0;
}

void help()
{
    printf("xkeycheck \n\
\n\
LIST OF AVAILABLE KEYS \n\
        escape \n\
        F1-F12 \n\
        printscreen \n\
        scrolllock \n\
        pause \n\
        ` \n\
        0-9 \n\
        -  + \n\
        backspace \n\
        return/enter \n\
        a-z \n\
        space \n\
        [  ]  ;  '  \\  ,  .  / \n\
        lshift  rshift \n\
        lctrl  rctrl \n\
        lalt  ralt \n\
        lsuper/lwin  rsuper/rwin \n\
        menu \n\
        tab \n\
        capslock \n\
        insert  delete \n\
        home  end \n\
        pageup  pagedown \n\
        numlock \n\
        num0-num9 \n\
        num+  num-  num*  num/  num. \n\
        up  left  down  right \n\
\n\
EXAMPLE \n\
        xkeycheck left && echo \"left arrow key is down\" \n\
\n\
");
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        die("exactly one parameter required (try \"xkeycheck --help\")");
    }
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        help();
        return 0;
    }
    dpy = XOpenDisplay(NULL);
    XQueryKeymap(dpy, keys_return);
    KeyCode code = XKeysymToKeycode(dpy, getKeySym(argv[1]));
    XCloseDisplay(dpy);
    return !(keys_return[ code >> 3 ] & (1 << (code & 7)));
}
