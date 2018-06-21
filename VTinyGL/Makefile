CC = gcc
AR = ar
RANLIB = ranlib
CFLAGS = -std=gnu99 -I/usr/include/SDL -Iutil -Isrc -Iinclude -O0 -g
CXXFLAGS = $(CFLAGS)
OUTPUT = tinygles.a

OBJS = ./src/api.o  ./src/get.o     ./src/list.o      ./src/vertex.o   ./src/zline.o ./src/vgl.o \
	./src/arrays.o  ./src/glx.o         ./src/matrix.o       ./src/oscontext.o  ./src/zmath.o \
	./src/clear.o   ./src/image_util.o  ./src/memory.o       ./src/select.o     ./src/ztriangle.o \
	./src/clip.o    ./src/init.o        ./src/misc.o         ./src/specbuf.o    ./src/zbuffer.o \
	./src/error.o   ./src/light.o       ./src/msghandling.o  ./src/texture.o    ./src/zdither.o ./src/blend.o
		
all: ${OUTPUT} toar

${OUTPUT}:${OBJS}
	${CC} -c -o  ${OBJS} ${CFLAGS} 

toar:
	$(AR) cr ${OUTPUT} ${OBJS}
	$(RANLIB) ${OUTPUT}	

clean:
	rm  ${OBJS}  ${OUTPUT}
