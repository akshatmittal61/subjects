# Notes

## Syllabus

-   Asymptotic Notation
-   Time and space complexity
-   Divide and conquer, all sorting algos, heap tree
-   Greedy Methods: Job sequencing, knapsack, optimal merge pattern,
    huffman coding, dijkstra, minimum spanning tree (Prims's, Kruskal)
-   Graph Traversal: DFS, BFS, Connected components
-   Dynamic Programming: All pair shortest path, multistate graph, optimal binary search tree, TSP, 0/1 Knapsack, LCS, Matrix chain multiplication, Sum of Subset
-   Hashing
-   Polynomial, Non polynomial, NP hard, NP complete (insignificant)

## Algorithm

Finite set of steps/instructions to solve a particular problem

Characterstics:

-   No. of steps should be finite
-   There should be no ambiguity

## Asymptotic Notation

### Big Oh(O)

-   Worst case
-   Upper bound (at most)

```tex
f(n) = O(g(n))
f(n) <= c.g(n)

where c>0, n>=k, k>=0
```

For e.g.)

```tex
f(n)=n^2+n
n^2+n <= c.g(n^2)
n^2+n <= 2n^2

```

### Big Omega(Ω)

-   Best case
-   Lower bound (at least)

```tex
f(n) = Ω(g(n))
f(n) >= c.g(n)
```

### Big Theta(Θ)

-   average case
-   exact time

```tex
c_1.g(n)<=f(n)<=c_2.g(n)
```

## Properties of Asymptotic notations

| Notation       | Representations              | Reflexive                                                       | Symmeteric                                                      | Transitive                                                      |
| -------------- | ---------------------------- | --------------------------------------------------------------- | --------------------------------------------------------------- | --------------------------------------------------------------- |
| Big Oh (O)     | f(n) <= c.g(n)               | ![#34a853](https://via.placeholder.com/15/34a853/000000?text=+) | ![#ea4335](https://via.placeholder.com/15/ea4335/000000?text=+) | ![#34a853](https://via.placeholder.com/15/34a853/000000?text=+) |
|                | a<=b                         |                                                                 |                                                                 |                                                                 |
| Big Omega(Ω)   | f(n) >= c.g(n)               | ![#34a853](https://via.placeholder.com/15/34a853/000000?text=+) | ![#ea4335](https://via.placeholder.com/15/ea4335/000000?text=+) | ![#34a853](https://via.placeholder.com/15/34a853/000000?text=+) |
|                | a>=b                         |                                                                 |                                                                 |                                                                 |
| Big Theta(Θ)   | c_2.g(n) <= f(n) <= c_2.g(n) | ![#34a853](https://via.placeholder.com/15/34a853/000000?text=+) | ![#34a853](https://via.placeholder.com/15/34a853/000000?text=+) | ![#34a853](https://via.placeholder.com/15/34a853/000000?text=+) |
|                | f(n) = g(n), a=b             |                                                                 |                                                                 |                                                                 |
| Small Oh (o)   | f(n) < c.g(n)                | ![#ea4335](https://via.placeholder.com/15/ea4335/000000?text=+) | ![#ea4335](https://via.placeholder.com/15/ea4335/000000?text=+) | ![#34a853](https://via.placeholder.com/15/34a853/000000?text=+) |
|                | a<b                          |                                                                 |                                                                 |                                                                 |
| Small Omega(ɷ) | f(n) > c.g(n)                | ![#ea4335](https://via.placeholder.com/15/ea4335/000000?text=+) | ![#ea4335](https://via.placeholder.com/15/ea4335/000000?text=+) | ![#34a853](https://via.placeholder.com/15/34a853/000000?text=+) |
|                | a>b                          |                                                                 |                                                                 |                                                                 |
