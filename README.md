*This project has been created as part of the 42 curriculum by tarebros, pcellar.*

# push_swap

## Description

**push_swap** is an algorithmic project: sort a stack of unique integers using a second stack and a very limited set of operations, while producing the **smallest possible list of operations**.

The program `push_swap` receives a list of integers (first argument = top of stack `a`), computes a sequence of Push_swap operations that sorts `a` in ascending order (smallest on top, `b` empty at the end), and prints it on stdout, one operation per line.

Available operations: `sa sb ss pa pb ra rb rr rra rrb rrr`.

The project's real goal is to make algorithmic complexity concrete. The binary embeds **four strategies** and can pick one at runtime:

| Strategy | Flag | Complexity (in number of operations) |
|---|---|---|
| Simple | `--simple` | O(n²) |
| Medium | `--medium` | O(n√n) |
| Complex | `--complex` | O(n log n) |
| Adaptive (default) | `--adaptive` | picks one of the strategies above depending on disorder |

An optional `--bench` flag prints metrics to **stderr** (disorder, strategy, complexity class, total operations, count per operation type).

## Instructions

### Compilation

```sh
make        # builds ./push_swap
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
make bonus  # builds ./checker (bonus)
```

Compiled with `cc -Wall -Wextra -Werror`. The Makefile does not relink.

### Usage

```sh
./push_swap [strategy] [--bench] <int> <int> <int> ...
```

- `strategy` is one of `--simple`, `--medium`, `--complex`, `--adaptive` (default: `--adaptive`).
- With no arguments, nothing is displayed.
- On error (non-integer, out of `int` range, duplicates), `Error\n` is written to stderr.

### Testing

```sh
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG
```

## Algorithms

### Disorder metric

Before any move, the program computes the disorder of stack `a`: the ratio of *inversions* (pairs `i < j` with `a[i] > a[j]`) to the total number of pairs.

```
disorder = mistakes / total_pairs      (0 = sorted, 1 = sorted in reverse)
```

Computing it costs O(n²) CPU time, but this is not counted in the Push_swap operation model, which only measures the number of operations generated.

### Operation model

All complexity classes below are expressed in the **number of Push_swap operations generated**, not the CPU complexity of a classical array-based algorithm.

### 1. Simple: O(n²), `--simple`

**Technique:** [selection sort adaptation: repeatedly bring the minimum of `a` to the top using the shortest of `ra`/`rra`, push it to `b`, then push everything back with `pa`].

**Why O(n²):** each of the n elements may need up to n/2 rotations to reach the top, so ≤ n · n/2 + 2n operations = O(n²).

**Why we kept it:** very low overhead on small or nearly-sorted inputs; simple to prove correct.

### 2. Medium: O(n√n), `--medium`

**Technique:** [chunk-based sorting: normalise values to ranks 0..n-1, split them into ≈√n chunks, push elements of the current chunk to `b` (rotating `b` to keep a rough order), then repeatedly extract the maximum from `b` back to `a`].

**Why O(n√n):** with √n chunks of size √n, each push to `b` costs O(√n) rotations on average, giving n · √n; extraction back is bounded similarly.

### 3. Complex: O(n log n), `--complex`

**Technique:** [Radix sort on ranks, base 2: for each bit from least to most significant, `pb` elements whose bit is 1 and `ra` the others, then `pa` everything back].

**Why O(n log n):** there are ⌈log₂ n⌉ passes; each pass uses at most n (`pb`/`ra`) + n (`pa`) operations, so ≤ 2n⌈log₂ n⌉ = O(n log n).

### 4. Adaptive (default), `--adaptive`

The adaptive strategy measures the disorder first and delegates to one of the techniques above:

| Disorder | Regime | Method used | Target complexity |
|---|---|---|---|
| < 0.2 | Low | [Simple / O(n²)] | O(n²) |
| 0.2 ≤ d < 0.5 | Medium | [Medium / O(n√n)] | O(n√n) |
| ≥ 0.5 | High | [Complex / O(n log n)] | O(n log n) |

**Rationale for the thresholds:** for low disorder, few inversions mean few displaced elements, so a cheap O(n²) method that only moves what is misplaced wins in practice despite its worse asymptotic bound; for high disorder, the O(n log n) method's fixed cost per pass pays off; the middle band is a compromise. Used for disorder in ranges of 0.2 and 0.5 as per the subject's regime boundaries, radix used for the most complex cases with the highest disorder reaching above 0.5 to 1.0.

**Complexity argument (upper bounds in the Push_swap model):**

- **Time (operations):** the regime is chosen once, in O(1) after the disorder computation. The total operation count is therefore bounded by the bound of the selected method: O(n²) for d < 0.2, O(n√n) for 0.2 ≤ d < 0.5, O(n log n) for d ≥ 0.5.
- **Space:** O(n): the two stacks hold n elements in total, plus one O(n) array of ranks used for normalisation. No strategy needs more than a constant number of additional arrays of size n.

## Project structure

```
.
├── Makefile
├── README.md
├── inc/
│   ├── libft/
│   ├── printf/
│   └── push_swap.h
└── src/
    ├── bench.c
    ├── chunk.c
    ├── disorder.c
    ├── fill_stack.c
    ├── flags.c
    ├── ft_printf_stderr.c
    ├── lists.c
    ├── main.c
    ├── parse.c
    ├── push.c
    ├── radix.c
    ├── rev_rotate.c
    ├── rotate.c
    ├── selection.c
    ├── swap.c
    └── utils.c
```

## Contributions

| Learner | Contributions |
|---|---|
| tarebros | parsing numbers, filling stacks, chunk sort, radix sort, bench, flags|
| pcellar | node and stack creation, stack operations, selection sort, printf_stderr|

## Resources

### References

- Big-O notation and algorithmic complexity: https://en.wikipedia.org/wiki/Big_O_notation
- Radix sort: https://en.wikipedia.org/wiki/Radix_sort
- Selection sort: https://en.wikipedia.org/wiki/Selection_sort
- Inversions in a sequence: https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)
- Stack data structure: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

### Use of AI

- Used for explaining difficult concepts, assisting with testing and debugging, and as a tutor during the course of the work on the project.
