[Editorial Page](../clumio-set-1.md)

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
For people frustrated over the wording of the question, we'd like to point out that the problem statement is indeed correct, and you should've analyzed the explanation of the sample case thoroughly. (Indeed, they mention that the 2 nodes can share a common interest, even if they aren't directly connected). 

You have to be prepared for such statements during the contest. For you it was just a contest, but there are people who gave the actual test. Imagine their frustration. 

And I was surprised nobody(?) noticed the ambiguity in the **Image Matching** question. There was no indication that both the matrices were square matrices (however, I didn't include those test-cases as I didn't want to complicate things).

I'll just mention the problem statement precisely, after which it should be quite easy to solve.

**Given a graph, where there can be 100 types of (coloured) edges, for each color and for each pair of vertices, find whether they are reachable from each other using monochromatic edges. Let's say the maximal value for any 2 vertices is** `max_val`. **You need to find out the maximum pairwise product of all the vertices which are reachable from each other by using** `max_val` **distinct monochromatic edges.**

The algorithm should be simple. If we fix a colour, then the question simply asks you to check whether 2 vertices lie in the same connected component w.r.t to the colour. Since the constraints are low enough, we can fix each colour and run DFS each time to get connected component numbers.

For each pair, find out the number of colours in which they have the same connected component numbers. This is the `max_val` we are looking for. Make a second pass and take the maximal pairwise product.

----

# Code
[Multiple DFS](shared-interest.cpp)
