all:
	(cd src/extract; make -j8)
	(cd src/lib/miditones-src; make)

clean:
	(cd src/extract; make clean)
	(cd src/lib/miditones-src; make clean)