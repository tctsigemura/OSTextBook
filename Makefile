.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = os.pdf

%.pdf : %.tex *.sty
	lualatex $*.tex
	open $*.pdf

all : ${PDFS}

os.pdf : os.tex chap?.tex bibliography.tex app?.tex

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~

