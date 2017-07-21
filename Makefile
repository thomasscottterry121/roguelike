CPPFLAGS=-g -Wall -Iinc

SOURCES=$(wildcard src/*.cc)
OBJECTS=$(patsubst %.cc,%.o,$(SOURCES))

main: $(OBJECTS)
	g++ $(CPPFLAGS) -o main $^

$(OJBECTS): $(SOURCES)
	g++ $(CPPFLAGS) -o $@ -c $^

clean:
	rm src/*.o
	rm main

git: clean
	@git add src/*.cc >> git.log
	@git add inc/*.h >> git.log
	@git add README.md >> git.log
	@git add doc/* >> git.log
	@git add Makefile >> git.log
	@git commit || true
	@git push || true

