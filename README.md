# Cities-Of-Serbia
C++ project - making program for determination the shortest path between two chosen cities of Serbia.

## Executing program:
### 1) download the Release folder, and run "CitiesOfSerbia.exe" file
### 2) download the entire project, compile and run it using Visual Studio in release mode (in order to execute program in this way, you need to download SFML, and add following files in the Project properties:
* AllConfiguration -> C/C++ -> General -> Additional Include Directories: add the "include" folder of SFML
* AllConfiguration -> Linker -> General -> Additional Library Directories: add the "lib" folder of SFML
* Release -> Linker -> Input -> AdditionalDependecies: sfml-system.lib, sfml-window.lib, sfml-graphics.lib;
* also, you need to copy all files from SFML-version\bin to Project\Release).

* *Note*: This program is made in educational purposes, for exercising C++ and algorithms, and some of distances are approximated and are not trustworthy.
