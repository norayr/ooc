top_builddir=.
subdirs=tests
OOCN=Oocn
#OOCN=/home/ooc-devel/ooc/oocn --config /usr/lib/Oo2c/oo2crc


test_programs=TestScanner TestParser TestSymTab TestConfigSections TestConfigCmdLine TestConfigEnv TestConfigSimple TestInterfaceGen TestOpTree TestTexinfo TestURI AllModules

all:


.PHONY: mkdir clean distclean test

### `mkdir'
###      Build all the directories we're going to install oo2c in.   Since
###      we may be creating several layers of directories, we use mkinstalldirs
###      instead of mkdir.  Not all systems' mkdir programs have the `-p' flag.
mkdir: FRC
	(umask 022; for i in sym obj doc doc/txt doc/html doc/xref; do \
	  ./mkinstalldirs ${top_builddir}/$$i; \
	done)

### `clean'
###      Delete all files from the current directory that are normally
###      created by building the program.  Don't delete the files that
###      record the configuration.  Also preserve files that could be made
###      by building, but normally aren't because the distribution comes
###      with them.
clean: 
	for i in sym obj doc; do rm -Rf ${top_builddir}/$$i/*; done
	rm -f src/XML
	for i in ${test_programs}; do rm -f $$i; done
	for i in ${subdirs}; do cd $$i && ${MAKE} clean; done

### `distclean'
###      Delete all files from the current directory that are created by
###      configuring or building the program.  If you have unpacked the
###      source and built the program without creating any other files,
###      `make distclean' should leave only the files that were in the
###      distribution.
distclean: clean
	rmdir ${top_builddir}/sym ${top_builddir}/obj ${top_builddir}/doc

FRC:

### `doc'
###      Create documentation from module sources.
doc:	mkdir
	${OOCN} --def-txt -Cv -o ${top_builddir}/doc/txt AllModules
	${OOCN} --def-html -Cv -o ${top_builddir}/doc/html AllModules
	${OOCN} --xref -Cv -o ${top_builddir}/doc/xref AllModules

### `test'
###      Perform all available regression tests.
test:
	cd tests && ${MAKE} test
