# Petipa API draft

The software has two main parts.

The Editor is written in C++, and uses the same code for all the supported platforms.
It handles all the business logic, and the rendering and interactions of the choreography editor.
It uses the following libraries:

* [SDL](https://libsdl.org) to access device's display and input
* [libnyquist](https://github.com/ddiakopoulos/libnyquist) to decode audio files
* [PortAudio](http://portaudio.com) to play audio
* [SOIL2](https://github.com/SpartanJ/soil2) to load image files as OpenGL textures
* [JSON for Modern C++](https://github.com/nlohmann/json) to handle JSON files for serialization


The Native part is to be written in the "natural" language of each platform (eg. Swift for iOS, Kotlin for Android).
It will initialize the application, call the Editor `run` method when the user opens a project, and provide methods for the Editor to open some dialogs:

* Visualization options
* Music setup
* Stage setup
* Charactgers and Tags setup
* Alert and Choice dialogs

The main design goal of the API is to keep the Native part as thin as possible.
