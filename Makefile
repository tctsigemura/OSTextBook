.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = os.pdf chap3_Sld.pdf

%.pdf : %.tex
	platex $*.tex
	platex $*.tex
	dvipdfmx $*.dvi
	open $*.pdf

all : ${PDFS}

os.pdf : os.tex chap?.tex mySty.sty

chap3_Sld.pdf : chap3_Sld.tex


clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~

