[Editorial Page](../nutanix-set-3.md)


<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Tricky Test Cases](#tricky-test-cases)
* [Code](#code)
* [Remark](#remark)

<!-- vim-markdown-toc -->

----

# Intuition
**Observation 1** : The only way to the change the number of digits is via increment.

Let's define a **Leader** of length `len` as the number `1000....` where `#ones + #zeros = len`. Observation 1 simply states that you cannot create a `len` digit number without crossing the leader. (And of course, the only way to reach the leader is via increment in `999.....`).

To make things more concrete, here's an example, say, you want to reach `1729`. Since it's a 4 digit number, at some point you must have reached the *leader*, i.e, `1000`, which in turn implies that you must reach `999` optimally, increment, and then reach `1729`. Notice that this observation reduces the number of digits in our original number by 1 (and this process would continue further).

So, we need to recursively calculate the cost to reach the *Leader* (optimally) first.

This reduces our original problem to **Given a leader** `1000....`, **of length** `len`, **how do we optimally reach any** `len` **digit number**.

I haven't found a proper proof of correctness for the following fact (but it's been verified by BFS).

**Split the number into 2 halves, increment till the value of the reverse of first half, reverse and increment till the value of the last half**.

Also, you'd get a bonus of `1` in the last reversal (as the starting digit of the leader is already `1`).

Of course, if in the process of increments you reach your number, you should terminate the process. 

----

# Tricky Test Cases
1) **Numbers Ending with a Zero** : You can avoid this smartly by subtracting 1 from the number, recursing on the new number and adding 1 to the result.

2) **One Digit Number** : Should be easy to handle.

3) **The number and leader have the same first half** : You won't need to do reversals in this case.

4) **Numbers with odd length** : It's a bit tricky, but observe that you don't need to include the middle element in reversal.

----

# Code
* [My Solution](solution.cpp)
* [Tester's Solution](stupid.cpp)
* [Pattern Generated via BFS](pattern.txt)

----

# Remark
* A lot of people might've come close to the solution, missing only the `tricky test cases` mentioned above. I intentionally created the first test to be all numbers in the range `[1, 1e5]`, so that you have a hard time understanding whether your general approach is incorrect or if you are missing an edge case. 
* **If you have a nice proof of correctness, feel free to make a PR!**
