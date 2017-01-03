/* pad.cpp - implements pad class */

#include "pad.h"

PSX_Pad::PSX_Pad(u_int port)
{
	if( port != 0 && port != 1 ){
		printf("Invalid port number: %d\n", port);
		printf("Setting port to 1 (technically 0) instead!\n");

		this->port = 0;
	}else{
		this->port = port;
	}

	padInfo = 0;
	SysPad  = 0;
	SysPadT = 0;
}

void PSX_Pad::read(void)
{
	/* PSYQ pad read call */
	padInfo = PadRead(0);

	/* taken from orion psxlib */
	SysPadT = padInfo & (padInfo ^ SysPad);
	SysPad  = padInfo;
}

bool PSX_Pad::checkPressed(u_int button)
{
	return (SysPad & _PAD(port, button));
}


