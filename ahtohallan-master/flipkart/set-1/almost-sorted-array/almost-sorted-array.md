
[Editorial Page](../flipkart-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Let's forget about `almost-sorted-arrays`. What is the minimum number of deletions that you need to sort an array in strictly increasing order. If you think about it, the **LIS** represents the longest increasing subsequence in the original array. Since it is largest group that is already sorted, you need to delete the elements which are not part of the LIS to sort the array. 

Why is this optimal? Notice that if the answer were smaller, than it means that we could've just used the element in our sequence to make an even bigger increasing sequence.

Now, our goal is to find out the **LIS**. Obviously, the `O(n^2)` DP won't work. So, we need to redefine the `O(n^2)` DP and further optimize it to `O(n log(n))`. The code is very simple and you can find an excellent write-up on [CP-Algorithms](https://cp-algorithms.com/sequences/longest_increasing_subsequence.html). 

You can find even shorter implementation on the internet, (such as [deletion via set iterators](https://codeforces.com/blog/entry/12274?#comment-400297)). However, I prefer the CP-Algorithms one, as it builds upon an intuitive DP definition and also helps in restoration. I'm sure you can commit it to long-term memory once you've understood the idea behind the alternate `O(n^2)` DP. Just make sure to try out the `O(n^2)` version before jumping onto the `(O(n log(n))` version.

Finally, notice that the question provides a bonus of one element. Hence, you need to print `max(0, n - LIS - 1)`.

----

# Code
* [My Solution](solution.cpp)

----

