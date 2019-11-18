.SUFFIXES:
.SUFFIXES: .tex .pdf

%.pdf : %.tex
	lualatex $*.tex
	#open $*.pdf

SUBDIRS:=Sld

all : os.pdf Subdirs

os.pdf : mySty.sty os.tex chap?.tex bibliography.tex app?.tex

Subdirs :
	$(foreach dir, $(SUBDIRS), $(MAKE) --directory=$(dir); )
clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~
	$(foreach dir, $(SUBDIRS), $(MAKE) --directory=$(dir) clean; )
