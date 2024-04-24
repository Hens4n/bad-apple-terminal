# Bad Apple Terminal
It's just a personal project to play "Bad Apple!!" on the terminal.<br/>
[See the running program](https://youtu.be/gKyNBp4C2Gk)
## Table of content
* [About the project](https://github.com/Hens4n/bad-apple-terminal#about-the-project)
* [What is Bad Apple?](https://github.com/Hens4n/bad-apple-terminal#what-is-bad-apple)
* [More information](https://github.com/Hens4n/bad-apple-terminal#more-information)

## About the project
It's just a personal project to play "Bad Apple!!" on the terminal using ASCII character. Possibly it will can be used to reproduce other things in the terminal in ASCII characters, but my goal now is to play "Bad Apple!!".

This project is also a challenge to myself to put all my knowledge and creativity into action.

## What is "Bad Apple!!"?
Briefly, "Bad Apple!!" is a popular Japanese song from the Touhou game series which got famous by the variety of places (like a [calculator](https://youtu.be/6pAeWf3NPNU)) to play the [2009 fan-released 3D clip](https://youtu.be/UkgK8eUdpAo) of this song. 

## More Information

### Cross-platform?
Not completely. The `getNumberOfFrames()` function, in `filmemnp.h`, will only work on Linux. Its functions is just to get the number of grayscale frames automatically. Because of that, the line 7 in `imagemnp.c` is commented and line 8 contains the number of grayscale frames hardcoded.

### Path Macros
`STORE_VFRAMES_PATH`, `STORE_GFRAMES_PATH` and `CONVERT_FRAMES_PATH` in `imagemnhp.h` are responsible to store the location and the pattern of each frame name. The location I chose was inside the home (on a Linux environment), with `$home/frame` storing each RGB frame and `$home/frame/gray` storing each grayscale frame.

`STORE_VFRAMES_PATH` tells the location and the name pattern for each frame (ffmpeg deals with that). The pattern chose was a simple numerical sequence with four digits, starting at 0001.

`STORE_GFRAMES_PATH` tells the location and the name pattern for each grayscale frame (imagemagick deals with that). The pattern chose was a simple numerical sequence with four digits, starting at 0000.

`CONVERT_FRAMES_PATH` tells the location and the name pattern for each RGB frame for conversion.

`GRAYSCALE_PATH` in `filemnp.h tells the location of the grayscale frames to count the number of frames inside the folder (for automation). The automation will only works on Linux, so... don't worry about it, Windows user.

### How to run?
Before running the program enter the path to the bad apple, like:
```
./BadApple /path/to/badapple.mp4
```

#### Linux
- Install the [jpeglib](https://www.ijg.org/) library, ffmpeg and imagemagick.
- Create the folders as they are in the path macros.
- If you want, uncomment line 7 and comment line 8 in `imagemnp.c`.
- Run the Makefile.

#### Windows
- Install [msys2](https://www.msys2.org/) to install gcc and the jpeglib using its package manager.
    - The command `pacman -S mingw-w64-x86_64-gcc` will install everything for you (literally everything). You should check [here](https://packages.msys2.org/package/mingw-w64-x86_64-gcc) to see what will be installed.
    - Add compiler in your path variable (`C:\msys64\mingw64\bin`, if not changed)
- Install [ffmpeg](https://ffmpeg.org/) and [imagemagick](https://imagemagick.org/index.php) and add both in your path variable.
- See `Makefile` in order to compile.

### Generating frames from the video
This project uses [ffmpeg](https://ffmpeg.org/) and [imagemagick](https://imagemagick.org/index.php) respectively to extract and resize frames, and convert all frames to grayscale.

### Dealing with frames
To deal with frames, we use a JPEG library called [jpeglib](https://www.ijg.org/) which is responsible for decompressing the binaries of a jpeg file.

### Headers information

#### filemnp.h
Responsible for the functions of opening images.

#### imagemnp.h
Handles frame extraction, grayscale and image to ASCII conversion.

#### ascii.h
Responsible for the functions of converting pixel values to ASCII characters.
