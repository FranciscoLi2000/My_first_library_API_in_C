# Professional C Library Project

## Project Overview
A production-ready C static library combining libft, get_next_line, and ft_printf into one comprehensive, well-tested library following 42 School Norminette standards.

## Recent Changes (2025-11-25)
- ✅ Created complete project structure (include/, src/, tests/, examples/)
- ✅ Implemented all libft Part 1 functions (libc reimplementation)
- ✅ Implemented all libft Part 2 functions (additional utilities)
- ✅ Implemented get_next_line with multi-fd support and configurable BUFFER_SIZE
- ✅ Implemented ft_printf with all required conversions (%c %s %p %d %i %u %x %X %%)
- ✅ Created comprehensive Makefile with test targets
- ✅ Wrote comprehensive unit tests for all modules
- ✅ Created example demonstration program
- ✅ Written professional README in both Chinese and English
- ✅ Set up GitHub Actions CI/CD pipeline

## Project Architecture

### Directory Structure
```
mylib/
├── include/              # Header files
│   ├── libft.h          # libft API
│   ├── get_next_line.h  # get_next_line API
│   └── ft_printf.h      # ft_printf API
├── src/
│   ├── libft/           # 34 libft functions
│   ├── get_next_line/   # GNL implementation (2 files)
│   └── ft_printf/       # Printf implementation (3 files)
├── tests/               # Comprehensive test suite
│   ├── test_libft.c
│   ├── test_gnl.c
│   └── test_printf.c
├── examples/
│   └── demo.c           # Usage demonstration
├── .github/workflows/
│   └── ci.yml           # CI/CD pipeline
├── Makefile             # Build system
└── README.md            # Documentation (Chinese & English)
```

### Key Design Decisions

1. **Three Separate Headers**: Each project (libft, get_next_line, ft_printf) has its own header file for modularity

2. **Norminette Compliance**:
   - Maximum 80 characters per line
   - Maximum 25 lines per function
   - Only `/* */` comments
   - Variables declared at function start
   - Optimal algorithms (O(n) for strings, O(1) for char checks)

3. **Memory Semantics**:
   - All functions returning `char *` or `void *` require caller to free
   - Clear documentation of who allocates/frees memory
   - No memory leaks (verified with Valgrind)

4. **Multi-FD Support**: get_next_line uses static array to support up to 1024 concurrent file descriptors

5. **Configurable BUFFER_SIZE**: Can be set at compile time with -D BUFFER_SIZE=n

## Build & Test

### Compile Library
```bash
make                 # Build libft.a
```

### Run Tests
```bash
make test           # Run all tests
make test_libft     # Test libft functions
make test_gnl       # Test get_next_line
make test_printf    # Test ft_printf
make demo           # Run demonstration program
```

### Memory Checks
```bash
valgrind --leak-check=full ./test_libft
valgrind --leak-check=full ./test_gnl
valgrind --leak-check=full ./test_printf
```

## Coding Standards

All code follows 42 School Norminette:
- 80 characters max per line
- 25 lines max per function
- `/* */` comments only
- No global variables
- Static functions for internal helpers
- Optimal algorithms and data structures

## User Preferences

### Code Style
- Prefer readability over brevity
- Use descriptive variable names
- Document complex algorithms
- Keep functions focused on single responsibility

### Workflow
- Test-driven development
- Compile frequently to catch errors early
- Use Valgrind for memory verification
- CI/CD for automated quality checks

## Usage in Other Projects

### Linking
```bash
gcc -Wall -Wextra -Werror -Iinclude your_program.c libft.a -o your_program
```

### Example
```c
#include "include/libft.h"
#include "include/get_next_line.h"
#include "include/ft_printf.h"

int main(void)
{
    char *str = ft_strdup("Hello");
    ft_printf("String: %s\n", str);
    free(str);
    
    int fd = open("file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    ft_printf("Line: %s", line);
    free(line);
    close(fd);
    
    return (0);
}
```

## Portfolio Value

This library demonstrates:
- ✅ Strong C programming fundamentals
- ✅ Memory management expertise
- ✅ Understanding of system calls and file I/O
- ✅ Variadic functions (va_list, va_arg)
- ✅ Test-driven development
- ✅ CI/CD best practices
- ✅ Professional documentation
- ✅ Code quality standards (Norminette)

## Next Steps (Optional Enhancements)

- [ ] Bonus: Linked list functions (ft_lstnew, ft_lstadd_front, etc.)
- [ ] Bonus: ft_printf flags support (- 0 . # + and field width)
- [ ] Shared library (.so/.dylib) generation
- [ ] pkg-config file for easy integration
- [ ] Extended test suite with fuzzing
- [ ] Performance benchmarks

## License
MIT License - Free to use for personal and commercial projects
