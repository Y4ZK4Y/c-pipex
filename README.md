# Pipex

## Overview

The Pipex project is a 42 School project that mimics the behavior of the Unix pipeline mechanism. It demonstrates an understanding of process creation, inter-process communication, and file manipulation in C programming. The core functionality of Pipex is to execute two commands in sequence, where the output of the first command serves as the input to the second, similar to the Unix pipeline


## Execution overview

Pipex is invoked with the following syntax:

```sh
./pipex file1 cmd1 cmd2 file2
```

- `file1`: The source file from which the first command (`cmd1`) reads its input.
- `cmd1`: The first Unix command to be executed, with its output piped to `cmd2`.
- `cmd2`: The second Unix command, which processes the output of `cmd1`.
- `file2`: The destination file where the output of `cmd2` is written.

This execution model is designed to mirror the behavior of the shell command:

```sh
< file1 cmd1 | cmd2 > file2
```


## Examples

1. **Example 1**:
   ```
   ./pipex infile "ls -l" "wc -l" outfile
   ```
   This should behave like:
   ```
   < infile ls -l | wc -l > outfile
   ```

2. **Example 2**:
   ```
   ./pipex infile "grep a1" "wc -w" outfile
   ```
   This should behave like:
   ```
   < infile grep a1 | wc -w > outfile
   ```

## Compilation and Execution

To compile pipex, run the following command in the terminal:

```
make
```

This will generate an executable named `pipex`. To run the program, use the syntax described above, replacing `file1`, `cmd1`, `cmd2`, and `file2` with your desired inputs.

