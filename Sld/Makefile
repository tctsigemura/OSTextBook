CHAPS =  chap1 chap2 chap3 chap4 chap5 chap6 chap7 chap8 \
	chap9 chapA chapB chapC chapD chapE chapF chapG chapH chapX

all : all_pdf all_Hnd.pdf

all_pdf :
	$(foreach chap, ${CHAPS}, \
                     latexmk -interaction=nonstopmode -lualatex $(chap)_Sld; \
                     latexmk -interaction=nonstopmode -lualatex $(chap)_Hnd; )

all_Hnd.pdf : chap?_Hnd.pdf
	gs -q -dNOPAUSE -dBATCH -sDEVICE=pdfwrite -sOutputFile=all_Hnd.pdf \
	chap?_Hnd.pdf

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav */*~ *~ \
              *.fls *.fdb_latexmk
