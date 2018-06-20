.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = memoryHierarchy.pdf masterBootRecord.pdf hddPartition.pdf \
	partitionTable.pdf

%.pdf : %.tex myfig.sty
	lualatex $*.tex
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *~

