[Editorial Page](../clumio-set-1.md)

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Optimizations](#optimizations)
* [A Concise and Faster Solution](#a-concise-and-faster-solution)
* [Code](#code)

<!-- vim-markdown-toc -->

----

Copy pasting from the Easy-Version.

# Intuition
As I mentioned in the e-mail, the question is conceptually easy, but would require a careful implementation to avoid bugs and code-duplication.

There exists a lot of solution, using maps, DFS, BFs, etc (all of them equally good). I'll explain my approach.

First, forget about the second grid. We want to structure our functions in such a way that it can process the 2 matrices in the exact same manner. So we'll just keep a parameter for a general matrix.

Given a matrix, how do we effectively(?) store the information of its connected components (without any data loss). Clearly, just storing the count/starting-position is not enough. Well, the easiest way would be to just store every member of a particular connected component in one conatiner, and store the resulting container in a bigger container. Notice that there would be as many smaller containers as there are connected components.

**Algorithm** : Perform DFS, intialized with an empty vector. As soon as you reach a new cell, push the co-ordinates into the vector. At the end of DFS call, push the vector into a collection of vector.

Mirror the process for the second matrix.

Now, you have 2 vectors (which itself contains vectors), and you need to find out how many containers are same. But notice that containers might be arranged differently even though the connectd components are exactly the same (due to dfs order). To resolve this issue, we'd like to define an order relation between them. The workaround is very simple, sort each smaller container (for both matrix). Now that an ordering is defined, if the connected componets are indeed equal, their sorted containers must be equal.

The last things is to compare 2 vectors for equality. This already exists in STL, and you could do it in a brute force manner(by comparing each pair of elements and checking for equality.

# Optimizations
To optimize the above approach, we can use STL's builtin `set_intersection` which can return the common elements of 2 containers (which is exactly what we want). The only caveat is that the container must be sorted. We are lucky enough, we can even sort vectors and compare them. Finally, you should know about `back_inserter` which is very useful for `set_intersection`.

If you want to learn about **Prime Factorization, Number of Divisors, Set Intersection, Sieve**, all in one question, I sugges you try out **Codeforces - Modified GCD Problem**.

# A Concise and Faster Solution
To make the code more readable and error-free, you should use the technique of **Flood Fill** instead of dealing with `visited` matrices. You can practice **Flood Fill** on Leetcode and come back once you are done.

Our first function would be `normal_dfs`, which just takes a matrix and flood fills the connected components. Nothing fancy.

Our second function would be `parallel_dfs` which, you guessed it, would apply DFS on both the matrices parallelely. If both hit the same number at any time, the `paralle_dfs` would continue. However, if one of them hits 1 and the other one hits zero, it means that both these connected components are invalid and we can just destroy using flood-fill by calling `normal_dfs`. Just make sure to maintain a `flag` to indicate whether a component was rendered useless.

Thats' it. The complexity is `O(n^2)` with no hidden factors.

At this point, I must mention that there are lots of beautiful approaches for this question (for example, by using maps). You should go through the submissions to take a look at them.

----

# Code
* [No Set Intersection](no-set-intersection-correct-tle.cpp)
* [Set Intersection](set-intersection-correct.cpp)
* [Parallel DFS](parallel-dfs.cpp)
