.PHONY : echo clean
CC=gcc
CXX=g++

all : c.exe
test : c.exe
	test/test1.sh

c.exe : main.o libshared.so
	$(CXX) -o c.exe -L$(PWD)/ -Wall main.o libshared.so
	
main.o : main.cpp
	$(CXX) -c main.cpp
	
shared.o : shared.cpp shared.h
	$(CXX) -c shared.cpp -fpic -std=c++14
	
libshared.so : shared.o
	$(CXX) shared.o -shared -o libshared.so
	
clean :
	rm c.exe main.o libshared.so shared.o
	
