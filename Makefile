CXX = clang++ -Wall -Wextra -Winline -W -Wwrite-strings -pedantic -Iinclude/

bf2c : bfinst.o bfinstlist.o bfreadfile.o main.o
	${CXX} -o bf2c bfinst.o bfinstlist.o bfreadfile.o main.o
bfinst.o : bfinst.cpp include/bfinst.hpp
	${CXX} -c -o bfinst.o bfinst.cpp
bfinstlist.o : bfinstlist.cpp include/bfinstlist.hpp include/bfinst.hpp
	${CXX} -c -o bfinstlist.o bfinstlist.cpp
bfreadfile.o : bfreadfile.cpp include/bfreadfile.hpp include/bfinstlist.hpp include/bfinst.hpp
	${CXX} -c -o bfreadfile.o bfreadfile.cpp
main.o : main.cpp include/bfreadfile.hpp include/bfinstlist.hpp include/bfinst.hpp
	${CXX} -c -o main.o main.cpp

.PHONY: clean
clean :
	rm -f *.o bf2c
