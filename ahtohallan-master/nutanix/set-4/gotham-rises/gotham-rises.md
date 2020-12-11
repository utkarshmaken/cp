[Editorial Page](../nutanix-set-4.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Suppose the cost of building a clinic is less than or equal to that of repairing a road. In this case, it makes no sense to build a single road (as you can always break that road and assign a clinic in either of the end-points). Hence, the answer in this case would be : `total_vertex*cost_of_clinic`.

----

Now, suppose the cost of building a clinic is more than repairing a road. So, ideally we'd like to avoid building clinics as much as possible. Notice that all the connected components do not influence each other, hence let's just talk about one connected component.

Of course, we need one clinic in this component. After that, in the worst case, we need to build `n-1` extra (and costly clinics). However, notice that you can always replace each of these `(n - 1)` clinics with a road (if you take the edges in any spanning tree). 

So, we build a clinic in a single vertex and find a spanning tree of `(n - 1)` edges and repair those roads. Notice that we only care about the count of the edges in the spanning tree. Hence the cost for a single connected component would be 

```
clinic_cost + (cc_size - 1)*road_cost
```

Summing it up over all connected components, say `total_cc`, we realize that we need to build `total_cc` clinics and `(n - total_cc)` roads.

The final cost is : 

```
total_cc*clinic_cost + (n - total_cc)*road_cost
```

All that remains is to find out the total number of connected components. This can be easily done via DFS.

----

# Code
* [My Solution](solution.cpp)
* [Tester's Solution](stupid.cpp)

----

