#!/bin/bash
rm *.pgm
rm *.jpg
rm *.csv
mkdir exp1
############ Exp1
	./aica 1 0 1 15 -1 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp1/1_15_-1
	mv *.pgm *.jpg output.csv display.html ./exp1/1_15_-1/

	./aica 1 0 1 15 0 >output.csv
    matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
    mkdir ./exp1/1_15_0
	mv *.pgm *.jpg output.csv display.html ./exp1/1_15_0/

	./aica 1 0 1 15 1 >output.csv
    matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
    mkdir ./exp1/1_15_1
	mv *.pgm *.jpg output.csv display.html ./exp1/1_15_1/


############ Exp1

	./aica 1 0 3 15 -1 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m;  quit "
	mkdir ./exp1/3_15_-1
	mv *.pgm *.jpg output.csv display.html ./exp1/3_15_-1/

	./aica 1 0 3 15 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m;  quit "
	mkdir ./exp1/3_15_0
	mv *.pgm *.jpg output.csv display.html ./exp1/3_15_0/

	./aica 1 0 3 15 2 >output.csv
    matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m;  quit "
    mkdir ./exp1/3_15_2
	mv *.pgm *.jpg output.csv display.html ./exp1/3_15_2/

########### Exp1

	./aica 1 0 6 15 -2 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp1/6_15_-2
	mv *.pgm *.jpg output.csv display.html ./exp1/6_15_-2/

	./aica 1 0 6 15 0 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp1/6_15_0
	mv *.pgm *.jpg output.csv display.html ./exp1/6_15_0/

	./aica 1 0 6 15 1 >output.csv
	matlab -nodesktop -nosplash -nodisplay -r "run ./convertPGM.m; quit "
	mkdir ./exp1/6_15_1
	mv *.pgm *.jpg output.csv display.html ./exp1/6_15_1/


