CC = gcc
STDFLAGS = -Wall -Wextra -Werror -std=c11
UNAME = $(shell uname -s)
FLAGS_MAIN = "noflags"
FLAGS_TEST = "noflags"

ifeq ($(UNAME),Darwin)
	FLAGS_MAIN = -lm -lpthread
	FLAGS_TEST = -lcheck -lm -lpthread -fprofile-arcs $(shell pkg-config --cflags --libs check)
endif
ifeq ($(UNAME),Linux)
	FLAGS_MAIN = -lsubunit -lrt -lm -lpthread
	FLAGS_TEST = -lcheck -lsubunit -lrt -lm -lpthread -fprofile-arcs $(shell pkg-config --cflags --libs check)
endif


SOURCE_C = ./core/parser.c ./core/other.c ./core/main.h
SOURCE_TESTS_C = ./core/parserTest.o ./core/otherTest.o
SOURCE_UI = ./gui/appwindow.cpp ./gui/appwindow.h ./gui/appwindow.ui ./gui/openglwidget.cpp ./gui/openglwidget.h
SOURCE_TEST = ./core/tests.c

OUTNAME_TESTS = test

PROJECTNAME = 3D_Viewer

BUILDDIR_RELEASE = build/$(PROJECTNAME)-build-release

OUTNAME_MAIN = $(PROJECTNAME) 

OUTNAME_TAR = $(PROJECTNAME)-build-release-v1.tar.gz

all: cleanall test gcov_report install dist dvi
.PHONY : all

build: clean gui/main.cpp $(SOURCE_C) $(SOURCE_UI)
	if [ ! -d "$(BUILDDIR_RELEASE)" ] && [ ! -f "build/$(OUTNAME_MAIN)" ]; then cd gui/ && cmake CMakeLists.txt && make; fi
.PHONY : build

install: build
	if ! [ -d "$(BUILDDIR_RELEASE)" ]; then mkdir $(BUILDDIR_RELEASE); fi
	mv gui/3D_Viewer.app $(BUILDDIR_RELEASE)/$(OUTNAME_MAIN)
.PHONY : install

dist: $(BUILDDIR_RELEASE)/$(OUTNAME_MAIN)
	tar -zcvf build/$(OUTNAME_TAR) $(BUILDDIR_RELEASE)
.PHONY : dist

dvi:
	cd doxygen && doxygen Doxyfile
	open doxygen/html/index.html
.PHONY : dvi

test: $(SOURCE_TEST) $(SOURCES_C)
	$(CC) -c --coverage ./core/parser.c   -o ./core/parserTest.o
	$(CC) -c --coverage ./core/other.c 		-o ./core/otherTest.o
	$(CC) $(SOURCE_TEST) $(SOURCE_TESTS_C) $(FLAGS_TEST) -o ./core/$(OUTNAME_TESTS)
	./core/$(OUTNAME_TESTS)
.PHONY : test

gcov_report: core/$(OUTNAME_TESTS)
	gcov -b -l -p -c ./core/*.gcno
	gcovr -g -k -r . --html --html-details -o ./core/coverage_report.html
	mv *.gcov ./core
	open ./core/coverage_report.html
.PHONY : gcov_report

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i ./core/*.c ./gui/*.cpp
	clang-format -i ./core/*.h ./gui/*.h
	clang-format -n ./core/*.c ./gui/*.cpp
	clang-format -n ./core/*.h ./gui/*.h
.PHONY : style

clean: cleanall
	@rm -rf *.out	
	@rm -rf test main
	@rm -rf core/test
	@rm -rf core/*.gcda
	@rm -rf *.gcda
	@rm -rf core/*.gcno
	@rm -rf *.gcov
	@rm -rf core/*.gcov
	@rm -rf core/*.o
	@rm -rf *.html
	@rm -rf core/*.html
	@rm -rf *.css
	@rm -rf core/*.css
	@rm -rf callgrind.*
	@rm -rf massif.*
	@rm -rf test.dSYM
	@rm -rf a.out.dSYM
	@rm -rf doxygen/html
	@rm -rf gui/.qt
	@rm -rf gui/3D_Viewer_autogen
	@rm -rf gui/CMakeFiles
	@rm -rf gui/cmake_install.cmake
	@rm -rf gui/CMakeCache.txt
	@rm -rf gui/Makefile
	@rm -rf gui/CMakeLists.txt.user
	@rm -rf build-gui-Desktop_arm_darwin_generic_mach_o_64bit-Debug
	@rm -rf .clang-format

.PHONY : clean

cleanall: uninstall dist_clean clean
.PHONY : cleanall

uninstall:
	rm -rf $(BUILDDIR_RELEASE)
	rm -rf build/$(OUTNAME_TAR)
.PHONY : uninstall

dist_clean:
	@rm -rf build/$(OUTNAME_TAR)
.PHONY : dist_clean

valgrind: test
	valgrind --leak-check=full ./test
	# valgrind --tool=callgrind ./test
	# valgrind --tool=massif ./test
.PHONY : valgrind


leaks:
	leaks -atExit -- core/$(OUTNAME_TESTS)
	@mv tests.gcda ./core
.PHONY : leaks

cc:
	$(CC) $(STDFLAGS) core/main.c core/parser.c core/other.c && ./a.out