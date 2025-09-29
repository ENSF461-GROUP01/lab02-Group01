COMPILER=gcc
PLATFORM=Linux

.PHONY: all clean test check_linux

all: check_linux gen_numbers.out select_arg.out gen_in_range.out

test: gen_numbers.out select_arg.out gen_in_range.out
	@./gen_numbers.out 3 | grep -q "" || echo "gen_numbers.out errored"
	@./select_arg.out 1 2 3 | grep -q "" || echo "select_arg.out errored"
	@./gen_in_range.out 0 5 | grep -q "" || echo "gen_in_range.out errored"

check_linux:
	@uname -s | grep -q $(PLATFORM) || (echo "Sorry, I Prefer $(PLATFORM)" && exit 1)

%.out: %.c utils.*
	$(COMPILER) -o $@ $^

clean: 
	rm -f *.out

