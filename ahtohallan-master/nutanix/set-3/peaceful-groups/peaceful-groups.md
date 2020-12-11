[Editorial Page](../nutanix-set-3.md)


<!-- vim-markdown-toc GFM -->

* [Quick Explanation](#quick-explanation)
* [Detailed Explanation](#detailed-explanation)
	* [How to know if we are at the end of a segment?](#how-to-know-if-we-are-at-the-end-of-a-segment)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Quick Explanation
Notice that at the end of the operations, you'd be left with contiguous segments. So, you want to find out how many contiguous segments you can split it into. Start from left, and note that if a color is in that segment, then its rightmost instance must also be in the segment. Using this, we can iterate, noting the maximum righmtost instance of colors seen so far. If we're at a stage where the maximum is equal to the current element, we have our segment.

Now that we know what the segment is,  it makes sense to change all colours to the colour that appears the most (in the segment). Then we just go backwards in the segment, find the colour which appears the most and add `size of segment - max_occurrence` to the cost so far.

----

# Detailed Explanation
**Observation 1** : 2 persons starting out in the same group would always remain in the same group.

This is obvious, since we need to change the t-shirt color of all the persons in the current team simultaneously.

**Observation 2** : At the end of the operations, there would be contiguous segments of team members.

This is due to the fact that we need to avoid fights between memebers who are sandwiched between other teams.

Let us consider the first element, with `L = 1`. Say, the rightmost occurrence of this element is at `R`. By *observation 1* and *observation 2*, it should be clear that all elements of segment `[L, R]` would have to be the same colour at the end of the process. 

**Here's the catch** : Consider the first element of the segment `[L, R]` which differs from `a[L]`. By *observation 1*, all the elements between the rightmost occurrence of this element would have to be the same colour. This can continue further.

**When to stop propagating the changes** : We can stop the process once we get hold of a segment which contains **all** the occurrences of all the elements in that segment. (of course, it has to be of minimal length).

Notice that anything that you do with this segment wouldn't affect the other parts of the array. Also notice that all elements of this segment has to be of the same colour. Let's call this color `k`. The cost for this segment is the count of all the players who are not wearing the `k-th` coloured t-shirt. Clearly, to minimize this value, we must select `k` to be the maximal occurrence of any colour in this segment.

Once we solve it for a single segment, we can restart the process again. (as the problem is exactly identical).

The time complexity is **O(n log(n))**.

## How to know if we are at the end of a segment?
It looks complicated but it's actually very simple. Define a map dp, `max_right[ele]` where `max_right[ele]` represents the rightmost occurrence's index of the element `ele`. Filling this is easy, you just iterate over the array and overwrite each value as soon as you see a new element.

Start processing the elements with a variable `max_max_right` which denotes the maximum value of the `max_right` that you've seen so far. If at any point you have `max_max_right == i`, you have your segment.

After that, you can just iterate backwards, find the maximal color using a map, and compute the answer and reset everything for the next iteration.

----

# Code
* [Tester's Solution (Concise)](solution.cpp)
* [My Solution](stupid.cpp)
