1. How to run the code

remove exp1, exp2, exp3 folders if exist
make clean; make
chmod a+x run*
./run_exp1.sh
./run_exp2.sh
./run_exp3.sh

2. Retrieve results

Experiment set 1 (Disable inhibition) is in exp1.
Experiment set 2 (Disable activation) is in exp2.
Experiment set 3 is in exp3.

Each folder inside of exp* is named as "R1_R2_h".

3. Counter-example of sync updating
chmod a+x converge.sh
./converge.sh
retrieve data in "output_converge.txt"

