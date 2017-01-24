#include "app.h"
#include "3DShape.h"

#ifndef QUAD3D_H_INCLUDED
#define QUAD3D_H_INCLUDED


class PSX_3DQuad : public PSX_3DShape
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
	
	//private:
	
		POLY_G4 plane;          // the primitive to draw
		//u_int   color[4][3];    // colors of each point
		VECTOR color[4];          // colors of each point
};

#endif

