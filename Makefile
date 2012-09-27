
all: split1 split2 split6 split7 splitc1 splitc2 splitc3

%: %.cpp
	g++ -Wall -O3 -std=c++0x -o $@ $<

.PHONY: clean

clean:
	@rm -f split1 split2 split6 split7 splitc1 splitc2 splitc3
