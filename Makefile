#Make file for my first project which is about using chatGPT for project ideas
#I used AI very sparingly for this project, mainly just for some syntax stuff
#because I'm getting very rusty.

#compiler
CXX = g++

#variables
flags = -Wall -g

#target executable
target = task

#for deletion of the target
targetDel = $(target)

#source files
##########
###Add files here
##########
srcs = main.cpp task.cpp

#object files
objs = $(srcs:.cpp=.o)

#deafult rule to build and run the executable 
all: $(target)
	
#Rule to link object files into the target executable
$(target) : $(objs)
	$(CXX) $(flags) -o $(target) $(objs)

#rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(flags) -c $< -o $@

#RUle to run the executable
run: $(target)
	./$(target)

#clean rule to remove generated files
clean:
	rm -f $(target) $(objs)
