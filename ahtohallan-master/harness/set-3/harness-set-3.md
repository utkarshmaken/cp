You can find the codes in the respective folder.

# University Career Fair
This is a classical question by the name **Activity Selection**. You need to create a new array which denotes the finish time of each job, then sort all the activities in non-decreasing order of finish time. Finally, start taking the activities in a greedy manner from this sorted order.

# Paint the Ceiling
This is just a classical technique known as **2 Pointer** with a couple of _catch_.

**Catch 1** : The values can become huge, so you need to use `long long` instead. If it results in _MLE_ use a single global array instead of a local vector.

**Catch 2** : You don't actually need to sort the array. It's already sorted in strictly increasing order.

**Catch 3** : Calculating `(a*b + c)%m` would result in overflow even if `a` and `b` are of the type `long long`. To handle this, use the property of modulo to simplify it as `(((a%m)*(b%m))%m + c%m)%m`.

**Cacth 4** : Even if you use 2 pointers, you should avoid multiplying and comparing (as `long long` multiplication can overflow easily. So, convert `a*b <= maxArea` to `a <= maxArea/b`.

**Catch 5** : **Binary Search** won't work as the constraints are too huge to handle a `log` factor. This was the crux of the question. You should really pay attention to the constraints before coding up the solution.

Finally, to solve it. You just need to begin with 2 pointers from front and end. If the current product is greater, decrease maximum, else get the answer and increase minimum. (Don't forget to count twice, except the identity pairs).

# University Career Fair (Hard)
This is a classical question by the name **Weighted Activity Selection**. An `O(n^2)` DP is apparent, assuming you solved **Longest Increasing Subsequence** question.

There exist a lot of variants of the `O(n log(n))` approach. Here's one that I personally like the best (inspired by lee215's post on Discuss).

First, sort all the jobs according to their finish time. Define a **Map-DP**, where `dp[end_time]` represents the maximum profit that you can earn till (and including) time `end_time`. Clearly, the base case is `dp[0] = 0`.

Now iterate over the activities in the increasing order of finish time. For any activity, we have 2 choices, either do it or don't. If we decide to do it, then we are interested in the optimal value that can be gained till the starting time of this activity. We can easily binary search this value in the map. However, if we decide to leave this activity, we just need to update it to the maximum value calculated till now (as the activities are in increasing order of finish time).

Here's a simple pseudocode which has a clever usage of **STL** features.

```python
sort according to finish time

dp[0] = 0
for each act in sorted_order
	take_it = dp[prev(upper_bound(act.start))] + act.profit
	leave_it = dp[prev(upper_bound(act.end))]
	
	dp[act.end] = max(take_it, leave_it)

Return the last element of DP array
```

