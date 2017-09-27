# use "gcc" to compile source files.
CC = g++
# the linker is also "gcc". It might be something else with other compilers.
LD = g++
# Compiler flags go here.
CFLAGS = -g -Wall -std=c++11
# Libraries
LIBS = -lcurl -l json -lboost_iostreams -lboost_system -lrt
# use this command to erase files.
RM = /bin/rm -f
# path to src files
SRC = src/
# list of generated object files.
OBJS = main.o WeatherOWM.o WeatherYahoo.o FileHandler.o Plotter.o WeatherGeneral.o ProgramHandler.o Helper.o MessagingHandler.o
PROG = prog

all: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(CFLAGS) $(OBJS) $(LIBS) -o $(PROG)

%.o: $(SRC)%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# rule for cleaning re-compilable files.
clean:
	$(RM) $(PROG) $(OBJS)
