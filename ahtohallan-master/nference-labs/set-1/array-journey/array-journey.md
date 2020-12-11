

[Editorial Page](../nference-labs-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
	* [Heaps](#heaps)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Define `dp[i]` as the maximum points that you can collect when you start your journey at `i-th` index and your destination is the last index of the array. Since you start at the `i-th` element, you necessarily need to take `a[ij`, no matter the value. After that you'd like to jump to the index which is reachable and gives you the maximum benefit.

As per the question,

```
dp[i] = a[i] + max(dp[j]) such at (i + 1) <= j <= (i + k)
```

This clearly indicates that if we fill the DP in a backward manner, we can populate it in `O(n*k)`. This is correct but not enough to pass the TL (as it's actually of order `n^2`, when `k = n/2`).

To optimize this, notice that we only care about the maximum of some range. So, we need a data structure that can 

1. Insert any element efficiently
2. Delete any element efficiently
3. Provide the maximum element at any time efficiently

`STL Heaps` wouldn't work, as you cannot do random deletions. The next guess would be to use `STL sets`, but there's actually a catch, you can insert duplicate elements. So this is also out.

In the end, we are left with `multisets`. The only catch is that some people tried to delete via values rather than iterators. This would obviously give you a WA, since when a window slides, you just need to delete one copy of the leaving element. For more discussion on **Overloading of erase** in `multisets`, refer the discussion on `Cereal Segments` from **Citrix**.

So, to summarize, we fill the DP in a reverse manner. At any point of time, our multiset would contain no more than `k` elements. We query the maximum each time, update DP values, insert it into multiset and pop the expired values. The time complexity is `O(n log(k))`.

----

## Heaps
A naive implementation with heaps wouldn't work due to the absence of random deletion. How, we can insert `(val, index)` to the heap and query the maximum each time. If the `index`  of the maximum is out of the current window, we delete it, and query the maximum again. This would give us the complexity of `O(n log(n))`. (Notice the difference).

----

# Code
* [My Solution - Heaps](solution.cpp)
* [My Solution - Multisets](solution-mset.cpp) 

----

