#---------------------------------------------------------------------
# Makefile for ImageLib
#
# Note: Sorry to not have libtoolized this project but i don't have
#       enough time to do that.

#
#---------------------------------------------------------------------
# All source files needed for the library
#

SRC = 	gif/gif.cpp CImage.cpp jpg/H2v2.cpp jpg/idct.cpp jpg/jpegdecoder.cpp jpg/jpegdecodermain.cpp png/hpng.cpp


OBJ=    gif/gif.o CImage.o jpg/H2v2.o jpg/idct.o jpg/jpegdecoder.o jpg/jpegdecodermain.o png/hpng.o

#---------------------------------------------------------------------

CXX	= g++
CC	= gcc

CXXFLAGS    = -O0 -g -Dlinux -DLIBPNG16 -c -I.
CFLAGS      = -O0 -g -Dlinux -DLIBPNG16 -c -I.


#--------------------------------------------------------------------

all: libimagelib.a

libimagelib.a: $(OBJ)
	@echo Making library...
	@rm -f libimagelib.a
	ar -rv libimagelib.a $(OBJ)

clean:
	@echo Cleaning...
	@rm -f *.o
	@rm -f gif/*.o
	@rm -f jpg/*.o
	@rm -f png/*.o
	@rm -f png/png/*.o
	@rm -f png/zlib/*.o

