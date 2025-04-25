
CC = gcc
CXX = gcc

CPPFLAGS = -Wall -g -DBUILD_DLL

LDFLAGS = -shared -Wl,--output-def=bin/Debug/libutil.def -Wl,--out-implib=bin/Debug/libutil.a -Wl,--dll
LOADLIBS = -lgdi32

objects = obj/Debug/colortable.o obj/Debug/main.o obj/Debug/outsrcstring.o obj/Debug/screen.o obj/Debug/systems.o
objectdir = obj/Debug
builddir = bin/Debug/util.dll


all: $(objects) $(builddir)

$(objectdir):
	mkdir -p $(objectdir)

$(builddir):
	mkdir -p $(builddir)

$(objects): $(objectdir)/%.o: %.cpp | $(objectdir)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


$(builddir): $(objects) | $(builddir)
	touch $(builddir)
	$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@



.PHONY: clean
clean:
	rm -f $(objects)

.PHONY: check
check:
	echo check

.PHONY: distcheck
distcheck:
	echo distcheck
