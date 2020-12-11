[Editorial Page](../clumio-set-1.md)

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
As I mentioned in the e-mail, the question is conceptually easy, but would require a careful implementation to avoid bugs and code-duplication.

There exists a lot of solution, using maps, DFS, BFs, etc (all of them equally good). I'll explain my approach.

First, forget about the second grid. We want to structure our functions in such a way that it can process the 2 matrices in the exact same manner. So we'll just keep a parameter for a general matrix.

Given a matrix, how do we effectively(?) store the information of its connected components (without any data loss). Clearly, just storing the count/starting-position is not enough. Well, the easiest way would be to just store every member of a particular connected component in one conatiner, and store the resulting container in a bigger container. Notice that there would be as many smaller containers as there are connected components.

**Algorithm** : Perform DFS, intialized with an empty vector. As soon as you reach a new cell, push the co-ordinates into the vector. At the end of DFS call, push the vector into a collection of vector.

Mirror the process for the second matrix.

Now, you have 2 vectors (which itself contains vectors), and you need to find out how many containers are same. But notice that containers might be arranged differently even though the connectd components are exactly the same (due to dfs order). To resolve this issue, we'd like to define an order relation between them. The workaround is very simple, sort each smaller container (for both matrix). Now that an ordering is defined, if the connected componets are indeed equal, their sorted containers must be equal.

The last things is to compare 2 vectors for equality. This already exists in STL, and you could do it in a brute force manner(by comparing each pair of elements and checking for equality.

----

# Code
* [Set Intersection](image-matching-set-intersection.cpp)
* [Parallel DFS](image-matching-parallel-dfs.cpp)

