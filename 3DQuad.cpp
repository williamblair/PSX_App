
#include "3DQuad.h"

PSX_3DQuad::PSX_3DQuad()
{
	/* set the correct number of points */
	numPoints = 4;

	/* initialize the primitive */
	SetPolyG4(&plane);

	/* initialize the pos array */
	pos = new SVECTOR[4];
	
	/* initilize its coordinates */
	setVector(&pos[0], -128, -128, 0); setVector(&pos[1], 128, -128, 0);
	setVector(&pos[2], -128,  128, 0); setVector(&pos[3], 128,  128, 0);
	
	/* initialize its colors array
	 * defaults to white */
	for(int i=0; i<4; i++)
	{
		color[i].vx = 255;
		color[i].vx = 255;
		color[i].vx = 255;
	}
	
	/* apply the array to the actual coloring */
	setRGB0(&plane, color[0].vx, color[0].vy, color[0].vz);
	setRGB1(&plane, color[1].vx, color[1].vy, color[1].vz);
	setRGB2(&plane, color[2].vx, color[2].vy, color[2].vz);
	setRGB3(&plane, color[3].vx, color[3].vy, color[3].vz);
	
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
	/* set the correct number of points */
	numPoints = 4;

	/* initialize the primitive */
	SetPolyG4(&plane);

	/* initialize the pos array */
	pos = new SVECTOR[4];

	/* initilize its coordinates */
	setVector(&pos[0], x1, y1, z1); setVector(&pos[1], x2, y2, z2);
	setVector(&pos[2], x3, y3, z3); setVector(&pos[3], x4, y4, z4);
	
	/* initialize its colors array */
	color[0].vx = r1; color[0].vy = g1; color[0].vz = b1;
	color[1].vx = r2; color[1].vy = g2; color[1].vz = b2;
	color[2].vx = r3; color[2].vy = g3; color[2].vz = b3;
	color[3].vx = r4; color[3].vy = g4; color[3].vz = b4;
	
	/* apply the array to the actual coloring */
	setRGB0(&plane, color[0].vx, color[0].vy, color[0].vz);
	setRGB1(&plane, color[1].vx, color[1].vy, color[1].vz);
	setRGB2(&plane, color[2].vx, color[2].vy, color[2].vz);
	setRGB3(&plane, color[3].vx, color[3].vy, color[3].vz);
	
	/* initialize the angle */
	ang.vx = 0;
	ang.vy = 0;
	ang.vz = 0;
}


void PSX_3DQuad::draw(void)
{
	/* save the current matrix on the stack */
	PushMatrix();

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
	
	/* rotate and shift each vertex of the prim */
	RotTransPers(&pos[0], (long *)&plane.x0, &dmy, &flg);
	RotTransPers(&pos[1], (long *)&plane.x1, &dmy, &flg);
	RotTransPers(&pos[2], (long *)&plane.x2, &dmy, &flg);
	RotTransPers(&pos[3], (long *)&plane.x3, &dmy, &flg);


	/* draw the primitive */
	DrawPrim(&plane);
	
	/* Reload the saved matrix */
	PopMatrix();

	return;
}
