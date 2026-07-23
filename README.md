*This project has been created as part of the 42 curriculum by dpetutschnigg and lschawer.*
# push_swap


# Description
`push_swap` is an algorithmic sorting project from the 42 curriculum.

The objective of this project is to sort a stack of integers using a restricted set of stack operations while minimizing the number of instructions generated.

The program receives an unordered list of integers as input and outputs a sequence of operations that transforms the initial stack (`a`) into a sorted stack. The available operations include swapping, pushing between stacks, rotating, and reverse rotating.

The project focuses on:
- parsing and validating user input,
- implementing efficient sorting algorithms,
- managing dynamic data structures,
- analysing algorithmic complexity,
- optimizing the number of operations.

This implementation includes several sorting strategies:
- **Simple** strategy: suitable for small inputs, using an O(n²) approach.
- **Medium** strategy: using an intermediate complexity approach of O(n√n).
- **Complex** strategy: using an efficient O(n log n) algorithm.
- **Adaptive** strategy: automatically selecting the most appropriate algorithm depending on the disorder level of the input.

Additionally, the program includes a benchmarking mode (`--bench`) which collects statistics about the sorting process, including the number of operations performed and the selected strategy.


# Instructions

## Compilation

The project compiles with the flags `-Wall`, `-Wextra`, and `-Werror`, using `cc`.
The Makefile contains the following rules:

* make all = default rule to create `push_swap.a`
* make clean = deletes the object files generated during compilation
* make fclean = deletes the object files AND the library (`push_swap.a`)
* make re = performs `fclean` followed by an `all` to re-compile everything from scratch

---

## Execution

The program is executed by passing integers as arguments. They can be passed as individual integers, or as one string. :

```bash
./push_swap 3 2 1 5 4
```
```bash
./push_swap "3 2 1 5 4"
```

The program outputs the sequence of operations needed to sort the stack.

Example:

```
sa
pb
ra
...
```

If the input is already sorted, no output is produced.

---

## Available Flags

One flag can be used to select the sorting strategy. If no strategy flag is provided, the program defaults to the Adaptive strategy.
In addition, the Benchmark flag can be used to display additional information about the sorting process.

Flags are order-independent and can be provided in any combination.

#### Simple strategy

```bash
./push_swap --simple numbers...
```

Uses an O(n²) sorting algorithm.

---

#### Medium strategy

```bash
./push_swap --medium numbers...
```

Uses an O(n√n) approach designed as a balance between simplicity and performance.

---

#### Complex strategy

```bash
./push_swap --complex numbers...
```

Uses an O(n log n) algorithm optimized for larger input sizes.

---

#### Adaptive strategy

```bash
./push_swap --adaptive numbers...
```

Automatically chooses a strategy based on the disorder level of the input.

---

#### Benchmark mode

In addition to choosing a strategy, the Benchmark flag can be used to display additional information about the sorting process:
- initial disorder percentage,
- selected strategy,
- number of operations,
- operation distribution.

```bash
./push_swap --bench numbers...
```

Example:

```
[bench] disorder: 74.25%
[bench] strategy: Adaptive / O(n log n)
[bench] total ops: 512
[bench] operations: sa: 12, sb: 32 ...
```

---

## Testing with random inputs

Generate random numbers:

```bash
ARG="$(shuf -i 0-9999 -n 500)"
./push_swap $ARG
```


---

# Resources

The following resources were used to understand algorithmic complexity and implementation strategies:

- GeeksForGeeks — Sorting Algorithms  
  https://www.geeksforgeeks.org/sorting-algorithms/

  Used for:
  - comparing sorting approaches,
  - understanding complexity trade-offs,
  - reviewing implementation concepts.

...
...
...

---

# Algorithm Design and Justification

## Simple Strategy — O(n²)

The simple strategy is designed for small input sizes.

It uses a quadratic-time sorting method where each element is repeatedly compared and moved until the stack reaches the correct order.

### Advantages

- Simple implementation.
- Easy to debug.
- Low overhead for small stacks.

### Disadvantages

- Performance decreases quickly as the input size grows.

For small datasets, the simplicity of this approach outweighs its complexity.

---

## Medium Strategy — O(n√n)

The medium strategy divides the problem into smaller sections.

Instead of treating the stack as one large unsorted structure, the algorithm works with groups of elements, reducing unnecessary movements.

### Advantages

- Better performance than quadratic approaches.
- Less complex than a full O(n log n) solution.
- Good balance between implementation complexity and efficiency.

### Disadvantages

- Still not optimal for very large datasets.

---

## Complex Strategy — O(n log n)

The complex strategy uses a divide-and-conquer approach.

The input is progressively divided into smaller sections, processed, and recombined efficiently.

### Advantages

- Scales well for large inputs.
- Provides predictable performance.
- Suitable for the 500-number benchmark.

### Disadvantages

- More complex implementation.
- Requires more careful management of stack operations.

---

## Adaptive Strategy

The adaptive strategy analyses the initial disorder of the input and chooses the most suitable algorithm.

The disorder value represents how far the initial stack is from being sorted.
- Low disorder (< 0.2) → use the Simple strategy.
- Medium disorder (< 0.5) → use the Medium strategy.
- High disorder → use the Complex strategy.


---

# Project Contributions

#### Lydia Schawer
- Implemented input parsing and validation.
- Designed stack data structures.
- Implemented stack operations (swap, push, rotate, reverse rotate).
- Added benchmarking functionality.


#### Daniel Petutschnigg
- Developed and implemented multiple sorting strategies.
- Implemented adaptive strategy selection.
- Tested performance with random input generation and debugging tools.

