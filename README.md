# Matrix-Modification
Algorithm that uses a "unpeeling" method to operate on matrices.

# Problem
We have a m*n matrix that needs to be manipulated. 
Manipulation needs to take place on the layers of the matrix independent of its adjacent layer.

# Solution
An algorithm that modifies the layers of the matrix(general to m*n) layer by layer

# How?
An algorithm that "unpeels" the matrices' layers and puts them into a 1D Array. Allowing for endless number of manipulations. Then, it "re-peels" the manipulated peel and moves to the next layer. 

# Concept of Recursion
Recursion is a method of solving a problem where the solution depends on solutions to smaller instances of the same problem. For this problem, we require a recursive algorithm as it can make modifications to any m*n matrix.  
