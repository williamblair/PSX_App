/* pad.h - header for pad class */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <libetc.h>

#include <libpad.h>

#ifndef PSX_PAD_INCLUDED
#define PSX_PAD_INCLUDED

/* modified from Orion's psx library */
#define PadUp           PADLup
#define PadDown	        PADLdown
#define PadLeft	        PADLleft
#define PadRight		PADLright
#define PadTriangle     PADRup
#define PadCross		PADRdown
#define PadSquare		PADRleft
#define PadCircle		PADRright
#define PadL1			PADL1
#define PadL2			PADL2
#define PadR1			PADR1
#define PadR2			PADR2
#define PadStart		PADstart
#define PadSelect		PADselect


class PSX_Pad
{
	public:
		// constructor
		PSX_Pad(u_int port);

		void read(void); // read pad data

		bool checkPressed(u_int button); // returns true if sent button is held down
	private:
	
		int port; // is it controller 1 or 2?

		int padInfo; // contains read in pad information

		/* these 2 taken from Orion's psx lib 
		 * used for pad info manipulation */
		int SysPad;
		int SysPadT;
};

#endif


