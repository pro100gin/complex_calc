vpath %.h ../include/

SOURCES = add.c sub.c divi.c mult.c
LIBS = $(addprefix lib, $(SOURCES:.c=.so))
OBJECTS = $(SOURCES:.c=.o)

all: $(LIBS)

lib%.so: %.o
		gcc -shared $< -o $@ 


$(OBJECTS): $(SOURCES)
		gcc -c $(@:.o=.c) -fPIC

$(SOURCES): operations.h

clean:
		clear
		rm -rf *.o *.so 
