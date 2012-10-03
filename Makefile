###########################################################
# Project 1 Makefile

CC = g++
CFLAGS =
#CFLAGS = -Wall -ggdb
INCLUDE =
#INCLUDE = -I/lusr/X11/include -I/lusr/include
LIBDIR =
#LIBDIR = -L/lusr/X11/lib -L/lusr/lib
# Libraries that use native graphics hardware --
# appropriate for Linux machines in Taylor basement
#LIBS= -L/usr/X11R6/lib -L/usr/lib -lXext -lX11 -lGL -lGLU -lglut -lfl
#LIBS = -lglut -lGLU -lGL -lpthread -lm
LIBS = -lglut -lGLU -lGL -lm -lfl

###########################################################
# Options if compiling on Mac
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
CC = g++
CFLAGS = -Wall -g -D__MAC__
INCLUDE = 
LIBDIR = -L/lusr/X11/lib
LIBS = -framework OpenGL -framework GLUT
endif

###########################################################
# Uncomment the following line if you are using Mesa
#LIBS = -lglut -lMesaGLU -lMesaGL -lm

PROD= mocap
HDRS= $(shell ls *.h)

ifeq ($(wildcard y.tab.cpp),)
	SRCS= $(shell ls *.cpp)  y.tab.cpp lex.yy.cpp
else
	SRCS= $(shell ls *.cpp)
endif

OBJS= $(patsubst %.cpp, %.o, $(SRCS)) 

LEX= lex 
YACC= yacc 
YFLAGS= -d

all: $(PROD)

y.tab.cpp: bvh.y
	$(YACC) $(YFLAGS) $<
	mv y.tab.c y.tab.cpp

lex.yy.cpp: bvh.l 
	$(LEX) $< 
	mv lex.yy.c lex.yy.cpp

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@

$(PROD):  $(OBJS)
	./check-code main.cpp joint.h joint.cpp unit.cpp mat3.h vector3.h point3.h
	$(CC) -o $(PROD) $^ $(LIBS)

clean:
	rm -f $(PROD)
	rm -f *.o
	rm y.tab.cpp
	rm lex.yy.cpp
	rm y.tab.h

# My stuff
unit:
	g++ -o unit.cpp mat3.h point3.h vector3.h unit && ./unit