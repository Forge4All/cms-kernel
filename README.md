# cms-kernel

A modular, object-oriented C++ kernel for a next-generation CMS, designed for learning and extensibility.

## Quickstart

1. Clone the repo: `git clone ...`
2. Build: `mkdir build && cd build && cmake .. && cmake --build .`
3. Run tests: `ctest`

## Development

- Lint: `clang-tidy ...`
- Format: `clang-format ...`
- Pre-commit: `pre-commit run --all-files`

## Developer Scripts

All developer tools and automation scripts are in the `scripts/` directory.
- To build: `./scripts/build.sh`
- To run tests: `./scripts/test.sh`

## Contributing

Pull requests and issues are welcome! See [docs/contributing.md](docs/contributing.md) for more.

## Roadmap

- OOP core design
- Plugin system
- Community themes
