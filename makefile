main: main.o adtlist.o fsarraylist.o varraylist.o object.o Person.o employee.o tree.o treeNode.o
	g++  main.o fsarraylist.o varraylist.o object.o Person.o employee.o adtlist.o tree.o treeNode.o -o proyecto
	
main.o:	main.cpp adtlist.o fsarraylist.h
	g++ -c main.cpp

fsarraylist.o:	fsarraylist.cpp fsarraylist.h
	g++ -c fsarraylist.cpp

varraylist.o:	varraylist.cpp fsarraylist.h varraylist.h
	g++ -c varraylist.cpp

object.o:	object.cpp fsarraylist.h object.h
	g++ -c object.cpp

adtlist.o:	adtlist.cpp adtlist.h fsarraylist.h
	g++ -c adtlist.cpp

tree.o:	tree.cpp tree.h varraylist.h treeNode.h
	g++ -c tree.cpp

treeNode.o:	treeNode.cpp treeNode.h varraylist.h object.h
	g++ -c treeNode.cpp

Person.o:	Person.cpp Person.h object.h
	g++ -c Person.cpp

employee.o:	employee.cpp employee.h object.h
	g++ -c employee.cpp

clean:
	rm -f *.o main