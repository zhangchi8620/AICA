#!/bin/bash
rm *.pgm
rm *.jpg
rm *.csv
mkdir exp3
############ Exp3

	./aica 1 -0.1 1 2 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/1_2_0
	mv *.pgm *.jpg output.csv display.html ./exp3/1_2_0/


############ exp3
	./aica 1 -0.1 1 5 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/1_5_0
	mv *.pgm *.jpg output.csv display.html ./exp3/1_5_0/


########### exp3

	./aica 1 -0.1 1 5 -2 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/1_5_-2
	mv *.pgm *.jpg output.csv display.html ./exp3/1_5_-2/


########### exp3

	./aica 1 -0.1 1 5 -4 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/1_5_-4
	mv *.pgm *.jpg output.csv display.html ./exp3/1_5_-4/


########### exp3

	./aica 1 -0.1 1 9 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/1_9_0
	mv *.pgm *.jpg output.csv display.html ./exp3/1_9_0/

########### exp3

	./aica 1 -0.1 1 9 -3 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/1_9_-3
	mv *.pgm *.jpg output.csv display.html ./exp3/1_9_-3/

########### exp3

	./aica 1 -0.1 1 9 -6 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/1_9_-6
	mv *.pgm *.jpg output.csv display.html ./exp3/1_9_-6/

########### exp3

	./aica 1 -0.1 1 14 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/1_14_0
	mv *.pgm *.jpg output.csv display.html ./exp3/1_14_0/

########### exp3

	./aica 1 -0.1 3 5 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/3_5_0
	mv *.pgm *.jpg output.csv display.html ./exp3/3_5_0/

########### exp3

	./aica 1 -0.1 3 5 -1 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/3_5_-1
	mv *.pgm *.jpg output.csv display.html ./exp3/3_5_-1/


########### exp3

	./aica 1 -0.1 3 9 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/3_9_0
	mv *.pgm *.jpg output.csv display.html ./exp3/3_9_0/

########### exp3

	./aica 1 -0.1 3 9 -3 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/3_9_-3
	mv *.pgm *.jpg output.csv display.html ./exp3/3_9_-3/

########### exp3

	./aica 1 -0.1 3 9 -6 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/3_9_-6
	mv *.pgm *.jpg output.csv display.html ./exp3/3_9_-6/

########### exp3

	./aica 1 -0.1 3 14 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/3_14_0
	mv *.pgm *.jpg output.csv display.html ./exp3/3_14_0/

########### exp3

	./aica 1 -0.1 7 9 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/7_9_0
	mv *.pgm *.jpg output.csv display.html ./exp3/7_9_0/

########### exp3

	./aica 1 -0.1 7 14 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/7_14_0
	mv *.pgm *.jpg output.csv display.html ./exp3/7_14_0/

########### exp3

	./aica 1 -0.1 12 14 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp3/12_14_0
	mv *.pgm *.jpg output.csv display.html ./exp3/12_14_0/
