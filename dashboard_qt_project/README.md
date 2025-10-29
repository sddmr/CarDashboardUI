Qt Dashboard Demo (C++ / Qt Widgets)
=================================

What this is
------------
A minimal Qt Widgets project implementing a simple dashboard UI inspired by your design. It uses placeholder images which you can replace with your real assets (e.g. 50.png, 70.png, car.png, solsinyal.png, sagsinyal.png, hizsabit.png).

Files
-----
- dashboard.pro        : qmake project file
- main.cpp
- mainwindow.h / .cpp
- resource.qrc         : Qt resource file listing images
- images/              : placeholder images (replace with your own)
- README.md

How to build
------------
1. Install Qt (Qt 5 or Qt 6) and qmake.
2. Open a terminal in the project folder and run:
   qmake
   make   (or mingw32-make on Windows)

Or open the project in Qt Creator and build/run from there.

Replacing images
----------------
Put your actual assets into the images/ directory with the same filenames as in resource.qrc:
- background.png
- 50.png
- 70.png
- car.png
- solsinyal.png
- sagsinyal.png
- hizsabit.png

Then rebuild the project (qmake may be required to refresh resources).

Notes
-----
- This is a starting template. You can expand it: use QML for smoother UI, add animations, sensors, and connect to real telemetry data.
- If you want, tell me which Qt version you will use and I can adapt the project (CMake or QML) or add features (e.g., clickable controls, network input).

