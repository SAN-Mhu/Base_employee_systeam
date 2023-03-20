objects = boss.o employee.o manager.o ProgramEnter.o SysManager.o
CPP = g++
CPPFLAGS = -std=c++11

main:$(objects)
	$(CPP) $(CPPFLAGS) $(objects) -o main

ProgramEnter.0:SysManager.h 
SysManager.0:SysManager.h worker.h boss.h employee.h manager.h
boss.o: boss.h
employee.o: employee.h
manager.o: manager.h

#clean .0 file
.PHONY : clean
clean:
	-rm $(objects)

