.SUFFIXES:
.SUFFIXES: .tex .pdf

HNDS =  chap1_Hnd.pdf chap2_Hnd.pdf chap3_Hnd.pdf chap4_Hnd.pdf \
        chap5_Hnd.pdf chap6_Hnd.pdf chap7_Hnd.pdf chap8_Hnd.pdf \
        chap9_Hnd.pdf chapA_Hnd.pdf chapB_Hnd.pdf chapC_Hnd.pdf \
        chapD_Hnd.pdf chapE_Hnd.pdf chapF_Hnd.pdf chapG_Hnd.pdf \
        chapH_Hnd.pdf chapX_Hnd.pdf

SLDS =  chap1_Sld.pdf chap2_Sld.pdf chap3_Sld.pdf chap4_Sld.pdf \
	chap5_Sld.pdf chap6_Sld.pdf chap7_Sld.pdf chap8_Sld.pdf \
	chap9_Sld.pdf chapA_Sld.pdf chapB_Sld.pdf chapC_Sld.pdf \
	chapD_Sld.pdf chapE_Sld.pdf chapF_Sld.pdf chapG_Sld.pdf \
	chapH_Sld.pdf chapX_Sld.pdf

%_Hnd.pdf : %_Hnd.tex %_Sld.pdf
	lualatex $*_Hnd.tex

%_Sld.pdf : %_Sld.tex *.sty
	lualatex $*_Sld.tex

all : ${SLDS} ${HNDS} # 中間ファイル *_Sld.pdf を消さないように

clean :
	rm -f *.log *.aux *.dvi *.out *.toc *.vrb *.snm *.nav *~
