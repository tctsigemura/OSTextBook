.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = presentation.pdf

%.pdf : *.tex
	platex $*.tex
	platex $*.tex
	dvipdfmx $*.dvi
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.snm *.nav *~

