.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = threadTimeTbl.pdf threadTimeGrph.pdf schedulingObjective.pdf \
	fcfs1.pdf fcfs2.pdf sjf1.pdf sjf2.pdf srtf1.pdf rr1.pdf rr2.pdf

%.pdf : %.tex *.sty
	platex $*.tex
	dvipdfmx $*.dvi
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *~

