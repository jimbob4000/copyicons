## About This Fork

### Overview
This fork provides a library implementation of CopyIcons that allows for individual copying of icon0.png and pic0.png images, rather than bulk copying.  

It is designed for use with my customized fork of [**lpp-vita**](https://github.com/jimbob4000/lpp-vita), which has been customised for [**RetroFlow Launcher**](https://github.com/jimbob4000/RetroFlow-Launcher).


### Building

Ensure that **VitaSDK** is installed and properly configured in your `PATH` environment variable before proceeding.
Navigate to the library directory an build using:

`cd copyicons-master/source/include/copyicons`
`mkdir build && cd build`
`cmake .. -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake`
`make`

### Credit:
Copyicons was originally made by [cy33hc](https://github.com/cy33hc) you will the original readme below.

________


# copyicons

This application is used for bulk copying of icon0.png/pic0.png from the ux0:app/GAME_ID/sce_sys to the ur0:appmeta/GAME_ID folder

The psvita can only load 500 bubbles. If you have more then 500 apps/games installed. The vita will not create the icon0.png and pic0.png files in the ur0:appmeta folder for those games that don't have bubbles.

This is used in conjuction with my Launcher app https://github.com/cy33hc/vita-launcher for getting icons to display for the games.

## Features

1. Decrypt the icon0.png/pic0.png and copy to ur0:appmeta.
2. Like mentioned this app scans every game in the ux0:app folder and copies the icon0.png/pic0.png if it's not found in ur0:appmeta

## Controls
There are no controls. Just run the app and wait for it to complete. Progress is shown on the screen.

## Credits
Thx to theFlow for Vitashell. I had copied the modules from Vitashell needed to pfs mount the game to decypt the content.
https://github.com/TheOfficialFloW/VitaShell
