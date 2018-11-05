CC         = -gcc
GCC        = -g++

TOP = $(shell pwd)
SRCDIR = $(TOP)/src
INCDIR = $(TOP)/include

SOURCES = \
	$(wildcard $(SRCDIR)/*.cpp )

INCLUDES = \
	-I$(INCDIR)

INCLUDE_SFML = \
	-I/usr/local/include

CFLAGS = \
	-std=c++17 \
	-lsfml-system \
	-lsfml-graphics \
	-lsfml-window \
	-lm
	#-framework sfml-system 
	#-framework sfml-graphics 
	 

rpg:$(SOURCES)
	$(GCC) -o $@ $^ $(INCLUDES) $(CFLAGS) $(INCLUDE_SFML)