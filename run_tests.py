import os 
import sys
import subprocess


PROGRAM= "./prolog_parser"
TEST_DIR="tests"

start = 1 
end = 8 


for i in range(1,end+1):
    test_path = os.path.join(os.getcwd(),f"{TEST_DIR}/test{i}.pl")

    output = subprocess.run(
        [PROGRAM, test_path],
        capture_output= True,
        text = True,
    )

    output_path = os.path.join(os.getcwd(),f"{TEST_DIR}/output{i}.txt") 

    with open(output_path,'w') as output_file:
        output_file.write(output.stdout)



