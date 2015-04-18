CXXFLAGS = -Wall -O3

all: split1 split2 split6 split7 split8 split9 splitc1 splitc2 splitc3

.PHONY: clean

clean:
	@rm -f split1 split2 split6 split7 split8 split9 splitc1 splitc2 splitc3
