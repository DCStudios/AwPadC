CC 		:= g++ 
PROG 	:= Awpad.exe
SRCS 	:= $(wildcard src/*.cpp)
OBJS 	:= $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))
CPARAMS := -Wall -pedantic -ggdb -O2 -c -o
BPARAMS := -Wall -pedantic -ggdb -O2 -o 

all: $(PROG)

obj/%.o: src/%.cpp
	$(CC) $(CPARAMS) $@ $<
	
$(PROG): $(OBJS)
	$(CC) $(BPARAMS) $@ $(OBJS)



