import os 
import subprocess

PROGRAM= "../prolog_parser"


start = 1 
end = 8 


for i in range(1,end+1):
    test_path = os.path.join(f"./test{i}.pl")

    output = subprocess.run(
        [PROGRAM, test_path],
        capture_output= True,
        text = True,
    )

    output_path = os.path.join(f"./output{i}.txt") 

    with open(output_path,'w') as output_file:
        output_file.write(output.stdout)



