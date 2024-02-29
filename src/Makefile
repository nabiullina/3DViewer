CC = g++
CFLAGS = -std=c++17 -Wall -Wextra
TEST_FLAGS = -lgtest
TESTS = test_viewer
REPORT = gcov_report
GCOV_REPORT = gcov/$(REPORT)
GCOV_INFO = $(GCOV_REPORT).info
GCOV_FLAGS  = --coverage -lcheck
3DVIEWER = 3DViewer_v2.app


.PHONY: all install dvi dist test gcov_report uninstall clean

all: install tests gcov_report

s21_viewer.o:
	$(CC) $(CFLAGS) -c ./tests/$(TESTS).cc ./model/transformer/transformer.cc ./model/parser/simple_parser.cc -g $(TEST_FLAGS)

s21_viewer.a: s21_viewer.o
	ar rcs s21_viewer.a transformer.o simple_parser.o

tests: s21_viewer.a
	$(CC) $(CFLAGS) test_viewer.o transformer.o simple_parser.o -o $(TESTS) s21_viewer.a $(TEST_FLAGS)
	./$(TESTS)

gcov_report: tests
	$(CC) $(CFLAGS) --coverage ./tests/$(TESTS).cc ./model/transformer/transformer.cc ./model/parser/simple_parser.cc -o gcov_report s21_viewer.a $(TEST_FLAGS)
	chmod +x *
	./gcov_report
	lcov -t "gcov_report" -o gcov_report.info --no-external --ignore-errors mismatch -c -d .
	genhtml -o report/ gcov_report.info
	open ./report/index.html

install: uninstall clean
	mkdir build
	cd view && qmake && make && make clean && rm Makefile && cd ../ && mv view/3DViewer_v2.app build/

open:
	open build/3DViewer_v2.app/Contents/MacOS/3DViewer_v2

check_leaks:
	CK_FORK=no leaks --atExit -- ./build/3DViewer_v2.app/Contents/MacOS/3DViewer_v2 > logfile.log

dvi:
	open dvi/index.html

dist: install
	rm -rf ../Archive_3DViewer/
	mkdir ../Archive_3DViewer/
	cp -a **/ ./* Makefile ./build/$(3DVIEWER) ../Archive_3DViewer
	cd ../ && tar -cvzf Archive_3DViewer.tar.gz Archive_3DViewer

valgrind: tests
	CK_FORK=no valgrind --track-origins=yes --leak-check=full --leak-resolution=med --show-leak-kinds=all -s ./$(TESTS)

uninstall:
	rm -rf ./build*

clean:
	rm -rf *.{a,o,dSYM,out}
	rm -rf gcov_report
	rm -rf report
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf Tests/test
	rm -rf ../*.gz
	rm -rf ../Archive_3DViewer
	rm -rf gcov
	rm -rf test_viewer
	rm -rf RESULT.txt
	rm -rf ../src/3DViewer/*.o
	rm -rf build
	rm -rf *.log
	rm -rf ./view/*.o
	rm -rf ./view/*.pro.user

style:
	@echo "======= CHECK GOOGLE CODE STYLE ======="
	@sleep 1
	find . \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0 clang-format -n -style=Google