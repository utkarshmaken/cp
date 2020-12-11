[Editorial Page](../vm-ware-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
	* [Don't modify the container while traversing via iterators](#dont-modify-the-container-while-traversing-via-iterators)
	* [Overloaded functions and the hidden return type](#overloaded-functions-and-the-hidden-return-type)
* [Final Algorithm](#final-algorithm)
* [Time Complexity Analysis](#time-complexity-analysis)
* [Further Readings](#further-readings)
* [Code](#code)

<!-- vim-markdown-toc -->

----

The 3rd question in the original test was **University Career Fair**.

# Intuition
It's been 7 years since this question appeared on **Codeforces**. But I think it's a gold standard for learning `sets` and variations of `binary_search, lower_bound`, even today.

This question has a lot of interesting approaches, including `sets`, `Union Find` and even `Segment Trees`.

The [official editorial](https://codeforces.com/blog/entry/9210) does a good job of explaining things, but I'll provide a sketch anyway.

Let us insert all the kinghts in a `set`. Also, maintain a vector `killer`, where `killer[i] = j` represents that `j` is the killer of `i`. Note that the `set` would only contain the alive knights at any point of time.

As per the conditions, for each fight, you need a list of all the alive knights which are greater than or equal to `L` but less than or equal to `R`.

There exists a convenient function in STL, called [Lower Bound](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/tree/master/Templates/Lower%20and%20Upper%20Bound) to accomplish the given task. However, note that if you use `lower_bound` defined in `algorithms` library, you'll get a **TLE** verdict on `Test - 11`. This is due to the fact that the [iterators](https://github.com/Just-A-Visitor/Algorithmic-Pseudocode/blob/master/Crash%20Course%20(DS%20%26%20Algorithms)/Lecture%20Notes/Lecture%203%20(STL).md#iterators-introduction) of `set` (which is internally a balanced **BST**) are not `random access iterators`.  So, you need to use the internal method of `sets`, which can be achieved via `mySet.lower_bound(key)`.


As soon as you have the information of these knights, you can then erase them from the set, while simultaneously setting `killer[erased] = current_knight`. 

However, there's a small catch.

## Don't modify the container while traversing via iterators
It's always a risky move to modify the container when we are iterating it via iterators. This is due to the fact that as sooon as we make some changes, the older iterators are no longer valid. Hence, if you iterate in the range `[lower_bound(L), lower_bound(R))` you might get a **WA** (as you are also deleting some elements in between, which might render `lower_bound(R)` useless).

Lucky for us, C++ provides safe alternatives to this.

## Overloaded functions and the hidden return type
* The `erase` function is overloaded, meaning, you can pass either the value to delete, or the iterator of the element to delete.
* The `erase` function also has a `return type` as the **iterator** to the next element of the container. In general cases, we might ignore it, but in this question we can make good use of it.

----

# Final Algorithm
* Create the containers, `killer` and `alive`.
* For each fight, do
	* Find the first knight to be killed.
	* Kill it, and update the `killer` array.
	* Remove it from `alive` set and go to the next alive knight.
	* If it is within the range, repeat the above steps.
* If you've accidentally erased the current winner, make sure to put it back.

----

# Time Complexity Analysis
Notice that in each query, we only use `O(log (n))` operations. You might wonder that it's not true as in some queries we are traversing a lot of elements in the set. However, if you look at the **amortized time complexity**, it would be `O(log (n))` per query. To further justify it, observe that once an element is out of the set, it would never enter again. Therefore, the extra work that we are doing is just `O(log (n))` per element. If we somehow combined all the removals in a single query, we'd get the complexity of `O(n log(n)`. But this also implies that the next queries would be less time-consuming.

To conclude, the time complexity then becomes `O( n*log(n) + q*log(n))`, which would pass under the given time limits.

----

# Further Readings
You should definitely try out the [DSU Approach](https://codeforces.com/blog/entry/9210)

----

# Code
* [Incorrect Use of Lower Bound --- TLE](solution-tle.cpp)
* [The Proper Way](solution.cpp)

----

