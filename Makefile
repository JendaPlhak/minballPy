CXX       = g++

PYTHON_CONFIG = python-config
LDFLAGS   = `$(PYTHON_CONFIG) --ldflags` -lCGAL -lgmp
LIBS      = `$(PYTHON_CONFIG) --libs`
INCLUDES  = -Iextern/pybind11/include/ -Iinclude `$(PYTHON_CONFIG) --includes`
WARNINGS  = -Wall -Wextra

MACHINE   = -march=native -mtune=native
CXXFLAGS  = -std=c++11 -x c++ $(INCLUDES) $(WARNINGS) $(MACHINE) -fPIC \
            -g3 -O2 -frounding-math

all: minball.so

setup:
	git submodule update --init --recursive

build_dir:
	mkdir -p build

build/minball.so: build_dir
	$(CXX) $(CXXFLAGS) src/*.cpp $(LDFLAGS) -shared -o build/minball.so

minball.so: build/minball.so
	cp build/minball.so .

clean:
	rm -rf build
