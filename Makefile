
all: split1 split2 split6 split7 split8 splitc1 splitc2 splitc3

%: %.cpp
	g++ -Wall -O3 -o $@ $<

.PHONY: clean

clean:
	@rm -f split1 split2 split6 split7 split8 splitc1 splitc2 splitc3
