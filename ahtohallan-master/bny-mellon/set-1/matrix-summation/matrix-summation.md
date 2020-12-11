[Editorial Page](../bny-mellon-set-1.md)

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This is just a watered-down version of a classical question by the name **Sum of any Rectangle in a Matrix** in `O(1)`. Since there's already a lot of videos and blogs explaining the solution, I'll just give a brief walkthrough. 

We will only be concerned with the question, **Given a matrix (not necessarily square), find out the sum of any rectangle in the matrix**. Note that the inputs are the `top-left` and the `bottom-right` co-ordinates of the rectangle. Of course, a single cell is a matrix of dimension `1x1`, so we can just reuse our code for the contest's question.

The first step is to convert our matrix to a **partial-sum** matrix, where `partial[x][y]` represents the sum of the rectangle starting at `(0, 0)` and ending at `(x, y)`. To perform the transitions, you add the **running-sum** of the current row to **partial[x - 1][y]**.

Finally, to calculate the sum of a rectangle, you'd need some inclusion and exclusion (which is fairly simple once you draw stuff on paper). It's difficult to explain without a diagram, so I'll just leave it upto you to look up some videos. I've also provided my template in the `Code` section. If you still aren't able to understand, ping me and I'll add some explanation/diagrams here. (Too lazy to do it now!).

To verify your own template, you can sumbit it at **UVa-108**.

Another relevant question is to handle sum of any subarray within an array. This can be easily done using `prefix-sums`. How do you handle point updates? (Hint : You should learn **Fenwick Trees** if you haven't already. Very simple, yet very powerful.) You can test your template at **UVa-12086**.

As a bonus question, how do you handle point updates in a matrix designated for rectangle-sum queries? (Hint : Fenwick/Segment Tree).

----

# Code
[Code](matrix-summation.cpp)

