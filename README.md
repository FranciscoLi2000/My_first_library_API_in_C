# 专业级 C 函数库 | Professional C Library

<div align="center">

**一个生产就绪的 C 静态库，整合了 libft、get_next_line 和 ft_printf**

**A production-ready C static library combining libft, get_next_line, and ft_printf**

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)]()
[![License](https://img.shields.io/badge/license-MIT-blue)]()
[![42 School](https://img.shields.io/badge/42-Norminette-success)]()

[中文](#中文文档) | [English](#english-documentation)

</div>

---

## 中文文档

### 📚 项目简介

mylib 是一个完整的 C 函数库，严格遵循 42 School Norminette 标准。它将三个核心项目整合到一个可复用、文档齐全、带测试的静态库中：

- **libft**: 标准 C 库函数的重新实现 + 额外实用函数
- **get_next_line**: 从文件描述符读取行的函数（支持多个 fd）
- **ft_printf**: printf 函数的自定义实现

### ✨ 特性

✅ **符合 42 Norminette 标准**
- 每行最多 80 个字符
- 每个函数最多 25 行
- 仅使用 `/* */` 注释格式
- 函数开头声明所有临时变量
- 使用最优算法和数据结构

✅ **完整功能**
- libft: 50+ 函数（字符串、内存、转换、文件输出）
- get_next_line: 支持可配置 BUFFER_SIZE 和多文件描述符
- ft_printf: 支持 %c %s %p %d %i %u %x %X %% 转换

✅ **生产就绪**
- 全面的单元测试（覆盖边界情况）
- 内存泄漏检测（Valgrind）
- 示例程序演示
- CI/CD 管道（GitHub Actions）

### 🚀 快速开始

#### 编译库

```bash
# 克隆仓库
git clone <repository-url>
cd mylib

# 编译静态库
make

# 这会生成 libft.a
```

#### 在你的项目中使用

```c
#include "include/libft.h"
#include "include/get_next_line.h"
#include "include/ft_printf.h"

int main(void)
{
    char *str = ft_strdup("Hello, World!");
    ft_printf("String: %s\n", str);
    free(str);
    return (0);
}
```

#### 编译你的程序

```bash
gcc -Wall -Wextra -Werror -Iinclude your_program.c libft.a -o your_program
```

### 📖 API 文档

#### libft 函数

**Part 1 - libc 函数**
```c
/* 字符分类 */
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);

/* 字符串操作 */
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char *ft_strdup(const char *s1);  /* 调用者需 free */

/* 内存操作 */
void *ft_memset(void *b, int c, size_t len);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_calloc(size_t count, size_t size);  /* 调用者需 free */

/* 转换 */
int ft_toupper(int c);
int ft_tolower(int c);
int ft_atoi(const char *str);
```

**Part 2 - 额外函数**
```c
/* 字符串操作（返回新分配的字符串，调用者需 free） */
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);  /* 数组和每个字符串都需 free */
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* 字符串迭代 */
void ft_striteri(char *s, void (*f)(unsigned int, char*));

/* 文件描述符输出 */
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
```

#### get_next_line

```c
/*
** 从文件描述符读取一行
** 参数: fd - 要读取的文件描述符
** 返回值:
**   - 成功: 包含 \n 的行（如果存在）
**   - EOF: NULL
**   - 错误: NULL
** 内存: 调用者必须 free 返回的行
** 注意: 支持多个文件描述符同时读取
*/
char *get_next_line(int fd);
```

**编译时配置 BUFFER_SIZE:**
```bash
gcc -D BUFFER_SIZE=42 your_program.c libft.a
```

#### ft_printf

```c
/*
** 格式化输出函数
** 参数: format - 带转换说明符的格式字符串
**       ... - 与格式说明符匹配的可变参数
** 返回值:
**   - 成功: 打印的字符数
**   - 错误: -1
** 支持的转换:
**   %c - 字符
**   %s - 字符串
**   %p - 指针地址（十六进制）
**   %d - 十进制整数
**   %i - 整数
**   %u - 无符号十进制
**   %x - 十六进制（小写）
**   %X - 十六进制（大写）
**   %% - 百分号
*/
int ft_printf(const char *format, ...);
```

### 🧪 测试

```bash
# 运行所有测试
make test

# 运行单个测试
make test_libft     # libft 函数测试
make test_gnl       # get_next_line 测试
make test_printf    # ft_printf 测试

# 运行示例程序
make demo

# 内存泄漏检测
valgrind --leak-check=full ./test_libft
```

### 🛠️ Makefile 目标

```bash
make              # 编译库
make clean        # 删除目标文件
make fclean       # 删除目标文件和库
make re           # 重新编译
make test         # 运行所有测试
make demo         # 编译并运行示例程序
```

### ⚠️ 常见陷阱

#### 内存管理
```c
/* ✅ 正确 */
char *str = ft_strdup("test");
free(str);  /* 总是释放 */

/* ❌ 错误 */
char *str = ft_strdup("test");
/* 忘记 free - 内存泄漏！ */
```

#### get_next_line
```c
/* ✅ 正确 - 多 fd 支持 */
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);
char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);  /* 可以交替读取 */
free(line1);
free(line2);

/* ⚠️ 注意 - 最后一行可能没有 \n */
char *line = get_next_line(fd);
if (line)  /* 检查是否有换行符 */
{
    size_t len = ft_strlen(line);
    if (line[len - 1] == '\n')
        /* 有换行符 */
    else
        /* 最后一行，没有换行符 */
}
```

#### ft_printf
```c
/* ✅ 正确 */
int count = ft_printf("Value: %d\n", 42);  /* 返回打印的字符数 */

/* ❌ 错误 */
ft_printf("Test");  /* 没有换行符 - 可能不会立即显示 */
```

### 📝 代码风格

此库严格遵循 42 School Norminette:
- 最多 80 个字符/行
- 最多 25 行/函数
- 仅 `/* */` 注释
- 变量在函数开头声明
- 无全局变量
- 静态函数用于内部辅助函数

### 📄 许可证

MIT License - 可自由用于个人和商业项目

---

## English Documentation

### 📚 Project Overview

mylib is a comprehensive C function library that strictly follows 42 School Norminette standards. It integrates three core projects into one reusable, well-documented, tested static library:

- **libft**: Reimplementation of standard C library functions + additional utilities
- **get_next_line**: Function to read lines from file descriptors (multi-fd support)
- **ft_printf**: Custom implementation of printf function

### ✨ Features

✅ **42 Norminette Compliant**
- Maximum 80 characters per line
- Maximum 25 lines per function
- Only `/* */` comment format
- All temporary variables declared at function start
- Optimal algorithms and data structures

✅ **Complete Functionality**
- libft: 50+ functions (strings, memory, conversion, file output)
- get_next_line: Configurable BUFFER_SIZE and multi-fd support
- ft_printf: Supports %c %s %p %d %i %u %x %X %% conversions

✅ **Production Ready**
- Comprehensive unit tests (edge cases covered)
- Memory leak detection (Valgrind)
- Example programs
- CI/CD pipeline (GitHub Actions)

### 🚀 Quick Start

#### Compile the Library

```bash
# Clone repository
git clone <repository-url>
cd mylib

# Compile static library
make

# This generates libft.a
```

#### Use in Your Project

```c
#include "include/libft.h"
#include "include/get_next_line.h"
#include "include/ft_printf.h"

int main(void)
{
    char *str = ft_strdup("Hello, World!");
    ft_printf("String: %s\n", str);
    free(str);
    return (0);
}
```

#### Compile Your Program

```bash
gcc -Wall -Wextra -Werror -Iinclude your_program.c libft.a -o your_program
```

### 📖 API Reference

See the Chinese section above for detailed API documentation. All function prototypes are identical, with English comments in the header files.

### 🧪 Testing

```bash
# Run all tests
make test

# Run individual tests
make test_libft     # libft function tests
make test_gnl       # get_next_line tests
make test_printf    # ft_printf tests

# Run demo program
make demo

# Memory leak check
valgrind --leak-check=full ./test_libft
```

### 🛠️ Makefile Targets

```bash
make              # Compile library
make clean        # Remove object files
make fclean       # Remove object files and library
make re           # Recompile
make test         # Run all tests
make demo         # Compile and run demo program
```

### 💡 Best Practices

1. **Always free allocated memory** - All functions returning `char *` or `void *` require caller to free
2. **Check return values** - NULL indicates malloc failure or error
3. **BUFFER_SIZE configuration** - Test with various sizes (1, 42, 10000000)
4. **Multi-fd support** - get_next_line can handle multiple files simultaneously
5. **Format specifier matching** - Ensure ft_printf arguments match format string

### 🎯 Use Cases

This library is perfect for:
- **42 School Projects** - Pre-tested, reliable functions
- **Portfolio Projects** - Demonstrates C programming skills
- **Interview Prep** - Shows understanding of low-level programming
- **Real Projects** - Production-ready, well-tested code

### 📊 Performance

- **Optimal algorithms**: O(n) for string operations, O(1) for character checks
- **Memory efficient**: Minimal allocations, no memory leaks
- **Fast compilation**: Static library with incremental builds

### 🤝 Contributing

This is an educational project. Feel free to:
- Report bugs
- Suggest improvements
- Use as reference for your own implementation

### 📄 License

MIT License - Free to use for personal and commercial projects

---

<div align="center">

**Made with ❤️ for 42 School and Beyond**

⭐ If this library helped you, please give it a star!

</div>
