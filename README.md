# PSX_App
Class for making Playstation 1 apps using PSYQ

ABOUT
--------
PSYQ is the official SONY development kit for the Playstation 1; it's available at:
	
	http://www.psxdev.net/downloads.html
	
Most of the code here is adapted from PSXDEV's hello world tutorial, and also Orion's PSX Library: 

	http://www.psxdev.net/help/psyq_hello_world.html
	http://onorisoft.free.fr/retro.htm<
	
PSYQ also comes with the developer's guide and reference manuals for the SDK, which are stored as PDFs in the DOCS folder of psyq.

Because of its age, PSYQ is only guranteed to work on Windows XP or earlier; So you can either dig up an old computer...
Or run a virtual machine! I use <a href="https://www.virtualbox.org/wiki/VirtualBox">Virtualbox</a>. My favorite feature is 
shared folders, which allows the virtual machine to access specifed directories on your computer. This means you can do all of your coding
and testing on your host machine, and the virtual machine only has to compile; while both the host and virtual machine are working
with the same directory.

USING THE LIBRARY
-----------------
The built in Make utility for psyq, <i>psymake</i>, seems to give me trouble alot of the time if I add too much to it. 
So, what I usually do is leave only the basic compiling to psymake, then have batch files do the rest. Check out the example
folder for more details

TESTING YOUR GAME
-----------------
You will need either a modded PS1 or an emulator to run your game. Some emulators include <a href="http://www.epsxe.com/">epsxe</a>,
<a href="https://pcsxr.codeplex.com/">pcsxr</a>, and <a href="http://www.emulator-zone.com/doc.php/psx/psx_em.html">pSX</a>. I use pcsxr, 
just because it's worked the best for me, and you can directly run psx EXEs in it without having to create a cd image.

If you feel motivated, I highly reccommend checking out <a href="http://ps-io.com/">ps-io</a>, a device that plugs into the back of
your fat PS1 (has to be the big grey one) and lets you run games from a SD card or over USB! Running over USB is super useful for
testing your software on actual hardware. However, ps-io is kind of expensive and requires some tricky soldering to install,
so beware.

OTHER PS1 STUFF:
---------------------------
https://github.com/simias/psxsdk - the github for psxsdk, an open source PS1 development library
http://unhaut.x10host.com/psxsdk/ - website for above SDK
https://code.google.com/archive/p/psxsdk/downloads - you can find a windows 32 bit version of ps2sdk here (...win32-inst.exe)
psxsdk comes with a command line disc creation utility that I use along with PSYQ for creating disc images

http://www.psxdev.net/forum/viewforum.php?f=64 - examples using PSYQ

