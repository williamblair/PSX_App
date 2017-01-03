# ----------------------------
# PlayStation 1 Psy-Q MAKEFILE
# ----------------------------

# example makefile - has to have the .mak extension to be recognized by psymake
all:
	ccpsx -O3 -Xo$80010000 main.cpp app.cpp system.cpp drawing.cpp pad.cpp -omain.cpe,main.sym,mem.map
