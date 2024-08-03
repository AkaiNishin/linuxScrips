#!/bin/bash

# Use the full path for gsettings
GSETTINGS=/usr/bin/gsettings
current_state=$($GSETTINGS get org.gnome.shell.extensions.dash-to-dock dock-fixed)

if [ "$current_state" == "true" ]; then
    $GSETTINGS set org.gnome.shell.extensions.dash-to-dock dock-fixed false
else
    $GSETTINGS set org.gnome.shell.extensions.dash-to-dock dock-fixed true
fi

