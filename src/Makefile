# Makefile -*- Makefile -*-


include ../Makefile.defaults
include ../Makefile.platform
include ../Makefile.$(PLATFORM)

all: libginger.a gin1.scm

clean:
	@echo "Cleaning up.."
	@rm libginger.a *.o *~ gin1.scm

install:
	@echo "Installing gin1.."
	@test -d $(INCLUDEDIR) || mkdir -p $(INCLUDEDIR)
	@test -d $(GINGERDIR) || mkdir -p $(GINGERDIR)
	@test -d $(BINDIR)/gin1 || mkdir -p $(BINDIR)
	@test -d $(LIBDIR) || mkdir -p $(LIBDIR)
	@cp ginger.h $(INCLUDEDIR)
	@cp *.gin $(GINGERDIR)
	@cp gin1.scm $(BINDIR)
	@mv $(BINDIR)/gin1.scm $(BINDIR)/gin1
	@cp support.scm $(BINDIR)
	@cp libginger.a $(LIBDIR)

uninstall:
	@echo "Uninstalling gin1.."
	@rm $(INCLUDEDIR)/ginger.h
	@rm -rf $(GINGERDIR)
	@rm $(BINDIR)/gin1
	@rm $(BINDIR)/support.scm
	@rm $(LIBDIR)/libginger.a

gin1.scm: gin1.gin
	@echo "Compiling gin1.."
	@./gin0.scm gin1.gin
	@chmod a+x gin1.scm

SRCS=utils.c dict.c gc.c env.c
OBJS=utils.o dict.o gc.o env.o
CFLAGS= $(PLATFORM_CFLAGS) -I..
LDFLAGS= $(PLATFORM_LDFLAGS)

libginger.a: $(OBJS)
	$(LIBRARIAN) $(LIBRARIAN_FLAGS) $@ $(OBJS)

$(OBJS):
	$(CPP_COMPILER) $(CFLAGS) -c $*.c
