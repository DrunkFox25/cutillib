
CC = gcc
CXX = gcc

CPPFLAGS = -Wall -g -DBUILD_DLL

LDFLAGS = -shared -Wl,--output-def=bin\Debug\libutil.def -Wl,--out-implib=bin\Debug\libutil.a -Wl,--dll
LOADLIBS = -lgdi32

objects = colortable.o main.o outsrcstring.o screen.osystems.o


all: $(objects)

$(objects): %.o: %.cpp #Makefile:14: *** missing separator.
	echo "prereq" $^ "target" $@
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^ -o $@


bin\Debug\util.dll: $(objects)
	$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@




clean:
	rm -f objects
