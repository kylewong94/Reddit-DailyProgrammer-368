proj=x_o_program

obj_path=../obj
bin_path=../bin

cxx=g++
cflags= -Wall -g

$(proj): main.o Grid.o
	$(cxx) $(cflags) -o $(bin_path)/$(proj) $(obj_path)/main.o $(obj_path)/Grid.o

main.o: main.cpp Grid.o
	$(cxx) $(cflags) -c main.cpp -o $(obj_path)/main.o

Grid.o: Grid.h
	$(cxx) $(cflags) -c Grid.cpp -o $(obj_path)/Grid.o

clean:
	rm -f $(bin_path)/*
	rm -f $(obj_path)/*.o
