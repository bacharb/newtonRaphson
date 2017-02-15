filename=newton-raphson

all:
	latex ${filename}
	bibtex ${filename}||true
	latex ${filename}
	latex ${filename}

install:
	dvipdf ${filename}
		
clean:
	rm -f ${filename}.{ps,pdf,log,aux,out,dvi,bbl,blg}
