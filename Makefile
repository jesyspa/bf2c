CXX = clang++ -Wall -Wextra -Winline -W -Wwrite-strings -pedantic -Iinclude/

bfinst.o : bfinst.cpp bfinst.hpp
	${CXX} -c -o bfinst.o bfinst.cpp
bfinstlist.o : bfinstlist.cpp bfinstlist.hpp bfinst.hpp
	${CXX} -c -o bfinstlist.o bfinstlist.cpp
bfreadfile.o : bfreadfile.cpp bfreadfile.hpp bfinstlist.hpp bfinst.hpp
	${CXX} -c -o bfreadfile.o bfreadfile.cpp
main.o : main.cpp bfreadfile.hpp bfinstlist.hpp bfinst.hpp
	${CXX} -c -o main.o main.cpp
bf2c : bfinst.o bfinstlist.o bfreadfile.o main.o
	${CXX} -o bf2c bfinst.o bfinstlist.o bfreadfile.o main.o

.PHONY: clean
clean :
	rm -f *.o bf2c
