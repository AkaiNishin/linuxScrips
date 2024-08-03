#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <twitch_channel_name>"
    exit 1
fi

CHANNEL=$1
URL=$(yt-dlp -g "https://www.twitch.tv/$CHANNEL")

if [ -z "$URL" ]; then
    echo "Failed to retrieve the stream URL."
    exit 1
fi

# Start mpv with the specified URL
mpv --title="Twitch - $CHANNEL" --geometry=500x300 --force-window=yes "$URL" &

# Get the PID of mpv
MPV_PID=$!

# Wait for mpv to start and create a window
sleep 2

# Use wmctrl to set the mpv window to always be on top
wmctrl -r "Twitch - $CHANNEL" -b add,above

# Wait for the mpv process to finish
wait $MPV_PID

