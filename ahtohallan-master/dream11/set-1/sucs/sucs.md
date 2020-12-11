
[Editorial Page](../dream11-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
It's very easy to overthink this one. The original test was of 90 minutes and consisted of the last 3 questions. Considering the difficulty of the last problem, I decided to extend the duration to 2 hours. Well, I had to add a filler question, so I just picked one from Leetcode. 

The original problem is ranked **LC-Easy**, as it can be done via sorting and 2 pointers if the constraints were low. To make it **LC-Med**, I added the tight constraints and time limit.

However, with the given constraints, sorting the array was not possible. I'm not sure why many of you didn't realize this fact and jumped straight into coding. Plus, I had also mentioned that the time limit is strict.

----

Coming onto the question, it's obvious that an `O(n)` solution is required.

One obvious (incorrect) approach that comes to mind is to exclude the longest sorted **prefix** and the longest sorted **suffix** from the array. However, this fails on this simple test case

```
2 3 1 6 4 5
```

The longest sorted prefix is `[2, 3]`, while the longest sorted suffix is `[4, 5]`. However, it should be obvious that we need to sort the entire array.

----

We can easily solve it by a simple 1D DP.

Let us define a DP, `min_right`, where `min_right[i]` denotes the minimum element to the right of the `i-th` element (including itself). Transitions are `O(1)`.

```
min_right[i] = min(a[i], min_right[i + 1])
```

Looking at the above recursion, it should be obvious that if we fill the DP from right to left, we can populate the DP array in a simple pass, in time `O(n)`.

----

Similarly, define a DP, `max_left`, where `max_left[i]` denotes the maximum element to the left of the `i-th` element (including itself). Transitions are `O(1)`.

```
max_left[i] = max(a[i], max_left[i - 1])
```

Looking at the above recursion, it should be obvious that if we fill the DP from left to right, we can populate the DP array in a simple pass, in time `O(n)`.

----

How can this help us?

Notice that the minimum element of the array has to be at position 1. If it is, then we can just cutoff that element from the array (since it won't be reordered during sorting). The second minimum should be at second place, and so on...

So, we just iterate the array and find out the first position where `min_right[i] != a[i]`. Similarly, we find out the largest `j` such that `max_left[j] != a[j]`. Finally, our answer would be the closed-closed interval `[i, j]`.

----

# Code
* [My Solution](solution.cpp)

----

