#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/gl.h>

#include <SDL/SDL.h>
#include "zbuffer.h"

void gluPerspective( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar ) {
		
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLdouble fW, fH;
	fH = tan( fovY / 360 * pi ) * zNear;
	fW = fH * aspect;
	glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}

SDL_Surface* screen;
static ZBuffer *frameBuffer;

void vglInit(unsigned short width, unsigned short height) 
{
    SDL_Init( SDL_INIT_EVERYTHING );
    screen = SDL_SetVideoMode(width, height, 16, SDL_HWSURFACE);
	SDL_ShowCursor(SDL_DISABLE);
    frameBuffer = ZB_open( width, height, ZB_MODE_5R6G5B, 0, 0, 0, 0);
    glInit( frameBuffer );
}

void vglSwap() 
{
	SDL_LockSurface(screen);
	ZB_copyFrameBuffer(frameBuffer, screen->pixels, screen->pitch);
	SDL_UnlockSurface(screen);
	SDL_Flip(screen);
}

void vglClose() 
{
	if (screen) SDL_FreeSurface(screen);
	SDL_Quit();
	
}

void * vglGetFramebuffer() 
{
    return (void *) screen->pixels;
}
