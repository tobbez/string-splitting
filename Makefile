CXXFLAGS = -Wall -O3

all: split1 split2 split6 split7 split8 split9 splitc1 splitc2 splitc3

split7: split7.cpp deps/strtk
	$(CXX) $(LDFLAGS) -Ideps/strtk/ $(CXXFLAGS) split7.cpp -o split7


.PHONY: clean update-deps

clean:
	@rm -f split1 split2 split6 split7 split8 split9 splitc1 splitc2 splitc3

update-deps: deps
	git --git-dir=deps/strtk/.git/ --work-tree=deps/strtk/ fetch origin
	git --git-dir=deps/strtk/.git/ --work-tree=deps/strtk/ reset --hard origin/master

deps:
	mkdir deps

deps/strtk: deps
	git clone --depth 1 https://github.com/ArashPartow/strtk.git deps/strtk
