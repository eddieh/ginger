# Makefile -*- Makefile -*-

all:
	@echo "Descending into src directory.."
	@cd src; $(MAKE) all
clean:
	rm -rf *~
	@echo "Descending into src directory.."
	@cd src; $(MAKE) clean
distclean:
	@echo "Descending into src directory.."
	@cd src; $(MAKE) distclean
install:
	@echo "Descending into src directory.."
	@cd src; $(MAKE) install
uninstall:
	@echo "Descending into src directory.."
	@cd src; $(MAKE) uninstall

