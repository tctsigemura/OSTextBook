.SUFFIXES:
.SUFFIXES: .tex .pdf

PDFS = memoryHierarchy.pdf masterBootRecord.pdf hddPartition.pdf \
       partitionTable.pdf fatBPB.pdf fatVolume.pdf fatDirEntry.pdf \
       fatConcept.pdf fatCls.pdf fatDir.pdf fatFat.pdf ufsVolume.pdf \
       ufsInode.pdf ufsDirEntry.pdf ufsDataBlock.pdf ufsInodeList.pdf \
       zfsDevice.pdf zfsVolumeLabel.pdf

%.pdf : %.tex myfig.sty
	lualatex $*.tex
	open $*.pdf

all : ${PDFS}

clean :
	rm -f *.log *.aux *.dvi *~

