[Editorial Page](../visa-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
First let us see when the answer is -1. To create a tree, we need `n - 1` edges. So, if we have atleast `n-1` edges in the original graph, we can always connect the entire structure. Why? In the worst case, you can delete all the edges and start creating the tree as you wish.

So, now assume that the `edges >= vertices - 1` and that the answer exists. Perform a `dfs` and find out the total connected components, say `tc`. Now, visualize each connected component as a mega node, which are independent from each other. In the end, we'd like to connect all these mega nodes. If you visualize these mega-nodes as nodes in a new graph, you'll realize that we "atleast" construct a tree out of them. Hence, we will require atleast `tc - 1` edges to connect them.

Let us prove that we can achieve the minimal move, i.e, we can connect these mega nodes by using `tc - 1` edges. Define a **free-edge** in a component as an edge which does not break the connectivity of the component once removed. If you're familiar with the term, it's often called `non-bridge` edges. In a connected graph of `n` vertices and `e` edges, how many free-edges are there? We need just `n - 1` edges to create a tree and rest edges are free edges. Hence, we have `e - (n - 1)` free edges.

If the total number of free edges in all the components is atleat `tc - 1`, then we can achieve the minimal move. So, to find total free-edges, we can remove the "bounded-edges" of all components. How many are there? Clearly, `cc_size - 1`

So, total free edges is

```
free_eddges = total_edges - sum(cc_size - 1) 
```

However, notice that `sum(cc_size) = n` and `sum(1) = tc`. Therefore, 

```
free_edges = total_edges - n + tc
free_edges >= tc - 1 ==> total_edges - n + tc >= tc - 1
total_edges >= n - 1
```

Hence, we've just shown that if total edges is greater than `n - 1`, we can always connect the disconnected components in `tc - 1` moves, which is the minimal as well as optimal.

----

# Code
* [My Solution](solution.cpp)

----

