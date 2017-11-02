.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = threadTimeTbl.pdf threadTimeGrph.pdf

%.pdf : %.tex
	platex $*.tex
	dvipdfmx $*.dvi
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *~

