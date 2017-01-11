
#include "3DShape.h"
#include <stdio.h>
#include <stdlib.h>

PSX_3DShape::PSX_3DShape()
{

	/* be safe with the pointers */
	pos  = NULL;
			
	/* set the default angle */
	ang.vx = 0;
	ang.vy = 0;
	ang.vz = 0;
	
	/* initialize the work longs */
	dmy = 0;
	flg = 0;
	
	numPoints = 0;
}


void PSX_3DShape::rotate(short x, short y, short z)
{
	/* apply the angles 
	 * example rotates 32 units at a time */
	ang.vx += x;
	ang.vy += y;
	ang.vz += z;
	
	/* reset angles if necessary */
	if( ang.vx > 4096 )    ang.vx = ang.vx - 4096;
	else if(ang.vx < 0) ang.vx = ang.vx + 4096;
	
	if( ang.vy > 4096 )    ang.vy = ang.vy - 4096;
	else if(ang.vy < 0) ang.vy = ang.vy + 4096;
	
	if( ang.vz > 4096 )    ang.vz = ang.vz - 4096;
	else if(ang.vz < 0) ang.vz = ang.vz + 4096;
	
	return;
}

/* getter functions */
short PSX_3DShape::getAngX(void){
	return ang.vx;
}

short PSX_3DShape::getAngY(void){
	return ang.vy;
}

short PSX_3DShape::getAngZ(void){
	return ang.vz;
}

short PSX_3DShape::getPos(u_int posNum, char vector)
{	short posVal = -1; // the return value
	
	if( posNum >= 0 && posNum < numPoints ) {
		switch(vector)
		{
			case 'x':
			case 'X':
				posVal = pos[posNum].vx;
				break;
			case 'y':
			case 'Y':
				posVal = pos[posNum].vy;
				break;
			case 'z':
			case 'Z':
				posVal = pos[posNum].vz;
				break;
			default:
				break;
		}
	}
	
	return posVal;
}
