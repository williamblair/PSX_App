::Example file for compilation of the project

:: compile the exe
ccpsx -O3 -Xo$80010000 *.cpp -omain.cpe,main.sym,mem.map
pause

:: converts the generated cpe file to a PSX EXE file, which can be run by an emulator
cpe2x main.cpe
pause
