#include "app.h"

#ifndef SHAPE3D_H_INCLUDED
#define SHAPE3D_H_INCLUDED

#define SCR_Z	1024		/* distance to screen*/

class PSX_3DShape
{
	public:
	
		PSX_3DShape(); // constructor
		
		/* remember: 4096 = 360deg in psx terms! */
		void rotate(short x, short y, short z);
		
		/* getter functions */
		short getAngX(void);
		short getAngY(void);
		short getAngZ(void);
		
		short getPos(u_int posNum, char vector);
	
	protected:
		SVECTOR ang;    // the angle of the plane

		long dmy, flg; // used for rotation placeholders

		u_int numPoints; // the number of points in the primitive,
		                  // eg 3 or 4

		SVECTOR *pos;         // array of coordinates
		
};

#endif

