/* example project using PSX_App */

#include "app.h"
#include "pad.h"
#include "3DQuad.h"

/* screen dimensions 
 * the most common resolution is 320x240 
 * hi res mode is 640x480 */
const u_int S_WIDTH  = 640;
const u_int S_HEIGHT = 480;

int main(void)
{
	/* the main app object */
	PSX_App app;
	
	/* initializes the psx system */
	app.init(S_WIDTH, S_HEIGHT);
	
	/* set the background color of the app 
	 * 255 max */
	app.setBgColor(50, 100, 100);

	/* tell where the geometry coordinates are relative to */
	SetGeomOffset(S_WIDTH/2, S_HEIGHT/2);
	
	/* a 3d flat quad that you can rotate, scale besides just translate */
	PSX_3DQuad square(-100, -100, 0, // coordinates
	                   100, -100, 0,
					  -100,  100, 0,
	                   100,  100, 0,
					   255,  0,   0,
					   0,    255, 0,
					   0,    0,   255,
					   255,  0,   255 );
		
	/* main game loop */
	while(1)
	{
		/* print some info to the screen */
		FntPrint("Hello PSX!\n\n");
		FntPrint("Screen Dimensions: %d x %d\n\n", S_WIDTH, S_HEIGHT);
		FntPrint("Quad Angle: (%d, %d, %d)\n\n", square.getAngX(),
		                                       square.getAngY(),
											   square.getAngZ() );
		FntPrint("Quad Coords:\n(%d, %d, %d)\n(%d, %d, %d)\n(%d, %d, %d)\n(%d, %d, %d)\n",
		                        square.getPos(0, 'x'), square.getPos(0, 'y'), square.getPos(0, 'z'),
								square.getPos(1, 'x'), square.getPos(1, 'y'), square.getPos(1, 'z'),
								square.getPos(2, 'x'), square.getPos(2, 'y'), square.getPos(2, 'z'),
								square.getPos(3, 'x'), square.getPos(3, 'y'), square.getPos(3, 'z'));
		
		/* rotate the quad */
		square.rotate(5, 7, 10);
		
		/* draw the quad */
		square.draw();
		
		/* psx system draw frame */
		app.drawFrame();
	}
	
	return 0;
}

