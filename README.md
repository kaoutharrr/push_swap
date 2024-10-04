# Push Swap Project

## Table of Contents
- [Introduction](#introduction)
- [Objectives](#objectives)
- [Instructions](#instructions)
- [Algorithm](#algorithm)
- [Chunks Algorithm](#chunks-algorithm)
- [Performance](#performance)
- [Setup and Compilation](#setup-and-compilation)
- [Usage](#usage)
- [Testing](#testing)

## Introduction
This project is part of the curriculum at **42** and involves sorting a stack of integers with a limited set of operations using two stacks (A and B). The goal is to use the fewest number of operations to sort stack A in ascending order.

## Objectives
The main objective of this project is to create a program (`push_swap`) that outputs a series of operations to sort a given list of integers. The allowed operations are:
- `sa` (swap top two elements of stack A)
- `sb` (swap top two elements of stack B)
- `ss` (swap both stacks)
- `pa` (push top element of stack B to stack A)
- `pb` (push top element of stack A to stack B)
- `ra` (rotate stack A upwards)
- `rb` (rotate stack B upwards)
- `rr` (rotate both stacks upwards)
- `rra` (rotate stack A downwards)
- `rrb` (rotate stack B downwards)
- `rrr` (rotate both stacks downwards)

## Instructions
1. You will be provided with a list of integers, and the task is to sort these integers using the allowed operations.
2. Your program should output the series of operations needed to achieve the sorted stack A.
3. The fewer operations you use, the better your solution will be graded.

## Algorithm
This project requires you to implement a sorting algorithm to achieve the task. Several algorithms can be used, but for this README, we focus on a **Chunks Algorithm** approach.

## Chunks Algorithm

### Overview
The Chunks Algorithm works by breaking the unsorted list into smaller parts (chunks). Instead of sorting the entire stack in one go, we deal with smaller subsets of the list, gradually moving them between the two stacks (A and B) until everything is sorted.

### Steps:
1. **Divide into Chunks:** 
   - Determine the number of chunks based on the size of the list. For example, with a list of 100 integers, you could divide it into 5 chunks, each containing 20 integers.
   - The chunk boundaries can be determined by sorting the array and splitting it into groups. For instance, the first chunk contains the smallest numbers, the next chunk the next smallest numbers, etc.

2. **Push Chunk to Stack B:** 
   - Start by pushing elements from stack A that belong to the current chunk to stack B. Keep track of the maximum and minimum elements of each chunk.

3. **Sort Stack B and Push Back to Stack A:** 
   - Once all elements of the current chunk are in stack B, sort them in descending order (largest to smallest) and push them back to stack A. This ensures that when you move them back, they are in the correct order in stack A.

4. **Repeat:** 
   - Repeat this process for all chunks, ensuring that each chunk is sorted and returned to stack A in the correct order.

### Example:
- Suppose you have a list of 10 integers. First, you sort them to define chunk ranges. Let's say for simplicity, your chunk size is 2. You will push the smallest two integers (chunk 1) to stack B, sort them, and push them back. Then move to the next chunk and repeat.

### Benefits of Chunks Algorithm:
- Efficient for medium and large datasets, as it breaks down the problem into manageable parts.
- Reduces the number of operations needed by focusing on smaller sections of the stack at a time.
  
## Performance
The project's performance will be graded based on the number of operations it uses. The fewer operations, the better your score.

General benchmarks:
- **5 numbers:** Max operations allowed = 12
- **100 numbers:** Max operations allowed = 700
- **500 numbers:** Max operations allowed = 5500

The Chunks Algorithm, when properly implemented, is capable of meeting these performance requirements.

## Setup and Compilation

### Prerequisites
- **GCC or another C compiler**: Make sure you have a C compiler installed on your machine.
- **Make**: You will use a `Makefile` to compile the project.

### Compilation
1. Clone the repository:
   ```bash
   git clone git@github.com:kaoutharrr/push_swap.git
    ```
2. Navigate to the project directory:
   ```bash
   cd push_swap
   ```
3. Compile the program using the Makefile:
  ```bash
  make
  ```
This will generate the push_swap executable.

### Usage
You can run the program with a series of numbers as arguments:
```bash
  ./push_swap 3 2 5 1 4
```
The program will output the list of operations needed to sort the input.
#### Example
```bash
  $ ./push_swap 3 2 5 1 4
  rra
  rra
  pb
  rra
  rra
  pb
  ra
  sa
  pa
  pa
```
### Testing
You can test your program using various sets of numbers:

Testing with a random set of numbers:
```bash
  ARG=$(seq -100 100 | sort -R | head -n 100 | tr '\n' ' '); ./push_swap $ARG
```
This command will generate a random set of 100 numbers between -100 and 100 and run your program on them.















   
