.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = fcfs1.pdf fcfs2.pdf sjf1.pdf sjf2.pdf srtf1.pdf rr1.pdf rr2.pdf

%.pdf : %.tex *.sty
	lualatex $*.tex
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *~

