all: linkedlist

LinkedList:
	cl /c LinkedList.cpp test.cpp
	lib /OUT:LinkedList.lib LinkedList.obj
	link test.obj LinkedList.lib
Clean:
	del *.obj
	del *.exe