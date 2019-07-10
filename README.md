# matrix-challenges
Challenging SAT benchmarks for matrix multiplication

Details about these instances are described in the article:
Marijn J.H. Heule, Manuel Kauers, Martina Seidl (2019)
Local Search for Fast Matrix Multiplication
SAT 2019: Lecture Notes in Computer Science 11628: 155-163.
https://arxiv.org/abs/1903.11391

## Challenge 1: Local search without streamlining. 

Our first method combines ran- domly pairing the type 3 terms with streamlining constraints. The latter was required to limit the search. We expect that local search solvers can be op- timized to efficiently solve the formulas without the streamlining constraints. This may result in schemes that are significantly different compared to ones we found. We prepared ten satisfiable formulas with hardcoded pairings of type 3 terms. Five of these formulas can be solved using yalsat in a few minutes. All of these formulas appear hard for CDCL solvers (and many local search solvers).

## Challenge 2: Prove unsatisfiability of subproblems. 

We observed that complete SAT solvers performed weakly on our matrix multiplication instances. It seems therefore unlikely that one could prove any optimality results for the product of two 3 × 3 matrices using SAT solvers in the near future. A more realistic challenge concerns proving unsatisfiability of some subproblems. We prepared ten formulas with 23 multiplications and hardcoded pairings of type 3 terms. We expect that these formulas are unsatisfiable.

## Challenge 3: Avoiding a type 3 term in a summand.

All known schemes have the following property: each summand has at least one type 3 term. We do not know whether there exists a scheme with 23 multiplications such that one of the summands contains no type 3 term. The challenge problem blocks the existence of a type 3 term in the last summand and does not have any additional (streamlining) constraints.
## Challenge 4: Existence of a scheme with 22 multiplications. 

The main challenge concerns finding a scheme with only 22 multiplications. The hardness of this challenge strongly depends on whether there exists such a scheme. The repository contains a plain formula for a scheme with 22 multiplications.
