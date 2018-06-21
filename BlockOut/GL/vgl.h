#ifndef VGL_H
#define VGL_H

typedef double GLdouble;

#ifdef __cplusplus
extern "C" {
#endif

void vglInit(unsigned short width, unsigned short height);
void vglSwap();
void vglClose();
void * vglGetFramebuffer();

// helper
void gluPerspective( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar );

#ifdef __cplusplus
}
#endif

#endif // VGL_H
