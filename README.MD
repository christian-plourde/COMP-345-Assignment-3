COMP 345 Assignment #3 Team #4

Group Members:
Christian Plourde I.D. 26572499 Jack Burns I.D. 40033754

WARNING
-------------------------------------------------------------------------------------------------------------
If attempting to run this code in Visual Studio or Eclipse, you may encounter an error with the inclusion of file "dirent.h". This is because this file is not included in the C++ compiler with these IDE. To fix this with Visual Studio, dirent.h (included with this code) needs to be placed in Visual Studio's Include folder. This can typically be found in C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.15.26726\include

Part 1
-------------------
The three strategies are implemented with cpu turns requiring no input from the user. The game is possible to play as just two cpu players. Their turns are part of the main driver.

Part 2 & 3
-------------------
The two observers can be tested by running main.exe, found in the driver folder. It can also be recompiled by compiling the main.cpp file in the same folder, which contains the main method for this driver. During the course of the game, the observers will output different messages at appropriate times, allowing the user to view their functionality and to validate that they are working correctly.