CPPFLAGS=-g -Wall -Iinc

SOURCES=$(wildcard src/*.cc)
OBJECTS=$(patsubst src/%.cc,obj/%.o,$(SOURCES))
MAIN=spacehack
GITLOG=1.log
obj/%.o : src/%.cc
	@g++ $(CPPFLAGS) -c $< -o $@
	@echo "CXX $@"

$(OJBECTS): obj/%.o : src/%.cc
	@g++ $(CPPFLAGS) -c $< -o $@
	@echo "CXX $@"


$(MAIN): $(OBJECTS)
	@g++ $(CPPFLAGS) -o main $(OBJECTS)
	@echo "LINK $@"

clean:
	@rm $(OBJECTS) -f
	@echo "RM $(OBJECTS)"
	@rm $(MAIN) -f
	@echo "RM $(MAIN)"
	@rm $(GITLOG) -f
	@echo "RM $(GITLOG)"

git: clean
	@git add src/*.cc >> $(GITLOG)
	@git add inc/*.h >> $(GITLOG)
	@git add README.md >> $(GITLOG)
	@git add doc/* >> $(GITLOG)
	@git add Makefile >> $(GITLOG)
	@git commit || true
	@git push || true

