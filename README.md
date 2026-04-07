# Problem 124 - 希兹亚的售票系统

**ACMOJ Problem ID**: 1877

## Table of Contents

- [Problem 124 - 希兹亚的售票系统](#problem-124-希兹亚的售票系统)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1877. 希兹亚的售票系统** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/124/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

听说有人在写火车票大作业，希兹亚也想做个与火车票相关的系统。现在希兹亚正在处理与买票订单相关的部分，但是他遇到了问题，想拜托你来解决。

这个子任务是这样的：

对于某条火车线路，一共有 $x$ 个站点。始发站为1号，终点站为 $x$ 号, 这列火车上一共有 $k$ 个座位。现在这个系统收到了 $p$ 笔订单，每笔订单都由 $u$、$v$、$n$ 三个整数组成，表示从起点站 $u$ 到目标站 $v$ 需要预定 $n$ 个座位。

一笔订单能满足是指该笔订单在行程范围内有能满足的空座位，否则就不能满足。一笔预定订单不能拆分，也就是起点站和目标站不能更改，预定的座位数目也不能更改。所有的预定需求按给出先后顺序进行处理，如果能满足就进行处理。

请你帮希兹亚完成这个部分，他会非常感激你的。

**请注意，这道题的数据量有点大，建议使用`scanf`和`printf`或快读和快写进行输入输出。**

### Input Format

第一行为三个整数 $x$, $k$, $p$。

接下来 $p$ 行，每行为三个整数 $u$, $v$, $n$，分别表示每一个预定d订单。

### Output Format

针对每个订单，输出一行，每行一个字母，$T$ 表示该预定订单能满足，$N$ 表示该预定订单不能满足。

### Samples

#### Sample 1

**Input:**
```
4 6 4
1 4 2
1 3 2
2 4 3
1 2 3
```

**Output:**
```
T
T
N
N
```

### Data Constraints

- 对于 $20\\%$ 的数据，$1\le x, p \le 1000$, $k \le 6000$;

- 对于 $40\\%$ 的数据，$1\le x, k, p \le 100000$;

- 对于 $100\\%$ 的数据，$1\le x, k, p \le 1000000$。

## Resource Limits

- **Time Limit**: 1150 ms
- **Memory Limit**: 488 MiB

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1150 ms
- **Memory Limit (per test case)**: 488 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/124/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
