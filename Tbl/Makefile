.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = threadTimeTbl.pdf threadTimeGrph.pdf schedulingObjective.pdf \
       segmentTableAttr.pdf

%.pdf : %.tex
	lualatex $*.tex
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *~

