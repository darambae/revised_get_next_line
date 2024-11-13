
# get_next_line (with bonus)

## Language
- [Français Version](./readme_fr.md)
- [한국어 Version](./readme_kr.md)

## Table of Contents

  - [Introduction](#introduction)
  - [Feature](#feature)
  - [Standard Functions for File Handling](#standard-functions-for-file-handling)
  - [Bonus](#bonus)

## Introduction

**get_next_line** is a C project that aims to provide a function for reading a line from a file descriptor, including standard input. This implementation allows for efficient line-by-line reading from files, handling multiple file descriptors simultaneously. The project focuses on memory management and dynamic allocation, ensuring that resources are properly managed while reading input. By working on **get_next_line**, you'll gain a deeper understanding of file handling in C and improve your skills in working with buffers and strings.

## Feature

- Reads a line from a file descriptor, including the newline character.
- Handles multiple file descriptors simultaneously.
- Efficient memory usage with dynamic buffer allocation.


## Standard Functions for File Handling

- `open()` : Opens a file and returns a file descriptor.
  - Prototype: `int open(const char *pathname, int flags, mode_t mode);`
  - Example: `int fd = open("file.txt", O_RDONLY);`

- `read()` : Reads data from a file descriptor.
  - Prototype: `ssize_t read(int fd, void *buf, size_t count);`
  - Example: `ssize_t bytesRead = read(fd, buffer, 1024);`

- `close()` : Closes a file descriptor.
  - Prototype: `int close(int fd);`
  - Example: `close(fd);`

## Bonus

- Handles multiple file descriptors at the same time.
- Returns the line read, or NULL if there is nothing more to read or an error occurred.
