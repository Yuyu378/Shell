This project is licensed under the terms of the GPLv3+.
This project is written, compiled and tested using VScode, and is not guaranteed.

This project has only been tested on Win11 and Ubuntu 22.04, and is not warranted to run smoothly on other platforms.

The compilation and testing environment for Win11 is UCRT64, which can be installed using MSYS2:

	1. Go to www.msys2.org to install the software distribution and construction platform for Windows.
	2. Run "pacman -Syu" at the end of the UCRT64 environment to update MSYS2.
	3. run "pacman -S mingw-w64-ucrt-x86_64-toolchain" on the UCRT64 environment terminal
	4. Add C:\msys64\ucrt64\bin (this is the default path) to the environment variables

The Ubuntu 22.04 compiler test environment is GNU, which is installed by default in the operating system.

The VScode runtime build and debug files are in the Windows 11 and Ubuntu 22.04 folders.
To test in VScode, copy the .vscode folder from the folder to the Shell folder, and open it with VScode to test.

If you have another preferred IDE, just import the original files from Shell into that IDE.