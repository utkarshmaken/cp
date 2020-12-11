[Editorial Page](../sprinklr-set-2.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Using Dijkstra as a Black-Box (and Hashing a pair of integers)](#using-dijkstra-as-a-black-box-and-hashing-a-pair-of-integers)
* [The Final Algorithm](#the-final-algorithm)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
I'm assuming you've solved **Dijkstra** from **Fractal Analytics** (it was meant to serve as a warm-up to this question).

----

We didn't have a constraints page for this question, hence, I took a first glance at the question, and thought it would be a simple Dijkstra, followed by **path-restoration** followed by removing `k` heaviest edges in the shortest path. **`you_know_who`** was quick to point out that this wouldn't work.

Consider a graph on 3 vertices, namely `A, B, C` which are connected in the form of a cycle. Say, the edge weight `A---B` is 1 and `B---C` is 1, but `A---C` is `infinity`. According to Dijkstra, the min cost to travel from `A` to `C` is 2 by crossing 2 edges. With one wildcard, you can reduce it to atmost one. However, it should be clear that the answer should be zero if you apply the wildcard on the heaviest edge (which you normally wouldn't consider in "Dijkstra").

----

A quick google search led me to a blog on CF, which said that the expected time complexity is `O(n*k log(n*k))`. I quickly realized that this is just a variation of [Uva - Full Tanks?](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2352) (which is a great question, and you should definitely solve it. However, be warned that the time limit is strict).

----

Observe that during our journey in the optimal path, a vertex (let's call it **state** for now) isn't uniquely defined by just its number. We also have to take into account how many wildcards we have available with us when we reach that vertex.

For example, you might reach the vertex labelled `5` with 3 wildcards remaining or maybe `0` wildcards remaining. Of course, we should treat these 2 states separately.

----

We are familiar with the proof of correctness of **Dijkstra**. If we can somehow reduce this graph to some other graph on which "Dijkstra" could be applied intuitively, we are done.

So, as per the above discussion on "states", visualize a scenario where nodes in a graph can be represented by 2 integers. (Don't worry about how you'll implement this on a computer, just focus on the core concepts).

The source vertex has `k` wildcard available. We don't know whether in the first step we should use a wildcard or not. If we decide to use it, we also need to find out on which "neighbour" we should use it. To finish all speculation, let's just do a brute-force and list out all possibilities.

> Focus carefully on the next part as we are going to build the **state-graph** now.

**Notation** : Let's increment original `k` by one. Now, at any point in our journey, the number of wildcards available to use would be one of `0....(k - 1)`.

We'll construct a new graph, where each node has 2 numbers associated with it. The first number tells us the vertex number in the original graph, and the second number `avail` tells us the number of wildcard still available when we reach this node. As should be obvious from the definition, this new "state-graph" can have atmost `n*k` vertices.

Assume current node is `(u, avail)`.

1. **We decide to use the wildcard** : In this case, simply add an edge with **zero weight**`(u, avail) ---> (v, avail - 1)`, where `v` is all the neighbours of `u` in the original graph. Notice how `avail` has decreased.
2. **We decide not to use the wildcard** : In this case, simply add an edge with original weight `(u, avail) ---> (v, avail)`, where `v` is all the neighbours of `u` in the original graph. Notice how `avail` has remained the same.

Repeat the above steps for each edge, and the state graph is constructed. Notice that all possible vertex scenario is present in the state graph. We do not know the optimal path that we should take, but we can run **Dijkstra** on the "state-grap" , with source as `(source, full_avail)` and finally take the minimum of `(dest, any_avail)` (as we don't care how many wildcards we have left when we reached `dest`).

----

The algorithm is complete in itself and you can simulate this process with nodes as `pair<int, int>` instead of integers.

# Using Dijkstra as a Black-Box (and Hashing a pair of integers)
While this works, this might make the code a bit harder to debug. What if I told you that we can represent the "state-graph" as integers rather than pairs (and then run the plain old "Dijkstra" on it). When **`you_know_who`** told me this approach, I was like, **Wait, what? You can do that?**. 

The idea is to use custom hashing for small integers. Say, we want to hide the information, `(vertex, avail)` inside a single number. We can do this by : 

```
pass = k*vertex + avail
```

To extract the value of `avail`, we can just do `pass % k`, To extract the value of `vertex`, we can just do `pass/k`. This works because `0 <= avail < k` (so basically, Euclid's Divison Lemma). This is also one of the reason why we did `k++`.

# The Final Algorithm
* `k = total_wildcard + 1`
* Initialize a **state-graph** on `n*k` vertices
* For each edge `u--->v` in the original graph, with weight `w`, do
	* For `avail` in `[0, k)`, do
		* Add a directed edge of weight **zero** from `(u, avail) ---> (v, avail - 1)`.
		* Add a directed edge of weight **zero** from `(v, avail) ---> (u, avail - 1)`
		* Add an undirected edge of weight `w` from `(u, avail) <---> (v, avail)`

* Use the above hashing rule to simplify the calculations.
* Run **standard Dijkstra's Algorithm** in the state graph, with source as `(0, full_avail)`.
* For each `pass` in the state graph, do
	* Extract original vertex by `pass/k`
	* Do `res[orig_vertex] = min(res[orig_vertex], dist[pass])`

----

I've probably over-complicated this. You can refer to [Shortest Path Modelling](https://codeforces.com/blog/entry/45897?locale=en) for an alternate explanation.

----

# Code
* [My Solution](solution.cpp)

----


