prog:=pong
valgrind_log:=valgrind-out.log
LD_FLAGS:=-lSDL2 -lSDL2_image
CC_FLAGS:=source/*.cxx -I includes/ -w

run: build
	./$(prog)
check_memory: build
	chmod +x check_memory.sh 
	./check_memory.sh $(prog) $(valgrind_log)
build:
	g++ main.cxx $(CC_FLAGS) $(LD_FLAGS) -o $(prog)

