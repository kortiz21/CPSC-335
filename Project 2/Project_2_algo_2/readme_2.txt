Algorithm 2:  Run Encoding Problem 
The String Run Encoding problem involves compressing a string to ensure that it takes less 
space. A "run" is a substring of repeated characters, for example "aaaa". Run-length encoding 
means replacing all similar characters with a single copy of the character and a count of how 
many times it appears. For example, "aaaa" is replaced with "4a", because there are 4 copies 
of  the  letter  'a'.  In  our  run-length  encoding  problem,  all  runs  are  encoded,  and  the  input 
strings  are  limited  to  lower-case  letters  and  space  characters.  The  string  run  encoding 
problem can be defined as follows:  
 
String run encoding problem  
input: a string 𝑆 of 𝑛 characters, where each character is a lower-case letter or space 
output: a string 𝐶 where each run of 𝑘 repetitions of the character 𝑥 is replaced with the 
string "𝑘𝑥" 
Sample inputs and outputs: 
• "ddd" becomes "3d" 
• "heloooooooo there" becomes "hel8o there" 
• "choosemeeky and tuition-free" becomes "ch2osem2eky and tuition-fr2e" 

Getting Started
Dependencies
Run on windows 10 or higher

Installing
N/A

Executing program
Build and run off ide of preferred choice

Help
N/A

Authors
Kevin Ortiz