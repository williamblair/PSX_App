# PSX_App
Class for making Playstation 1 apps using PSYQ

ABOUT
--------
PSYQ is the official SONY development kit for the Playstation 1; it's available at:
	
	http://www.psxdev.net/downloads.html
	
Most of the code here is adapted from PSXDEV's hello world tutorial, and also Orion's PSX Library: 

	http://www.psxdev.net/help/psyq_hello_world.html
	http://onorisoft.free.fr/retro.htm
	
PSYQ also comes with the developer's guide and reference manuals for the SDK, which are stored as PDFs in the DOCS folder of psyq.

Because of its age, PSYQ is only guranteed to work on Windows XP or earlier; So you can either dig up an old computer...
Or run a virtual machine! I use <a href="https://www.virtualbox.org/wiki/VirtualBox">Virtualbox</a>. My favorite feature is 
shared folders, which allows the virtual machine to access specifed directories on your computer. This means you can do all of your coding
and testing on your host machine, and the virtual machine only has to compile; while both the host and virtual machine are working
with the same directory.


USING THE LIBRARY
-----------------
The built in Make utility for psyq, <i>psymake</i>, seems to give me trouble alot of the time if I add too much to it. 
So, what I usually do is leave only the basic compiling to psymake, then have batch files do the rest.
