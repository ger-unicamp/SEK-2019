all: main
main: ev3dev.o
	arm-linux-gnueabi-g++ -o sensor sensors.cpp ev3dev.o -std=c++11 -static -Wall 
ev3dev.o: ev3dev.cpp
	arm-linux-gnueabi-g++ -c ev3dev.cpp -std=c++11 -static -Wall
