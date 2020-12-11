
[Editorial Page](../visa-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
	* [Prefix Sum Map](#prefix-sum-map)
	* [Sweep Line Algorithm](#sweep-line-algorithm)
	* [The Hidden Bug](#the-hidden-bug)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Notice that the question is : 

> Given a lot of intervals, what is the maximal number of intervals that intersect at any point?

There are 2 major approaches to solve this

----

## Prefix Sum Map
Since the constraints of the intervals are huge, it's clear that we cannot create that big an array. Let's build a map instead, say `covered`.

For each interval, `[left, right]`, we do `covered[left] += 1` and `covered[right + 1] -= 1`. Finally we iterate the map and convert it to a prefix-sum map.

Notice that the numbers in the prefix sum map represent the number of intervals covering a certain region. Hence, you just need to return the maximal element. Notice that with this trick, you can also find out whether 2 intervals overlap or not. How?

----

## Sweep Line Algorithm
I'm sure many of you might've already solved the classical interview question **Minimum Number of Platforms**, yet you might've missed the connection. In fact, this question is **exactly** the same as *Minimum Number of Platforms*.

Basically, there are 2 types of Greedy Algorithms used in classical interview question, one is **Activity Selection** (where you sort according to finish time and process in a greedy manner), the other is **Minimum Number of Platforms** (where you sort independently and do a merge sort style merging). Have you wondered how these 2 solutions work and why would the first method not work for this question, but the second does? Well, you should be familiar with the concept of Sweep Line (which, if you recall, also appeared in **Myntra : Load Balancing**).

You can read the [Wikipedia Post](https://en.wikipedia.org/wiki/Sweep_line_algorithm)

![Gif](https://upload.wikimedia.org/wikipedia/commons/2/25/Fortunes-algorithm.gif)

Visualize each interval as points on a 2D plane. Color start of the interval as `white` and `end` as black. Assume that a line sweeps over these points. Notice that a `white` and a `black` point cancel each other. At any point of time, the number of intervals covering the point is the net amount of `white` and `black` points to the left of it.

Notice that this algorithm doesn't care which interval has started or ended. It just looks at the question,

> Has any interval started or finished?

So, let us **mix** all the starting and ending intervals and sort them in increasing order of time. We'll also attach something to it which denotes if it is the start or end of an interval. Finally, process the points in increasing order, and increment if you see starting and decrement if you see and ending point. Keep track of the maximum seen so far.

## The Hidden Bug
It's very tempting to do this

```
for each interval
	if opening
		a.push(mp(left, 1))
	else
		a.push(mp(right, -1))
		
sort(a)

for ele in a
	counter += ele.second;
	
return max counter
```

Can you spot the error. While the code looks concise, it has a very tricky bug. Notice that when a line is fixed at a certain point, this algorithm would delete intervals first before adding them. Hence, it would give you an incorrect answer. So, always assign a `lower number` to start of the interval. This would ensure that they appear first after sorting. 

However, a quick workaround for this, as you can see in [abhinavvv306's submission](https://codeforces.com/gym/287227/submission/86752904) is to shift the end of the interval by 1. After this, it doesn't matter whether you assign a lower or higher number during sorting.

Of course, an alternate way is to `arrival` and `departure` and do a merge-sort style merging. Make sure to add a sentinel at end to avoid corner cases.

----

# Code
* [My Solution - Prefix Map](solution.cpp)
* [My Solution - Sweep Line](stupid.cpp)
* [abhinavvv306's Submission - Workaround for Sweep Line](https://codeforces.com/gym/287227/submission/86752904)

----

