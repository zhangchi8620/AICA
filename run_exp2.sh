#!/bin/bash
rm *.pgm
rm *.jpg
rm *.csv
mkdir exp2
############ Exp2

	./aica 0 -0.1 1 2 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/1_2_0
	mv *.pgm *.jpg output.csv display.html ./exp2/1_2_0/


############ Exp2

	./aica 0 -0.1 1 4 2 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/1_4_-2
	mv *.pgm *.jpg output.csv display.html ./exp2/1_4_-2/


########### Exp2

	./aica 0 -0.1 1 4 -1 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/1_4_-1
	mv *.pgm *.jpg output.csv display.html ./exp2/1_4_-1/


########### Exp2

	./aica 0 -0.1 1 4 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
    mkdir ./exp2/1_4_0	
	mv *.pgm *.jpg output.csv display.html ./exp2/1_4_0/

########### Exp2

	./aica 0 -0.1 1 6 -5 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/1_6_-5
	mv *.pgm *.jpg output.csv display.html ./exp2/1_6_-5/

########### Exp2

	./aica 0 -0.1 1 6 -3 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/1_6_-3
	mv *.pgm *.jpg output.csv display.html ./exp2/1_6_-3/

########### Exp2

	./aica 0 -0.1 1 6 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/1_6_0
	mv *.pgm *.jpg output.csv display.html ./exp2/1_6_0/

########### Exp2

	./aica 0 -0.1 1 9 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/1_9_0	
	mv *.pgm *.jpg output.csv display.html ./exp2/1_9_0/

########### Exp2

	./aica 0 -0.1 1 13 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/1_13_0
	mv *.pgm *.jpg output.csv display.html ./exp2/1_13_0/

########### Exp2

	./aica 0 -0.1 4 5 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/4_5_0
	mv *.pgm *.jpg output.csv display.html ./exp2/4_5_0/


########### Exp2

	./aica 0 -0.1 4 7 -5 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/4_7_-5
	mv *.pgm *.jpg output.csv display.html ./exp2/4_7_-5/

########### Exp2

	./aica 0 -0.1 4 7 -3 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/4_7_-3
	mv *.pgm *.jpg output.csv display.html ./exp2/4_7_-3/

########### Exp2

	./aica 0 -0.1 4 7 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/4_7_0
	mv *.pgm *.jpg output.csv display.html ./exp2/4_7_0/

########### Exp2

	./aica 0 -0.1 4 12 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/4_12_0
	mv *.pgm *.jpg output.csv display.html ./exp2/4_12_0/

########### Exp2

	./aica 0 -0.1 9 12 -6 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/9_12_-6
	mv *.pgm *.jpg output.csv display.html ./exp2/9_12_-6/

########### Exp2

	./aica 0 -0.1 9 12 -3 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/9_12_-3
	mv *.pgm *.jpg output.csv display.html ./exp2/9_12_-3/

########### Exp2

	./aica 0 -0.1 9 12 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp2/9_12_0
	mv *.pgm *.jpg output.csv display.html ./exp2/9_12_0/
