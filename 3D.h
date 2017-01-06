#include "app.h"

#ifndef THREED_H_INCLUDED
#define THREED_H_INCLUDED

#define SCR_Z	1024		/* distance to screen*/

class PSX_3DQuad
{
	public:
	
		PSX_3DQuad(); // constructor
		PSX_3DQuad(u_int x1, u_int y1, u_int z1, // the coordinates for each point
		            u_int x2, u_int y2, u_int z2,
		            u_int x3, u_int y3, u_int z3,
		            u_int x4, u_int y4, u_int z4, 
		            u_int r1, u_int g1, u_int b1, // the color of each point 
		            u_int r2, u_int g2, u_int b2,
		            u_int r3, u_int g3, u_int b3,
		            u_int r4, u_int g4, u_int b4 );
		            
		void draw(void);
		
		/* remember: 4096 = 360deg in psx terms! */
		void rotate(short x, short y, short z);
		
		/* getter functions */
		short getAngX(void);
		short getAngY(void);
		short getAngZ(void);
	
	private:
	
		SVECTOR pos[4]; // the position of each corner
		POLY_G4 plane;  // the actual primitive object
		
		long dmy, flg; // used for rotation placeholders
		
		SVECTOR ang;    // the angle of the plane
		
		u_int   color[4][3];    // colors of each point
};

#endif
