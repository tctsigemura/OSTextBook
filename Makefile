.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = os.pdf

%.pdf : *.tex mySty.sty
	platex $*.tex
	platex $*.tex
	dvipdfmx $*.dvi
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *~

