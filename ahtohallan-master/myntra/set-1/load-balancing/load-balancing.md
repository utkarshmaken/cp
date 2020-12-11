[Editorial Page](../myntra-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [The issue with Priority Queue](#the-issue-with-priority-queue)
* [Min-Seg-Tree as a Black-Box](#min-seg-tree-as-a-black-box)
* [Modifying Min-Seg-Tree](#modifying-min-seg-tree)
* [The Simplest Solution](#the-simplest-solution)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This question is not that difficult, but I was unable to think of the set-based solution while solving it. Thanks to ... for sharing their amazing approach. 

----

A lot of people were confused by the problem description. Most of them missed the keyword, **Round-Robin**, which states that you need to use the servers in a cyclic manner, regardless of the fact that the server with smaller numbers are free.

----

# The issue with Priority Queue
An immediate idea that comes to mind, is to maintain a `min-heap` that stores `(free_time, server_num)`, denoting that the server number `server_num` would be free by the time, `free_time`. The idea is to always use the top element and reinsert it with the new free time. However, this won't work.

> The above approach doesn't handle the **Round-Robin** specification.

A simple counter example for this is

```
3

4
1 2 3 100

4
10 20 1 1000
```

There are 3 servers. Naturally, you'd assign the first 3 tasks to the first 3 servers. However, when the fourth request comes, all the servers are free, but server-3 was freed first (which is actually irrelevant to our algorithm). However, with heaps, you'd end up using server-3 instead of server-1, hence violating the RR criteria.

----

# Min-Seg-Tree as a Black-Box
We can solve it in `O(n* log(n) * log(n))`. Notice that at any point of time, we are interested in the first server to the right of the last used server (in a cyclic manner), whose free time is less than or equal to the current time. If we can find this server, we can use it and then update the next free time of this server.

A Min-Seg-Tree is a data-structure which can provide the minimum element of a range in `O(log(n))`. So, we can just binary search the first element less than or equal to key by querying the seg-tree `log(n)` time, and each time discarding the right half of the segment (if possible). 

Implementation is easy, since you don't need to modify the template for SegTree. You just need to write your own version of B-Search, which is not that hard.

----

# Modifying Min-Seg-Tree
We can also solve it in `O(n log(n))` by modifying the `query` function of the segment tree, which would reduce the hassle of an outer binary-search. The idea is to place the binary search inside the query fuction. As soon as you are within a range, start a B-Search and keep discarding the right half. This would essentially answer the following query in `O(log(n))`

> Given a `key` and a `range`, find the first element in the range which is less than or equal to `key`. Return -1 if no such element exists.

With this, we can just query the right half to get the first free-server in RR method. If no server on the right is free, query the seg-tree again on the left half.

You need to rewrite your `query` function. However, `updates` would remain the same. For implementation details, you can refer to the seg-tree blog on `CP-Algorithms`.

----

# The Simplest Solution
Turns out, segment tree for this question is an overkill. The major hurdle is to differentiate b/w the busy and free servers. This makes it difficult to come up with a set-based solution. However, if you just keep the busy and free servers in 2 different sets, the question becomes quite easy to understand and implement.

Quoting the summary by `...` 

> I solved it with scan line . There are two types of events : new job or finishing an earlier job. At every instant `s` stores free servers at this point of time. When we encounter a new job we need to find the next free server (in circle). This can be easily done if we store the last used server . Then the required server is either the first element greater than the last used or the smallest element in the set `s` . When we finish a job we just need to insert the server back into the set `s`.

So, you just need to maintain 2 sets, a `free` set which contains the `ID's` of the free servers at this point of time. Of course, this set is initialized with all the available servers. You also need to maintain `busy` set that stores all the busy servers (sorted according to their `next-free-time`). The elements of the set are of the form `(next_free_time, server_id)`. You need to initialize this as an empty set.

Sort the queries according to their arrival times. For each query, delete all the servers from the `busy` set which have a `next-free-time` less than the current time. Parallely, insert these servers back into the `free` set. Also, keep track of the last used server id. To find the next server to use, just find the first server with `id` greater than the last used server. If none exists, then the server with smallest `id` would be our answer.

The complexity of the approach is `O(n * log(n))` even though we might transfer more than one element for some queries. However, if you do an analysis on how many times an element gets transferred, you'll realize that the amortized time complexity is `O(n * log(n))`. (Hint : Once the server goes inside `free` server, it would be a long time before it comes out).

----

# Code
* [My Solution - SegTree](solution-v1-ac-seg-tree.cpp)
* [My Solution - Sets](solution.cpp)
* [Submission 1](https://codeforces.com/gym/286503/submission/86207291)
* [Submission 2](https://codeforces.com/gym/286503/submission/86208959)

----

