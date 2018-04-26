.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS =  chap1_Sld.pdf chap2_Sld.pdf chap3_Sld.pdf chap4_Sld.pdf \
	chap5_Sld.pdf chap6_Sld.pdf chap7_Sld.pdf chap8_Sld.pdf \
	chap9_Sld.pdf chapA_Sld.pdf chapB_Sld.pdf

%.pdf : %.tex *.sty
	lualatex $*.tex
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~

