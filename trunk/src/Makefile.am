## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = gstpw

gstpw_SOURCES = \
	main.c \
	interface.c interface.h \
	callbacks.c callbacks.h \\
	support.c support.h dupa.h

gstpw_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

