
.SUFFIXES: .C .o
CXX = g++
CXXFLAGS = -g
EXEC = main
OBJS = obj/alea.o obj/chromosome.o obj/gene.o obj/main.o

${EXEC}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${EXEC} ${OBJS}

.C.o: # Abstract rule
	${CXX} ${CXXFLAGS} -c $<
# Still need to list the dependencies for object files
# Compiling the source files
obj/alea.o: src/alea.cpp include/alea.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

obj/chromosome.o: src/chromosome.cpp include/chromosome.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

obj/gene.o: src/gene.cpp include/gene.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

obj/main.o: main.cpp include/alea.hpp include/chromosome.hpp include/gene.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	rm -f ${EXEC} ${OBJS}