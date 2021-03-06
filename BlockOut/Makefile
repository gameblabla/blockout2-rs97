#---------------------------------------------------------------------
# Makefile for BlockOut
#
# ubuntu 12.04 LTS needed packages.
#
#  libgl1-mesa-swx11-dev
#  libglu1-mesa-dev
#  libxext-dev
#  libsdl1.2-dev
#  libsdl-mixer1.2-dev
#
#---------------------------------------------------------------------
# All source files needed for the application
#

SRC = 	BlockOut.cpp         PageChooseSetup.cpp       PageStartGame.cpp \
	EditControl.cpp      PageControls.cpp          Pit.cpp \
	Game.cpp             PageCredits.cpp           PolyCube.cpp \
	Http.cpp             PageHallOfFame.cpp        SetupManager.cpp \
	InitPolyCube.cpp     PageHallOfFameOnLine.cpp  SoundManager.cpp \
	Menu.cpp             PageHttp.cpp              Sprites.cpp \
	MenuGraphics.cpp     PageMainMenu.cpp          Utils.cpp \
	MenuGrid.cpp         PageOptions.cpp           PageChangeSetup.cpp  \
	PageScoreDetails.cpp PageGSOptions.cpp         BotPlayer.cpp \
	BotPlayerAI.cpp      BotMatrix.cpp \
	GLApp/GLApp.cpp  GLApp/GLFont.cpp  GLApp/GLMatrix.cpp  GLApp/GLSprite.cpp

OBJ=    BlockOut.o         PageChooseSetup.o       PageStartGame.o \
	EditControl.o      PageControls.o          Pit.o \
	Game.o             PageCredits.o           PolyCube.o \
	Http.o             PageHallOfFame.o        SetupManager.o \
	InitPolyCube.o     PageHallOfFameOnLine.o  SoundManager.o \
	Menu.o             PageHttp.o              Sprites.o \
	MenuGraphics.o     PageMainMenu.o          Utils.o \
	MenuGrid.o         PageOptions.o           PageChangeSetup.o  \
	PageScoreDetails.o PageGSOptions.o         BotPlayer.o \
	BotPlayerAI.o      BotMatrix.o \
	GLApp/GLApp.o  GLApp/GLFont.o  GLApp/GLMatrix.o  GLApp/GLSprite.o

#---------------------------------------------------------------------

ADD_LIBS = ../ImageLib/src/libimagelib.a
SDL_LIBS =

CXX		= g++

CXXFLAGS =     -O0 -g -Dlinux -DTINYSDGL -c -DRS97 \
               -I/usr/include/SDL -I../ImageLib/src -I.

LFLAGS   =  $(ADD_LIBS) \
		-lSDL_mixer -lSDL -lasound \
		../VTinyGL/tinygles.a -lpthread -lm -ldl -lpng -lz


#--------------------------------------------------------------------

all: blockout

blockout: $(OBJ)
	@echo Linking...
	@rm -f blockout
	$(CXX) $(OBJ) $(LFLAGS) -o blockout
	@echo Linking OK...

clean:
	@echo Cleaning...
	@rm -f *.o
	@rm -f GLApp/*.o
