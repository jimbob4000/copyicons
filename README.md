## Fork of copyicons 

### Overview
This fork provides a library implementation of CopyIcons that allows for individual copying of icon0.png and pic0.png images, rather than bulk copying.  

It is designed for use with my customized fork of [**lpp-vita**](https://github.com/jimbob4000/lpp-vita), which has been customised for [**RetroFlow Launcher**](https://github.com/jimbob4000/RetroFlow-Launcher).


### Building

Ensure that **VitaSDK** is installed and properly configured in your `PATH` environment variable before proceeding.
Navigate to the 'source/include/copyicons' directory then build using:


`mkdir build && cd build`

`cmake .. -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake`

`make`

### Credit:
Copyicons was originally made by [cy33hc](https://github.com/cy33hc) see their repository for more information.