[Editorial Page](../zestmoney-set-1.md)

**Note** : The solution is a bit complicated. If you have a simpler solution, please make a PR. It would be a great help, thanks!.

----

<!-- vim-markdown-toc GFM -->

* [Debugging Tips](#debugging-tips)
* [Intuition](#intuition)
	* [Constraints are a red-herring](#constraints-are-a-red-herring)
	* [Precomputing the remaining leaves](#precomputing-the-remaining-leaves)
	* [Prefix sum on the Columns](#prefix-sum-on-the-columns)
* [Handling Precision Issues](#handling-precision-issues)
* [An alternate explanation (by Lavish)](#an-alternate-explanation-by-lavish)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Debugging Tips
* Although the question talks about rounding off to the nearest integer, but in reality they want you to take `ceil` of the value (as should be evident from both the sample cases).
* Now that we know that we need to use `ceil`, you should avoid using it altogether. Instead, try to use integer multiplication and modulo under 100 to simulate `ceil`. (But if you insist, it can (probably) be done with high precision `ceil` by typecasting the result to `long double` before division).
* The code for the second version might not work for the first version, as the maximal number of days is different for both of them and using a loose upper bound for the first question would result in TLE (due to large constraints on the number of trees).
* Use 70 as maximal days in version-1 and 110 in version-2.
* As was the case with **Cereal Segments**, **Arbitrary Shopping**, and so on, you might've realized that whenever you need to scan around `10^5` numbers, you need to use fast input-output or use `scanf-printf`.

# Intuition
This is an innocent looking question, but can be a bit tricky if you directly jump to the implementation without a plan.

## Constraints are a red-herring
You might be intimidated by the large constraints. But, if you observe carefully, the maximal number of days required for all the leaves in all the trees to fall is around 120 (for total leaves as large as `10^18`). However, in our case, the total number of leaves is `10^9` which would all vanish by 70 days.

To arrive at these numbers, you can observe that each time we are multiplying the remaining leaves by `30/100` (assuming the minimum fall percentage). This is the same as dividing by `100/30 = 10/3 = 3..`. You already know how rapidly numbers fall upon division by 2, (finishes in around `log_2(n)` steps). So, as a loose upper bound, we can say that it would terminate in atmost `log_3(n)` steps.

Of course, you could also run a simple simulation to get the exact numbers. You can also apply some maths to conclude that `70` is a safe limit.

## Precomputing the remaining leaves
Now that we know that all the leaves would fall by day `70`, for each index, and for each day, let us calculate the amount of leaves remaining. To do this, just start out with the seed value, and multiply by the fall percentage to get the amount of leaves that fall on the current day. Then, you can just subtract from the original value to get the remaining values.

**Catch**
* Don't directly try to compute the compute the answer for remaining leaves. First, you need to find out the amount of leaves fallen, and then subtract. This is to avoid errors in the roundoff rules.
* Make sure to deal with precision issues. You can read about them in later sections.

Let's say we've calculated these value in a matrix called `remain`, where `remain[ind][day]` represents the number of leaves remaining on day `day` on the tree at index `ind`.

## Prefix sum on the Columns
Since we are always interested in the total number of leaves in any segment on a given day, let us convert the columns of the `remain` matrix to prefix-sum. Now, we can easily answer the query, **How many remaining leaves are there in any segment on any given day**.

Finally, to answer the queries, find out the number of leaves remaining on day `day` and subtract the remaining leaves on day `day - 1`.

# Handling Precision Issues
You can either user high precision `ceil` with `long double` or multiply the percentage and divide by 100 using the divison, i.e, extract the remainder first and then divide. You can read the code for the exact details.

----

# An alternate explanation (by Lavish)
The first thing to observe is that it will take at most 120 days for all the leaves to fall down ( this is for `10^18` leaves, so pretty safe for our case).

Now suppose for each day and for each tree, I have number of leaves that will fall from that particular tree. (let say stored in `cnt[d][t]`. To answer a particular query of the form `day , left_tree , right_tree` I can make 2 cases.. 1st, when `day > 120`, in which case answer is simply 0. In other case, I want `cnt[day][left_tree] + cnt[day][left_tree+1] + .. + cnt[day][right_tree]`. By seeing this, and number of queries, you must have prefix sum in your mind. That's exactly what is stored in the `cnt[][]` in the code.


To calculate `cnt[d][t]`, I need number of leaves before the day begins. This is stored in `dp[][]` in the code. Finally, `dp[i][j] = dp[i-1][j] - leaves_fallen and cnt[i][j] = leaves_fallen`. 


The next important thing is to avoid double calculations whenever possible ( remember this as a rule of thumb).

In our case, we want to calculate `ceil((leaves*percentage)/100)`. To avoid double, we can do this as follows. Calculate `leaves*percentage` (and store it in `long long`, let say `res`). if `res % 100 == 0`, we know that we will get exact integer, and no need to round up. In other case, we need to round up `res/100`. By this, we can eliminate double calculations.
(To do this in single step, note that we can do `(res+99)/100)`.

**Bonus** : This question can also be solved by using `long double` instead of double. For details, read precision error and significant digits in floating point data types. 

----

# Code
* [My Solution (A bit long)](solution.cpp)
* [Tester's Solution](stupid.cpp)
