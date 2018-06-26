.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = threadTimeTbl.pdf threadTimeGrph.pdf schedulingObjective.pdf \
       segmentTableAttr.pdf pageTableAttr.pdf beladyAnomalyM3.pdf \
       beladyAnomalyM4.pdf partitionTableEntry.pdf partitionTableType.pdf \
       filenameExtensions.pdf dirOperations.pdf fileOperations.pdf

%.pdf : %.tex
	lualatex $*.tex
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *~

