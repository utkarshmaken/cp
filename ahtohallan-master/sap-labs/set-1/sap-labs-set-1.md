You can find the codes in the respective folder.

# Monsoon Umbrellas
This is just a direct application of a classical question by the name **Coin Change**. Indeed, view the _distinct_ size of the umbrellas as the denomination of the coins, and the number of people to be covered as the amount that you want the change for.

Let us number the _distinct_ denominations from `1` to `n`. (we don't need to sort them). Recall the DP definition, `dp[denom][amount]` represents the minimum number of coins to make a change for the amount `amount` when you are only allowed to use the first `denom` coins. The transistions are straight-forward. Either take the last coin (if possible), in which case you should recur on `dp[denom][amount - val_of_last_coin]` (as you can reuse the last denomination). Or, don't take the last coin, in which case you need the value of `dp[denom - 1][amount]`. Of course, if it is not possible to create the change, you set it to infinity.

As for a closing remark, recall that **Greedy** does not work. Consider coins of 3 denominations, `1, 15, 25`. You need to make a change for the amount `30`. If you follow a greedy strategy, you might end up taking `25 1 1 1 1 1`. However, the optimal solution is `15 15`.

**Catch** : If you have a habit of taking infinity as `INT_MAX`, make sure that you don't accidentally do arithmetic on it. My approach is to create a variable, `const int inf = ...` (without yet assigning the value). Once I've written the entire code, I go through it once to see whether I should select `INT_MAX` as infinity or some smaller number, say `1e8/1e9 + 7` would suffice.

# Traveling is Fun
This question is entirely based on 2 concepts. If you aren't familiar with them, you'd have a hard time understanding the editorial. These are **Time Complexity Analysis of Prime Generation using Sieve's Algorithm** and **Union Find**. (To be honest, you can solve this question without **Union Find**, in which case you should have the patience and confidence to implement **Graphs** and assign connected component numbers using **DFS**.)

From the constraints, it is clear that we need to answer each query in atmost logarithmic time. Of course, we cannot make any assumption on the type of queries. 

One way to solve the question is to build the graph, and add an edge between 2 vertices if their gcd is `>0`. Of course, to check this condition, you'd end up using `O(n^2 log(n))` time in the preprocessing step. (when `g == 0`). This basically means that the result might be a complete graph with an edge between any 2 vertices.

However, here's the most important fact. If there's an edge between `a --- b` and `b --- c` , you don't need to create an edge between `a --- c` as they are already in the same connnected component. So, we'll try to keep some leaders in each component and only add each edge with one end-point to the leader.

Here's another well known fact, you can iterate through all the multiples of all the numbers in the range `[1, 1e5]`, without time-out. (In fact, the complexity is `O(n log(n))`). This an amazingly helpful trick that you can apply to a lot of questions. I leave it up to you to research the proof (which again is quite elegant). Notice that the time complexity of `Sieve` is apparent from this logic, as we just iterate over divisors of prime numbers.

The final tool is a **Union Find** data structue, which can perform `merge` and `find_set` in `O(log (n))` using **Path Compression** (which, you'd be surprised, is just one line of code). Of course, it can also be improved to `O(alpha(n))` by using **Union by Rank** too, but **Path Compression** has never betrayed me so far.

Ok, so coming back to the question, for `gcd` to be greater than `g`, each of the number must be greater than `g`. Let us fix a number `k > g` and place all the numbers whose `gcd` is a multiple of `k` in one connected component. We can just make `k` as the leader and merge every multiple of `k` into the set which contains `k`. We repeate this process for all `k` in the range (which is effectively the same as looping through all multiples of all numbers).

Of course, if you are dealing with graphs instead of DSU, you should add an edge from `k` to every multiple of `k` for all `k > g`, and then perform a dfs to assign connnected component number to all the vertices, ultimately answering all queries in `O(1)` time for each of them.

As a bonus, notice that although the question talks a lot about `gcd`, nowhere in our code have we used `gcd`. However, you should know that there is an inbuilt function to calculate `gcd` by the name `__gcd(., .)`


