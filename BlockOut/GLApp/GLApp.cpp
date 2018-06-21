// -------------------------------------------
// SDL/OpenGL OpenGL application framework
// Jean-Luc PONS (2007)
// -------------------------------------------
#include "GLApp.h"
#ifndef WINDOWS
#include <unistd.h>
#endif

#undef LoadImage

#include <CImage.h>
#include "SoundManager.h"

extern char *LID(char *fileName);
extern void vglInit(unsigned short width, unsigned short height);
extern void vglSwap();
extern void vglClose();

// -------------------------------------------

GLApplication::GLApplication() {

  m_bWindowed = true;
  m_bVSync = false;
  m_strWindowTitle = (char *)"GL application";
  strcpy((char *)m_strFrameStats,"");

#if defined(PLATFORM_PSP)
  m_screenWidth = 480;
  m_screenHeight = 272;
#elif defined(PLATFORM_PSVITA)
  m_screenWidth = 960;
  m_screenHeight = 544;
#elif defined(RS97)
  m_screenWidth = 320;
  m_screenHeight = 480;
#else
  m_screenWidth = 320;
  m_screenHeight = 240;
#endif

}

// -------------------------------------------

int GLApplication::SetVideoMode() 
{
	return GL_OK;
}

// -------------------------------------------

int GLApplication::ToggleFullscreen() {

  return GL_OK;
    
}

// -------------------------------------------

int GLApplication::Create(int width, int height, BOOL bFullScreen, BOOL bVSync ) {

  int errCode;

  m_bVSync = bVSync;
  m_screenWidth = width;
  m_screenHeight = height;
  m_bWindowed = !bFullScreen;


  OneTimeSceneInit();
  errCode = RestoreDeviceObjects();

  return GL_OK;

}

// -------------------------------------------

void GLApplication::Pause(BOOL bPause) {
}

// -------------------------------------------

int GLApplication::Resize( DWORD width, DWORD height ) {

  int errCode;
  m_screenWidth = width;
  m_screenHeight = height;

  InvalidateDeviceObjects();

  errCode = RestoreDeviceObjects();
  if( !errCode ) {
    printGlError();
    exit(1);
  }

  return GL_OK;

}

// -------------------------------------------

int GLApplication::Run() {

  SoundManager np;
  SDL_Event event;

  bool quit = false;
  int  nbFrame = 0;
  int  lastTick = 0;
  int  lastFrTick = 0;
  int  errCode = false;
  int  fTick = 0;
  int  firstTick = 0;

  m_fTime        = 0.0f;
  m_fElapsedTime = 0.0f;
  m_fFPS         = 0.0f;
  lastTick = lastFrTick = firstTick = SDL_GetTicks();

  //Wait for user exit
  while( quit == false )
  {
     
     //While there are events to handle
     while( SDL_PollEvent( &event ) ) {
       if( event.type == SDL_QUIT )
         quit = true;
       else
         EventProc(&event);
     }
     fTick = SDL_GetTicks();

     // Update timing
     nbFrame++;
     if( (fTick - lastTick) >= 1000 ) {
        int t0 = fTick;
        int t = t0 - lastTick;
        m_fFPS = (float)(nbFrame*1000) / (float)t;
        nbFrame = 0;
        lastTick = t0;
       // sprintf(m_strFrameStats,"%.2f fps (%dx%dx%d)",m_fFPS,m_screenWidth,m_screenHeight,m_bitsPerPixel);
     }

     m_fTime = (float) ( fTick - firstTick ) / 1000.0f;
     m_fElapsedTime = (fTick - lastFrTick) / 1000.0f;
     lastFrTick = fTick;

     if (!quit) 
		errCode = FrameMove();
		Render();
     if( !errCode ) quit = true;
     
     //Swap buffer
     vglSwap();
  }
	np.CleanEverything();
	vglClose();

	return 0;
}

// -------------------------------------------

void GLApplication::SetMaterial(GLMATERIAL *mat) {

  float acolor[] = { mat->Ambient.r, mat->Ambient.g, mat->Ambient.b, mat->Ambient.a };
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, acolor);
  float dcolor[] = { mat->Diffuse.r, mat->Diffuse.g, mat->Diffuse.b, mat->Diffuse.a };
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dcolor);
  float scolor[] = { mat->Specular.r, mat->Specular.g, mat->Specular.b, mat->Specular.a };
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, scolor);
  float ecolor[] = { mat->Emissive.r, mat->Emissive.g, mat->Emissive.b, mat->Emissive.a };
  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, ecolor);
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat->Power);
  glColor4f(mat->Ambient.r, mat->Ambient.g, mat->Ambient.b, mat->Ambient.a);

}

// -------------------------------------------

void GLApplication::printGlError() {
  
  char message[256];

  GLenum errCode = 0;

  switch( errCode ) {
    case GL_INVALID_ENUM:
      sprintf(message,"OpenGL failure: An unacceptable value is specified for an enumerated argument. The offending function is ignored, having no side effect other than to set the error flag.");
      break;
    case GL_INVALID_VALUE:
	  sprintf(message, "OpenGL failure: A numeric argument is out of range. The offending function is ignored, having no side effect other than to set the error flag.");
      break;
    case GL_INVALID_OPERATION:
	  sprintf(message, "OpenGL failure: The specified operation is not allowed in the current state. The offending function is ignored, having no side effect other than to set the error flag.");
      break;
    case GL_STACK_OVERFLOW:
	  sprintf(message, "OpenGL failure: This function would cause a stack overflow. The offending function is ignored, having no side effect other than to set the error flag.");
      break;
    case GL_STACK_UNDERFLOW:
	  sprintf(message, "OpenGL failure: This function would cause a stack underflow. The offending function is ignored, having no side effect other than to set the error flag.");
      break;
    case GL_OUT_OF_MEMORY:
      sprintf(message, "OpenGL failure: There is not enough memory left to execute the function. The state of OpenGL is undefined, except for the state of the error flags, after this error is recorded.");
      break;
	default:
      sprintf(message, "Application failure.");
	  break;
  }


  printf(message);

}
