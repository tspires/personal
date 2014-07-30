#/usr/bin/bash
lib=$1
g++ -fpic -c $lib.cpp
g++ -shared -o $lib.so $lib.o
export LD_LIBRARY_PATH="."

