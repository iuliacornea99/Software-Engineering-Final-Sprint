# Sprint 5, Team 2

By: Dushan Terzikj (d.terzikj@jacobs-university.de), Iulia Cornea (i.cornea@jacobs-university.de)

PencilProducer
=============

Compiling and Testing
---------------------
Compiling of the source tree is automated via CMake. You can build the sources
using the following commands:
```
$ mkdir build
$ cd build
$ cmake ..
```

Finally, install the binaries using while you are in build folder:
```
$ make
```

To build the documentation, go to the build folder and type:
```
$ make doc
```

Binaries are built in the `build/` directory.
```
$ ./src/pencile_producer
```

To run testing, first make sure you are in the build folder and run make:
```
$ cd test
$ ./test_welcome
```

If there are any errors with building, you are probably missing some dependencies. See the dependencies below.


Dependencies
------------
To build this software, one needs:
- g++
- cmake
- make
- pkg-config
- GoogleTests

The core PencilProducer executable require:
- qt5-default 

The documentation target requires:
- doxygen

If you still cannot build the project, call technical support from the contributors.

## Fix up for Sprint 4
- [x] Save is implemented on exit instead of a button and select a file
- [x] Upgrade the APM

## Fix up for Sprint 5
- [x] Fixed API.
- [x] Added a refresh button on the welcome screen for refreshing highscores.
- [x] Project was restructured.
- [x] Added extra debugging tools (intelligence, marketing and pencils in inventory)
- [x] Added game-over window once total pencils reaches 25k.
- [x] Improved classes OOP concept structure (well defined private and public sectors), (apm.h).
- [x] Documented all functions in the codebase and added inline comments.
- [x] Improved gameplay UI.

