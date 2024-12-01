all:
	g++ test.cpp -o test -std=c++20 -O2 -Wl,--stack=512000000
run: all
	.\test
report:
	xelatex report.tex