
CC = gcc
CXX = g++.exe

CPPFLAGS = -Wall -g -DBUILD_DLL

LDFLAGS = -shared -Wl,--output-def=bin/Debug/libutil.def -Wl,--out-implib=bin/Debug/libutil.a -Wl,--dll
LOADLIBS = -lgdi32

objects = obj/Debug/colortable.o obj/Debug/main.o obj/Debug/outsrcstring.o obj/Debug/screen.o obj/Debug/systems.o
build = bin/Debug/util.dll

objectdir = obj/Debug
builddir = bin/Debug


all: $(objects) $(build)

$(objectdir):
	mkdir -p $(objectdir)

$(builddir):
	mkdir -p $(builddir)

$(objects): $(objectdir)/%.o: %.cpp | $(objectdir)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


$(build): obj/Debug/main.o | $(builddir)
	touch $(build)
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
