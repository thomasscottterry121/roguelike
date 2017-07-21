OBJDIR=obj
BINDIR=bin
SRCDIR=src
INCDIR=inc
DOCDIR=doc

CPPFLAGS=-g -Wall -I$(INCDIR) -lncurses

SOURCES=$(wildcard $(SRCDIR)/*.cc)
OBJECTS=$(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SOURCES))


MAIN=$(BINDIR)/spacehack
GITLOG=1.log

obj/%.o : src/%.cc $(OBJDIR)
	@g++ $(CPPFLAGS) -c $< -o $@
	@echo "CXX $@"

$(MAIN): $(OBJECTS) $(BINDIR)
	@g++ $(CPPFLAGS) -o $(MAIN) $(OBJECTS) -lncurses
	@echo "LINK $@"


$(BINDIR):
	@mkdir $(BINDIR)
	@echo "MKDIR $(BINDIR)"
$(OBJDIR):
	@mkdir $(OBJDIR)
	@echo "MKDIR $(BINDIR)"

clean:
	@rm $(OBJECTS) -f
	@echo "RM $(OBJECTS)"
	@rm $(MAIN) -f
	@echo "RM $(MAIN)"
	@rm $(GITLOG) -f
	@echo "RM $(GITLOG)"
	@rm $(BINDIR) -rf
	@echo "RM $(BINDIR)"
	@rm $(OBJDIR) -rf
	@echo "RM $(OBJDIR)"

git: clean
	@git add $(SRCDIR)/*.cc >> $(GITLOG)
	@git add $(INCDIR)/*.h >> $(GITLOG)
	@git add README.md >> $(GITLOG)
	@git add doc/* >> $(GITLOG)
	@git add Makefile >> $(GITLOG)
	@git commit || true
	@git push || true

run: clean $(MAIN)
	@$(MAIN)

install: $(MAIN)
	@install $(MAIN) /usr/$(MAIN)
	@echo "INSTALL $(MAIN)"

lc:
	@echo "LINES IN PROJECT"
	@wc -l $(SRCDIR)/* $(DOCDIR)/* $(INCDIR)/* Makefile

list:
	@ls * -R
