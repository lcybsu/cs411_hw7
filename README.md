# cs411_hw7
This project is to construct a minimum spanning tree using Prim's algorithm.

prim_firstMethod.cpp has a time complexity of O(n^2). 
prim_secondMethod.cpp has a time complexity of O(#edge log(#vertices)) using priority_queue in STL. 

Run the program and enter the graph setting following the instruction.

DEMO for prim_firstMethod.ccp

// Define the graph (testing with a square graph)
------------------------------
Enter number of vertices
4
Enter number of edges
4
Starting vertices: 
0
Ending vertices: 
1
Edge weight: 
1
Starting vertices: 
1
Ending vertices: 
2
Edge weight: 
2
Starting vertices: 
2
Ending vertices: 
3
Edge weight: 
3
Starting vertices: 
3
Ending vertices: 
0
Edge weight: 
4

------------------------------
// Program output 

Print the edges in MST：
(0,1)
(1,2)
(2,3)

Total weight of MST:6
Program ended with exit code: 0

Same porcedure for the prim_secondMethond.cpp.
