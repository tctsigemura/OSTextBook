.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = os.pdf chap1_Sld.pdf chap2_Sld.pdf chap3_Sld.pdf chap4_Sld.pdf \
	chap5_Sld.pdf chap6_Sld.pdf

%.pdf : %.tex
	platex $*.tex
	platex $*.tex
	dvipdfmx $*.dvi
	open $*.pdf

all : ${PDFS}

os.pdf : os.tex chap?.tex mySty.sty

chap1_Sld.pdf : chap1_Sld.tex mySld.sty

chap2_Sld.pdf : chap2_Sld.tex mySld.sty

chap3_Sld.pdf : chap3_Sld.tex mySld.sty

chap4_Sld.pdf : chap4_Sld.tex mySld.sty

chap5_Sld.pdf : chap5_Sld.tex mySld.sty


clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~

