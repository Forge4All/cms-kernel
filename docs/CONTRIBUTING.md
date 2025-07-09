# Contributing to cms-kernel

Thank you for your interest in contributing! This repository contains the C++ core (kernel) for the Forge4All CMS. For plugin and theme development, see the [cms-bridge](link) and [theme repos](link).

## How to Contribute

1. Fork this repository and clone your fork.
2. Create a new branch for your feature or fix.
3. Run the build and tests:
   - `mkdir build && cd build && cmake .. && cmake --build . && ctest`
4. Run pre-commit checks:
   - `pre-commit run --all-files`
5. Open a pull request with a clear description of your changes.

## Code Style

- All code must pass `clang-format` and `clang-tidy`.
- Write unit tests for new features and bug fixes (Google Test).
- Use clear, descriptive commit messages (gitmoji encouraged).

## Reporting Issues

- Open an issue with steps to reproduce, expected and actual behavior, and relevant logs.

## Questions?

- Ask in [GitHub Discussions](link) or open an issue.

We appreciate your contributions to making this project better!
