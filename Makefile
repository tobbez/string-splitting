CXXFLAGS = -Wall -O3

all: split1 split2 split6 split7 split8 split9 splitc1 splitc2 splitc3 split_subparser

split7: split7.cpp | deps/strtk
	$(CXX) $(LDFLAGS) -Ideps/strtk/ $(CXXFLAGS) split7.cpp -o split7

split_subparser: split_subparser.cpp | deps/json_parser
	$(CXX) $(LDFLAGS) -Ideps/json_parser/include/ $(CXXFLAGS) split_subparser.cpp -o split_subparser


.PHONY: clean update-deps

clean:
	@rm -f split1 split2 split6 split7 split8 split9 splitc1 splitc2 splitc3 split_subparser

update-deps: deps
	git --git-dir=deps/strtk/.git/ --work-tree=deps/strtk/ fetch origin
	git --git-dir=deps/strtk/.git/ --work-tree=deps/strtk/ reset --hard origin/master
	git --git-dir=deps/json_parser/.git/ --work-tree=deps/json_parser/ fetch origin
	git --git-dir=deps/json_parser/.git/ --work-tree=deps/json_parser/ reset --hard origin/master

deps:
	mkdir deps

deps/strtk: | deps
	git clone --depth 1 https://github.com/ArashPartow/strtk.git deps/strtk

deps/json_parser: deps
	git clone --depth 1 https://github.com/VerizonDigital/json_parser deps/json_parser
