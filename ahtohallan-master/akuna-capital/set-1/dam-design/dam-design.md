
[Editorial Page](../akuna-capital-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
	* [The Universal Dummy](#the-universal-dummy)
	* [The Derived Cases](#the-derived-cases)
	* [The Ultimate Reduction](#the-ultimate-reduction)
	* [Final Pseudocode](#final-pseudocode)
* [Bonus](#bonus)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This can also be solved via **Binary Search on the Answer** for each segment. You can go through the linked codes to learn more about this approach.

First of all, you need to understand the question properly. (That's the major obstacle with HackerRank questions).

**Catch 1** : The height of a mud-segment cannot exceed by more than 1 of its neighbour's height. Notice that there is no constraints on how much less can it be. It is entirely possible that the height of mud is 2 while adjacent walls are of infinite heights. A lot of people missed this fact, me included.

**Catch 2** : Although the sample inputs are sorted according to wall positions, nowhere is it mentioned that a general input would be sorted. Hence, you can't assume the same.

## The Universal Dummy
We'll start off with a dummy example. Later we'll see that all the cases can be reduced to this.

Assume that there are 2 walls, both of height 0. One of them is positioned at the origin. The second one is situated on the x-axis, with `gap` empty slots b/w them.

----

| **Gap** | **Max Height** | **Sequence**            |
|---------|----------------|-------------------------|
| 0       | N/A            | N/A                     |
| 1       | 1              | 0-1-0                   |
| 2       | 1              | 0-1-1-0                 |
| 3       | 2              | 0-1-2-1-0               |
| 4       | 2              | 0-1-2-2-1-0             |
| 5       | 3              | 0-1-2-3-2-1-0           |
| 6       | 3              | 0-1-2-3-3-2-1-0         |
| 7       | 4              | 0-1-2-3-4-3-2-1-0       |
| 8       | 4              | 0-1-2-3-4-4-3-2-1-0     |
| 9       | 5              | 0-1-2-3-4-5-4-3-2-1-0   |
| 10      | 5              | 0-1-2-3-4-5-5-4-3-2-1-0 |

----

It's not that difficult to see that the heights increases, reaches a peak and then falls down. In fact, you can even form a explicit formula. Clearly, it is `ceil(gap/2)`. To avoid floating point arithmetic, we can say it's just `(gap + 1)/2` in integer divison, provided `gap > 0`.

## The Derived Cases
Suppose, we have two towers of equal height, with `gap` slots b/w them. What is the answer? You can just shift the origin and conclude that it is


```
common_height + (gap + 1)/2 : gap > 0
```

## The Ultimate Reduction
Notice that segments do not influence each other. So, we just need to calculated the answer for each segment and take the global max. WLOG, assume that a segment has 2 towers of height, `small` and `big`, with `gap` slots b/w them.

It's clear that we'll try to increase `small` as much as it can. Suppose, `gap` is such that, no matter how much you increment, you can never reach `big`. So, you just return `small + gap`.

So, now assume that `gap` is such that you can reach `big`. So, just use `big - small` steps to equalize the heights, and then use the formula from the last section.

## Final Pseudocode
This small piece of code can effectively compute the answer for 2 consecutive towers. Remember to make sure they are consecutive by sorting on your end.

```python
solve(small, big, gap)
if gap is 0
	return 0

if(small > big)
	swap(small, big)
	
eq_dist = big - small

if gap < eq_dist
	return small + gap

small += eq_dist
gap -= eq_dist

return small + (gap + 1)/2
```

----

# Bonus
We were also planning on adding an additional problem to find the maximal sum of all heights. However, I forgot to add it in the problem set :(

----

# Code
* [My Solution](solution.cpp)
* [N\_o\_o\_B's Submission - B-Search](https://codeforces.com/gym/287803/submission/87237935)
* [BeTheStar27's Submission - B-Search](https://codeforces.com/gym/287803/submission/87240448)

----

