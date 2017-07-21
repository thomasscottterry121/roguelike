CPPFLAGS=-g -Wall -Iinc

SOURCES=$(wildcard src/*.cc)
OBJECTS=$(patsubst src/%.cc,obj/%.o,$(SOURCES))


obj/%.o : src/%.cc
	@g++ $(CPPFLAGS) -c $< -o $@
	@echo "CXX $@"

$(OJBECTS): obj/%.o : src/%.cc
	@g++ $(CPPFLAGS) -c $< -o $@
	@echo "CXX $@"


main: $(OBJECTS)
	@g++ $(CPPFLAGS) -o main $(OBJECTS)
	@echo "LINK $@"

clean:
	@rm $(OBJECTS) -f
	@echo "RM $(OBJECTS)"
	@rm main -f
	@echo "RM main"
	@rm git.log -f
	@echo "RM git.log"

git: clean
	@git add src/*.cc >> git.log
	@git add inc/*.h >> git.log
	@git add README.md >> git.log
	@git add doc/* >> git.log
	@git add Makefile >> git.log
	@git commit || true
	@git push || true

