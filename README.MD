# xkeycheck

xkeycheck is a small shell utility for X which determines whether or not a key is being pressed down or not.
I wrote it because I was missing a simple, quick way of obtaining keyboard information in my shell scripts.

## Example usage

    xkeycheck a && echo "key a is down"

## Installation

Arch Linux users can install the `xkeycheck-git` AUR package.

You only need Xlib installed, which comes by default on most Unix installations.

Then, run the following (if necessary, as root):

    make install
