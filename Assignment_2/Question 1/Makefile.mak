Question_1_1: Question_1_1.c
        gcc -o Question_1_1 Question_1_1.c -lpthread

Question_1_2: Question_1_2.c
        chmod u+x bashScript.sh
        gcc -o Question_1_2 Question_1_2.c -lpthread

run_1_1:
        ./Question_1_1

run_1_2:
        ./Question_1_2