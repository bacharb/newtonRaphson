if HAVE_PDFLATEX
	doc_DATA = newton-raphson.pdf

	${doc_DATA}:	newton-raphson.tex references.bib
	$(PDFLATEX) newton-raphson.tex	
	
	CLEANFILES = *.aux *.log *.pdf

endif
