# push_swap

<p align="center">
	<img src="https://github.com/user-attachments/assets/019e55f2-926b-46b1-a2d7-c76a63487062"
</p>

push_swap is an algorithm project involving sorting numbers in 2 stacks with as little instructions as possible and given the limited set of instructions

## Status
Finished: 2024-06-12. Grade: 125/100.

## Rules
The program is only allowed two stacks to work with, stack A and stack B. All numbers are initially added to stack A and stack B is empty.

### Instruction set
- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

## Approach
The program partitions the numbers into stack B. Then, it does a selection sort to sort back to stack A. The partition size varies depending on the number of elements. More elements, more and bigger partitions.

## Usage
### push_swap
Run `make` to compile `push_swap`<br/>

The program can be be used as such:
```bash
./push_swap 4 1 3 2 5
```
Output will look like this:
```
> ./push_swap 4 1 3 2 5
ra
pb
ra
pb
ra
sa
pa
pa
```

### Checker
Run `make bonus` to compile `checker` program <br/>
The output from the `push_swap` program can be piped into the `checker` to verify that the instructions are correct

```bash
ARG="4 1 3 2 5"; ./push_swap $ARG | ./checker $ARG
```
The checker will return `OK` if the instructions are correct or `KO` if not. Returns `Error` if arguments given are not valid
```
> ARG="4 1 3 2 5"; ./push_swap $ARG | ./checker $ARG
OK

> ./push_swap "4 1 3 2 5" | ./checker "1 2 3 4 5"
KO

> ARG="4 1 3 2 5"; ./push_swap $ARG | ./checker abcdef
Error
```
