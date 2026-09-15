*This project has been created as part of the 42 curriculum by haincel, baaldirm.*

# push_swap

## Description

**push_swap** is a 42 Common Core algorithmic project. The goal is to sort a
random list of integers with no duplicates held in stack `a` using the smallest
possible number of operations, with the help of a second, initially empty
stack `b`.

Only a limited set of stack operations is allowed:

`sa` / `sb` / `ss` : Swap the first two elements of `a` / `b` / both
`pa` / `pb` : Push the top of `b` to `a` / the top of `a` to `b`
`ra` / `rb` / `rr` : Rotate `a` / `b` / both up (first element becomes last)
`rra` / `rrb` / `rrr` : Reverse rotate `a` / `b` / both (last element becomes first)

The program computes then prints on the standard output, the sequence of
these operations needed to sort stack `a` in ascending order, smallest value
on top.

Mandatory single sorting algorithm goes further and embeds
**four distinct sorting strategies** in the same binary,
selectable at runtime:

- **Simple** — an `O(n²)` baseline strategy repeatedly
  find the minimum, rotate it to the top of `a`, and push it to `b`, then
  push everything back in order.
- **Medium** — an `O(n√n)` chunk-based strategy that splits the values into
  `√n` ranges and processes them range by range.
- **Complex** — an `O(n log n)` radix-sort-style strategy that sorts values
  bit by bit on their rank, using pushes and rotations instead of array
  indexing.
- **Adaptive** — the default strategy. It measures the **disorder** of the
  input (the proportion of out-of-order pairs, from `0` = already sorted to
  `1` = worst case) *before* doing any move, and then dispatches to the
  strategy that matches the required complexity class for that disorder
  level:
  - `disorder < 0.2` → Simple (`O(n²)`)
  - `0.2 ≤ disorder < 0.5` → Medium (`O(n√n)`)
  - `disorder ≥ 0.5` → Complex (`O(n log n)`)

  Complexity/space argument (in the push_swap operation model, i.e. number
  of `sa/sb/.../rrr` operations generated, not classic array-algorithm
  complexity):
  - Simple: for each of the `n` elements, finding the minimum costs `O(n)`
    and moving it costs at most `O(n)` rotations, giving `O(n²)` operations
    total and `O(1)` extra space (the stacks themselves are the only
    storage).
  - Medium: the input is split into `√n` chunks; each of the `√n` passes
    scans the remaining stack (`O(n)`) to extract the next value in range,
    giving `O(n√n)` operations and `O(1)` extra space.
  - Complex: values are pushed to `b` and back to `a` bit by bit over
    `O(log n)` bit positions, each pass costing `O(n)`, giving
    `O(n log n)` operations and `O(1)` extra space.

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` binary using `cc` with `-Wall -Wextra -Werror`.
Other available rules: `clean`, `fclean`, `re`.

### Usage

```bash
./push_swap [strategy flag] [--bench] [numbers...]
```

- `numbers...` — the list of integers to sort (space or argument-separated,
  no duplicates).
- Strategy flag (optional, default is `--adaptive`):
  - `--adaptive` — pick a strategy based on measured disorder (default).
  - `--simple` — force the `O(n²)` strategy.
  - `--medium` — force the `O(n√n)` strategy.
  - `--complex` — force the `O(n log n)` strategy.
- `--bench` (optional) — after sorting, print benchmark information
  (disorder, strategy used, total operation count, and the count of each
  operation type) to **stderr** as subject.pdf states, while the operation list
  itself stays on **stdout**.

If no numbers are given, the program prints nothing and returns.
On invalid input it prints `Error` on **stderr** followed by a newline.

### Examples

```bash
$> ./push_swap 2 1 3 6 5 8
ra
pb
rra
...

$> ./push_swap --simple 5 4 3 2 1
$> ./push_swap --complex 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
OK

$> shuf -i 0-9999 -n 500 > args.txt
$> ./push_swap $(cat args.txt) | wc -l

$> ./push_swap --bench 4 67 3 87 23 2> bench.txt | ./checker_linux 4 67 3 87 23
OK
$> cat bench.txt
[Bench] disorder: 40.00%
[Bench] strategy: Adaptive / O(n√n)
[Bench] total_ops: 13
...
```

## Technical choices

- Stack `a` and `b` are implemented as circular linked lists rather than
  arrays, so that rotate/reverse-rotate operations are `O(1)` pointer
  updates instead of `O(n)` array shifts.
- Each value is given a `rank` (its position in the sorted order) once, at
  the start, so the algorithms only ever compare/compute on ranks instead
  of re-sorting or re-scanning raw values.
- No global variables are used except the benchmark data, which is exposed
  through a single static accessor (`get_bench_pointer`) rather than a raw
  global, to keep it out of the rest of the program's scope.

## Resources

- [Big-O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- hargava, A. Y. (2016). Grokking algorithms: An illustrated guide for programmers
and other curious people. Manning Publications.
Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009).
Introduction to algorithms (3. bs.). The MIT Press.
- 42 push_swap subject.pdf and La Norme (coding standard) documentation.

### AI usage

AAI was used to fill in the gaps in the subject.pdf where it lacked details.
It was not used to write the function implementations themselves.

## Contributions

This is a group project completed by exactly 2 learners:

- **haincel** — stack/linked-list structure, push_swap
  language operations, input parsing and validation,
  the simple strategy, as well as helping
  complex and benchmark part of the project.
- **baaldirm** — medium and complex strategies, adaptive
  strategy and disorder calculation, benchmark mode, as well as helping
  creating the structure of the project.

Both learners contributed meaningfully to the project, reviewed each
other's code.