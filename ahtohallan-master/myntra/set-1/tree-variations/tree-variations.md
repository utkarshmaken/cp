[Editorial Page](../myntra-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Proof Of Correctness](#proof-of-correctness)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
If you are getting a **WA** on TC-211, it's likely that your algorithm is wrong, rather than missing corner cases. If you just print the frequency of the maximal element, test-cases upto 211 would pass. These test-cases were designed on purpose (to remove possibility of an invalid answer).

----

A lot of you already deduced that there is only one value which is a possible candidate for the answer, i.e, the **maximal value**. To summarize it, 

> The answer is either 0 or it is equal to the frequency of the maximal value.

So, the main issue is to find out when the answer would be zero. To do this, assume that the answer is non-zero. This implies that the tree must be rooted at a node with the maximal value. So, just root the tree at that node, perform a DFS, remembering the minimum value of the ancestor. If at any point of time, the condition is violated, you know that the answer does not exist.

# Proof Of Correctness
> If an answer exists, why should it be equal to the frequency of the maximal element?

**Claim** : If the answer exists, all the nodes with the maximal values would have a path consisting entirely of nodes with maxmal values. In other words, they would be directly connected to each other.

**Proof** : Assume that there is a non-maximal node on the path b/w 2 maximal nodes. This means that the answer is zero, as the condition would be violated on the end-nodes.

So, now we can assume that the maximal elements form a cluster. 

**Claim** : All the nodes in this cluster are equivalent.

**Proof** : Quoting the summary by **`you_know_who`**

> Suppose we have 2 disconnected components of `max_val`, then the answer will surely be 0. The only thing that remains to prove is that all elements of a single component are equivalent.

> Consider the tree as a net, with edges as rope, and knots as vertices. Paint this maximal component as black ( and other values as grey proportional to the value ). Now visualise holding this net from any black vertex. You can imagine that all black vertices will be at the top and continuous, and other vertices with decreasing blackness will follow. This property will hold regardless of the black knot we hold the net from ( because all the values `>= k` will be forming a single component, which will be at the top of the tree ).

----

# Code
* [My Solution](solution.cpp)

----

