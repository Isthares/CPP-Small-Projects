all: output

main.o: main.cpp file.h
	g++ -c main.cpp

menu.o: menu.cpp menu.h student.h
	g++ -c menu.cpp

file.o: file.cpp file.h menu.h 
	g++ -c file.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

output : main.o menu.o file.o student.o
	g++ main.o menu.o file.o student.o -o output
