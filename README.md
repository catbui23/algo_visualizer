# algo_visualizer

A CLI application for visualizing algorithms, currently focused on sorting algorithms.  
This project aims to provide an intuitive way to observe how algorithms operate step by step, along with tracking their computational behavior.

## Features

- Visualize sorting algorithms step by step in a CLI environment
- Track the number of operations performed, including:
  - Swaps
  - Comparisons
  - Accesses
  - Assignments

## Supported Algorithms

The following sorting algorithms are currently implemented:

- Bubble Sort
- Cycle Sort
- Heap Sort
- Insertion Sort
- Intro Sort
- Merge Sort
- Quick Sort
- Radix Sort
- Selection Sort
- Three-way Merge Sort
- Tim Sort

## Visualization Capabilities

The visualizer supports tracking and displaying the following operations:

- Swapping
- Comparing
- Accessing
- Assigning

## Usage

### Options

```bash
algo_visualizer [OPTIONS]
```

| Options        | Description                           |
| -------------- | ------------------------------------- |
| `-h`, `--help` | Show help message                     |
| `-f`, `--file` | Load configuration from JSON file     |
| `-l`, `--list` | Show all available sorting algorithms |

Example:

```bash
algo_visualizer --list
```

### Run with Command Line Arguments

```bash
algo_visualizer <algorithm> <input_type> <value>
```

1. `algorithm`
   - Name of the sorting algorithm (must be valid).
   - Use `--list` to see all supported algorithms.
2. `input_type`
   - `--array`: Provide input array manually.
   - `--randomize`: Generate random array.
3. `value`
   - With `--array`: Comma-separated list of integers, e.g: "5,4,3,2,1".
   - With `--randomize`: Size of the array (positive integer), e.g: 20.

Example:

```bash
algo_visualizer quick --array "5,4,3,2,1"
algo_visualizer merge --random 20
```

### Run with JSON file

```bash
algo_visualizer -f config.json
```

| Key         | Type                  | Required | Description                               |
| ----------- | --------------------- | -------- | ----------------------------------------- |
| `algorithm` | `string`              | Yes      | Sorting algorithm name                    |
| `array`     | `array<unsigned int>` | No       | Input array                               |
| `randomize` | `bool`                | No       | Enable random generation (default: false) |
| `size`      | `unsigned int`        | No       | Size of random array                      |

Example:

```json
{
  "algorithm": "tim",
  "array": [5, 4, 3, 2, 1],
  "random": true,
  "size": 10
}
```

> ⚠️ Important Notes
>
> - If random = true → random array will be used and array will be ignored
> - If random = false → array will be used
> - If no arguments are provided → help will be shown

## Demo

Bubble Sort

<https://github.com/user-attachments/assets/f6fe555b-ec41-4916-bb85-7165a6ec529d>

Merge Sort

<https://github.com/user-attachments/assets/de3aae10-dd2f-4f94-8256-3b0b9b2dd315>

Quick Sort

<https://github.com/user-attachments/assets/cdc49789-1269-435b-a3f9-5504770a615a>

## Current Status

The project is actively under development. Future improvements may include:

- Support user input
- Additional algorithms (trees related algorithm, path-finding, etc.)
