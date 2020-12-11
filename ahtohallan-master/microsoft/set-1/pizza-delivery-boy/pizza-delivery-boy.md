
[Editorial Page](../microsoft-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Roundoff](#roundoff)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
The critical point is to focus on what the question is trying to test. Is it looking for algorithmic skills and asking you to use some advanced data-structures to avoid `O(n^2)` or is it trying to test your ESC101 concepts on how to round-off/truncate real numbers. Judging by the level of the questions mentioned in the mail, it's clear that an `O(n^2)` solution is acceptable provided you take care of roundoff (as the distance can become huge).

# Roundoff
How do you roundoff to 6 digits after the decimal? Of course, using inbuilt functions would not work for larger numbers. 


One way to do this is : 

1. Extract 7 digits after the decimal and discard the rest (in short, typecast it into `long long`, while retaining the information of 7 digits after the decimal.
2. Notice that we are not interested in the seventh-digit. However, it will affect the answer.
3. If the seventh-digit is greater than or equal to 5, we need to round-up else we need to round-down.
4. Just chop off the last digit and add 1 if required. Finally convert back to decimal by moving 6 digits to the right of the decimal.


**Note** : Of course, if you use `set precision`, you'll not face these issues. However, the point of this question was to solve it via traditional methods (as you don't have any control over input-output in `mettl`).

----

# Code
* [My Solution](solution.cpp)

----
