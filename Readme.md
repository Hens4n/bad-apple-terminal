# Bad Apple Terminal
It's just a personal project to play "Bad Apple!!" on the terminal
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
### How to execute?
Before running the program enter the path to the bad apple, like:
```
./BadApple ~/path/to/badapple.mp4
````
### Generating frames from the video
This project uses [ffmpeg](https://ffmpeg.org/) and [imagemagick](https://imagemagick.org/index.php) respectively to extract and resize frames, and convert all frames to grayscale. For some reason the exec family functions for executing linux commands was not working with imagemagick, so I used system() (defined in the stdlib header) for ffmpeg and imagemagick.
### Dealing with frames
To deal with frames, we use a JPEG library called [jpeglib](https://www.ijg.org/) which is responsible for decompressing the binaries of a jpeg file.
### Headers information
#### filemnp.h
Responsible for the functions of opening images.
#### imagemnp.h
Handles frame extraction, grayscale and image to ASCII conversion.
#### ascii.h
Responsible for the functions of converting pixel values to ASCII characters.
