
#include "3D.h"

PSX_3DQuad::PSX_3DQuad()
{
	/* initialize the primitive */
	SetPolyG4(&plane);
	
	/* initilize its coordinates */
	setVector(&pos[0], -128, -128, 0); setVector(&pos[1], 128, -128, 0);
	setVector(&pos[2], -128,  128, 0); setVector(&pos[3], 128,  128, 0);
	
	/* initialize its colors array
	 * defaults to white */
	for(int i=0; i<4; i++)
	{
		color[i][0] = 255;
		color[i][1] = 255;
		color[i][2] = 255;
	}
	
	/* apply the array to the actual coloring */
	setRGB0(&plane, color[0][0], color[0][1], color[0][2]);
	setRGB1(&plane, color[1][0], color[1][1], color[1][2]);
	setRGB2(&plane, color[2][0], color[2][1], color[2][2]);
	setRGB3(&plane, color[3][0], color[3][1], color[3][2]);
	
	/* set the default angle */
	ang.vx = 0;
	ang.vy = 0;
	ang.vz = 0;
	
	/* initialize the work longs */
	dmy = 0;
	flg = 0;
}

PSX_3DQuad::PSX_3DQuad(u_int x1, u_int y1, u_int z1, // the coordinates for each point
                         u_int x2, u_int y2, u_int z2,
                         u_int x3, u_int y3, u_int z3,
                         u_int x4, u_int y4, u_int z4, 
                         u_int r1, u_int g1, u_int b1, // the color of each point 
                         u_int r2, u_int g2, u_int b2,
                         u_int r3, u_int g3, u_int b3,
                         u_int r4, u_int g4, u_int b4 )
{
	/* initialize the primitive */
	SetPolyG4(&plane);
	
	/* initilize its coordinates */
	setVector(&pos[0], x1, y1, z1); setVector(&pos[1], x2, y2, z2);
	setVector(&pos[2], x3, y3, z3); setVector(&pos[3], x4, y4, z4);
	
	/* initialize its colors array */
	color[0][0] = r1; color[0][1] = g1; color[0][2] = b1;
	color[1][0] = r2; color[1][1] = g2; color[1][2] = b2;
	color[2][0] = r3; color[2][1] = g3; color[2][2] = b3;
	color[3][0] = r4; color[3][1] = g4; color[3][2] = b4;
	
	/* apply the array to the actual coloring */
	setRGB0(&plane, color[0][0], color[0][1], color[0][2]);
	setRGB1(&plane, color[1][0], color[1][1], color[1][2]);
	setRGB2(&plane, color[2][0], color[2][1], color[2][2]);
	setRGB3(&plane, color[3][0], color[3][1], color[3][2]);
	
	/* initialize the angle */
	ang.vx = 0;
	ang.vy = 0;
	ang.vz = 0;
}

void PSX_3DQuad::rotate(short x, short y, short z)
{
	/* apply the angles 
	 * example rotates 32 units at a time */
	ang.vx += x;
	ang.vy += y;
	ang.vz += z;
	
	/* reset angles if necessary */
	if( ang.vx > 4096 ) ang.vx = ang.vx - 4096;
	if( ang.vy > 4096 ) ang.vy = ang.vy - 4096;
	if( ang.vz > 4096 ) ang.vz = ang.vz - 4096;
	
	return;
}

void PSX_3DQuad::draw(void)
{
	/* translate vector */
	VECTOR vec = {0, 0, SCR_Z};
	
	/* work matrix */
	MATRIX m;
	
	/* rotate */
	RotMatrix(&ang, &m);
	
	/* translate */
	TransMatrix(&m, &vec);
	
	/* set rotation */
	SetRotMatrix(&m);
	
	/* set translation */
	SetTransMatrix(&m);
	
	/* rotate and shift each vertex of the wall */
	RotTransPers(&pos[0], (long *)&plane.x0, &dmy, &flg);
	RotTransPers(&pos[1], (long *)&plane.x1, &dmy, &flg);
	RotTransPers(&pos[2], (long *)&plane.x2, &dmy, &flg);
	RotTransPers(&pos[3], (long *)&plane.x3, &dmy, &flg);
	
	/* draw the plane */
	DrawPrim(&plane);
	
	return;
}

/* getter functions */
short PSX_3DQuad::getAngX(void){
	return ang.vx;
}

short PSX_3DQuad::getAngY(void){
	return ang.vy;
}

short PSX_3DQuad::getAngZ(void){
	return ang.vz;
}

