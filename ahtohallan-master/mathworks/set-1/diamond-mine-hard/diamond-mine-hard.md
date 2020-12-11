[Editorial Page](../mathworks-set-1.md)

<!-- vim-markdown-toc GFM -->

* [Switch to one-Based Indexing](#switch-to-one-based-indexing)
* [Greedy DP with Backtracking doesn't work](#greedy-dp-with-backtracking-doesnt-work)
* [Dynamic Programming to the Rescue](#dynamic-programming-to-the-rescue)
* [Do we really need to modify the grid?](#do-we-really-need-to-modify-the-grid)
* [Did we miss anything?](#did-we-miss-anything)
* [Pseudocode for 4D DP](#pseudocode-for-4d-dp)
* [Drop a dimension and recover it from other parameters](#drop-a-dimension-and-recover-it-from-other-parameters)
* [Pseudocode for 3D DP](#pseudocode-for-3d-dp)
* [Optimising the space complexity](#optimising-the-space-complexity)
* [Code](#code)
* [Credits](#credits)

<!-- vim-markdown-toc -->

----

If you are active in the **Leetcode community**, you might already know that people dread this question. (By the way, this question goes by the name **Cherry Pickup** on Leetcode). I, for one, found it quite challenging. However, the question becomes much simpler once you see the DP definition for the question. But, as anticlimatic as it may seem, this question is asked a lot during placement/interview tests. So, might as well quit procrastinating and solve it now.

----

# Switch to one-Based Indexing
If we switch to one based indexing, our corner cases would become almost non-existent. **Why?** If we hit a row or column with index `0`, we know that it has gone out of the boundary.

The conversion is easy.

```cpp
vector<vector<int>> new_grid(n + 1, vector<int>(n + 1, 0))

for(int i = 0; i < n; i++)
	for(int i = 0; j < n; j++)
		new_grid[i + 1][j + 1] = old_grid[i][j]
```

----

# Greedy DP with Backtracking doesn't work
I'm sure most of you might've got a **WA** on the first hidden case (i.e, Test-Case 3). The approach looks so convincing, yet it is wrong. 

> If you take the maximum possible diamond in the forward traversal (while modifying the grid) and then take the maximum possible diamonds in the backward traversal, you'll miss out on the elements which are on the opposite sides of the diagonal.

Here's a very clever counter example for **Greedy DP**.

Consider the following grid. Assume that the blank cells are indeed blank and you can pass through it (There are no thorns in this configuration).

|           	| **Col 1** 	| **Col 2** 	| **Col 3** 	| **Col 4** 	| **Col 5** 	| **Col 6** 	| **col 7** 	|
|:---------:	|:---------:	|:---------:	|:---------:	|:--------:	|:--------:	|:--------:	|:-------:	|
| **Row 1** 	|     1     	|     1     	|     1     	|     1    	|          	|          	|         	|
| **Row 2** 	|           	|           	|           	|     1    	|          	|          	|         	|
| **Row 3** 	|           	|           	|           	|     1    	|          	|          	|    1    	|
| **Row 4** 	|     1     	|           	|           	|     1    	|          	|          	|         	|
| **Row 5** 	|           	|           	|           	|     1    	|          	|          	|         	|
| **Row 6** 	|           	|           	|           	|     1    	|          	|          	|         	|
| **Row 7** 	|           	|           	|           	|     1    	|     1    	|     1    	|    1    	|

If you try to maximize the cherries in each trip, you'll end up taking the following path in Round 1
* Go right till column 4 (Cherries Collected is 4)
* Go down till row 7 (Cherries collected is 6)
* Go right till column 7 (Cherries collected is 3)

The total cherries collected is **13**.

In the return trip, you have 2 options
* Go left till column 1 and go up till row 1
* Go up till row 1 and go left till column 1.


As you can easily see, in both of these options, you can only collect a single cherry.

So, you'll always end up leaving one cherry in the grid. However, if you play smart, you can collect all the cherries.   

**Optimal Path**
* **Trip 1** : Go right till column 4, go down till row 3, go right till column 7 and then go down till row 7.
* **Trip 2** : Go left till  column 4, go up till row 4, go left till column 1 and then go up till row 1.

----

# Dynamic Programming to the Rescue
It is clear that greedily picking the maximum cherries is not a feasible option. Consider any optimal path from `source` to `destination` and back again. If you notice carefully, it is the same as 2 persons collecting maximum cherries collectively, where one person starts from `(1, 1)` and goes to `(n, n)` , while the other person starts from `(n, n)` and goes to `(1,1)`. 

If you look even more closely, you'll observe that it is also the same as 2 persons starting simultaneously from `(n, n)` and going towards `(1, 1)`. Of course, if they are present at the same cell at the same time, only one of them would take the diamond present in that cell.

That's all the obsesrvation we need to solve this question.

Suppose, there are 2 persons `A` and `B`. Both the persons start from certain cells (possibly different) **at the same time** and try to reach the left-most cell of the grid,i.e, `(1,1)`. Of course, they should only take valid step, i.e, **up** or **left**.

Let us define `dp[x][y][p][q]` as **The maximum amount of diamonds(combined) that can be collected by both persons along their path to `(1, 1)` when Person `A` starts at the cell `(x, y)` while Person `B` starts at the cell `(p, q)`.** (We assume that if both the people reach the exact same cell at any point, only one of them would collect the diamond in that cell). Of course, it might happen that you are not able to reach `(1,1)` from the given starting positions. In that case, we set `dp[x][y][p][q] = minus_infinity`. 

Notice that our answer would be `dp[n][n][n][n]`. 

The transitions are simple. At the next time step, both the persons have to take a step (either to the *left* or *up*). Observe that these are independent events.

Here are the 4 possible scenario.

| **A's Move** 	| **B's Move** 	| **A's New Pos** 	| **B's New Pos** 	|
|--------------	|--------------	|-----------------	|-----------------	|
|    **Up**    	|    **Up**    	|   `(x - 1, y)`  	|   `(p - 1, q)`  	|
|    **Up**    	|   **Left**   	|   `(x - 1, y)`  	|   `(p, q - 1)`  	|
|   **Left**   	|    **Up**    	|   `(x, y - 1)`  	|   `(p - 1, q)`  	|
|   **Left**   	|   **Left**   	|   `(x, y - 1)`  	|   `(p, q - 1)`  	|


After each one of them has performed their move, we would like to know what is the maximum diamonds that can be collected from the new positions. Now, this has been converted to a typical dynamic programming problem.

To summarise, the transitions are :


```cpp
/* Ensure DP is intialized with minus infinity */
if (either of the cell is a thorn)
	continue

dp[x][y][p][q] = max(up_up, up_left, left_up, left_left)

// All the moves are invalid
if( dp[x][y][p][q] < 0 )
	continue

dp[x][y][p][q] += mat[x][y]

if( both cells are not the same)
	dp[x][y][p][q] += mat[p][q]
```

**The Base Case?** : When both the persons start at `(1, 1)`. There's no possible move left, and they can only collect the diamond in that cell. Hence, `dp[1][1][1][1] = mat[1][1]`.

----

# Do we really need to modify the grid?
The answer is **No**. At first sight, it looks as if person `B` can visit a cell which has been already visited by person `A`. However, this is not true. And I'll leave it to you to prove the following result.

**Theorem** : The paths of both the  persons are disjoint and intersect **if and only if** they meet at the intersecting cell (at the same time). In other words, person `B` cannot enter a cell which has already been visited by person `A` in the past (and vice-versa).

----

# Did we miss anything?
Yes, it might happen that there is no path from source to destination. Hence, we need to ensure that we do not return a negative value (Either return `0` or return `-1` as per the requirements of the question).

----

# Pseudocode for 4D DP
Just to re-iterate
1. Convert to one based indexing.
2. Create a 4D vector and initialize it to `minus_infinity`
3. Set the base case. (`dp[1][1][1][1] = new_grid[1][1]`)
4. For each of the **n^4** starting positions, compute the maximum value of the next move.
5. If no move is possible, skip it.
6. Make the best move, and take the diamond in the current cells.
7. Make sure not to double count the current cell (if they are identical)
8. If there is no path, return 0, else, return `dp[n][n][n][n]`

----

# Drop a dimension and recover it from other parameters
We are creating a 4D matrix, so the time complexity has already jumped to `O(n^4)`. Do we really need all the four dimensions? Are all the states reachable for our specific question?

Notice that we are computing the answer for every possible pair of starting positions but in the end, we are only using the result of `dp[n][n][n][n]`. If you notice carefully, you'll see that if 2 persons start at the same time from cell at `(n, n)`, then there is a correlation between their co-ordinates at any given point of time.

**Lemma**
At any given point of time `(x + y) == (p + q)`, given both the people start from the same cell.

**Proof**
It is very easy to see that any step, person `A` would either take a step up, in which case, `x` reduces by 1, or takes a step left, in which case `y` reduces by 1. Hence, no matter what, the sum of the co-ordiantes, i.e `(x + y)` decreases exactly by 1. The same is true for the second person. Hence, this sum would be equal at all times, given they start from the same position.

So, now we don't need the fourth dimension in our DP table. We can recover it from the first three dimensions, effectively reducing the complexity to **O(n^3)** from **O(n^4)**.

**Everything remains the same except now we need to check if the recovered dimension goes out of bounds or not**. (Notice that we didn't need this check in the 4D DP case. Why?

----

# Pseudocode for 3D DP
1. Convert to one based indexing.
2. Create a 3D Vector and initialise it to `minus_infinity`.
3. Set the base case, `dp[1][1][1] = new_grid[1][1][1]`
4. For each `n^3` states, do
	* Recover the fourth dimension.
	* Check whether it's going out of bounds or not.
	* Check if either of the current cell is a thorn.
	* Calculate the maximum profit from the next possible (4) moves.
	* If you're stuck from everywhere, skip.
	* Take the best move and also collect the diamond in the current cell.
	* Don't double count if you are in the same cell.
5. Don't double count if you are in the same cell.

----

# Optimising the space complexity
As indicated by the unusual time limit of the hard version, it should be clear that the intended solution is **O(n^3)** in time but **O(n^2)** in memory.

If you're reading this section, you wouldn't have much trouble optimizing the space complexity.

**Hint** : Do a **Knapsack Style** optimization. Notice that the answer for current states depend on two 2D matrices. So, you can just keep 2 matrices, say, `dp_current` and `dp_prev` and swap them as soon as the first loop ends. I'll leave the implementation details for you to figure out. You can go through the linked code if you wish.

----

# Code
* [2D DP](solution.cpp)

----

# Credits
[The Real MVP](https://leetcode.com/problems/cherry-pickup/discuss/165218/Java-O(N3)-DP-solution-w-specific-explanation)
