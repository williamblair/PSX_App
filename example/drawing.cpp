/* drawing.cpp - contains functions for drawing primitives */

#include "app.h"

void PSX_App::setBgColor(u_char r, u_char g, u_char b)
{
    bgcolor[0] = r;
    bgcolor[1] = g;
    bgcolor[2] = b;

    return;
}

void PSX_App::drawLine(const int x0, const int y0,
                       const int x1, const int y1,
                       const int r, const int g, const int b)
{
    LINE_F2 line;
    SetLineF2(&line);
    setXY2(&line, x0, y0, x1, y1);
    setRGB0(&line, r, g, b);

    DrawPrim(&line);

    return;
}

void PSX_App::drawPixel(const int x, const int y,
                        const int r, const int g, const int b)
{
    LINE_F2 line;
	SetLineF2(&line);
	setXY2(&line, x, y, x, y); // line where both coords are the same
	setRGB0(&line, r, g, b);

    DrawPrim(&line);

    return;
}

void PSX_App::drawRect(const int topLeftX, const int topLeftY,
                       const int bottomRightX, const int bottomRightY,
                       const int r, const int g, const int b)
{
    POLY_F4 rect;
    SetPolyF4(&rect);
    setXY4(&rect, topLeftX,      topLeftY,
                  bottomRightX,  topLeftY,
                  topLeftX,      bottomRightY,
                  bottomRightX,  bottomRightY);

    setRGB0(&rect, r, g, b);

    DrawPrim(&rect);

    return;
}
