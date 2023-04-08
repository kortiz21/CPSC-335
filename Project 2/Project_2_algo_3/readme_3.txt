Algorithm 3:  Merging Techniques  
You  are  provided  with  grades  of  students  from  various  sections  of  CPSC  120.  The  grading 
system allows the use of negative points.   The grades appear to be sorted: the first item in 
each array is the least element in the respective array. We have decided to merge the various 
lists  into  a  single  sorted  array.    Sample  input  arrays  and  the  desired  output  are  presented 
below: 
Sample input: 
all_lists  =[ [2, 5, 9, 21], 
        [-1, 0, 2], 
        [-10, 81, 121] 
        [4, 6, 12, 20, 150] ] 
 
Sample output: 
[ -10, -1, 0, 2, 2, 4, 5, 6, 9, 12, 20, 21, 81, 121, 150] 
 
There are different ways of merging these lists. Given that the first element of each array is 
the smallest integer, you can build a list of smallest items. Pick the smallest out of the list of 
all  smallest  items.  This  will  become  the  first  item  of  the  merged  sorted  list.  You  may  then 
proceed to check all items in parent array. Another method of achieving this is through the 
use of Heap Sort. A Min heap can be used to store the smallest elements at any point in your 
algorithm. 

Getting Started
Dependencies
Run on windows 10 or higher

Installing
N/A

Executing program
Build and run off ide of preferred choice, include in2c.txt file since arrays are read in from that file
Pass in desired vector size and array size, where array size is number of vectors in in2c.txt file and
vector size is the number of vectors within the list of vectors.

Help
N/A

Authors
Kevin Ortiz