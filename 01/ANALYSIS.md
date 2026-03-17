# Folder `01` Analysis

This folder contains introductory C++11 examples focused on language features.

## What each file demonstrates

1. **`01-nullptr.cpp`**
   - Overload resolution difference between `NULL` and `nullptr`.
   - `show(nullptr)` selects the pointer overload and avoids ambiguity.

2. **`02-uniform-init.cpp`**
   - Uniform initialization catches narrowing.
   - `int sum2 {x+y+z}` is intentionally commented out because brace-init rejects narrowing conversions.

3. **`03-uniform-widget.cpp`**
   - In-class member initializers and constructor delegating (`Widget():Widget(0,0)`).
   - Shows most-vexing-parse with `Widget w2();` comment.

4. **`04-uniform-vector.cpp`**
   - List initialization of `std::vector` and range-based for loop.

5. **`05-auto.cpp`**
   - `auto` type deduction for scalar and pointer values.
   - `auto w { new Widget };` deduces `Widget*`.

6. **`06-auto-init-list.cpp`**
   - Distinguishes scalar deduction (`auto s1 {1}`) from initializer-list deduction (`auto s2 = { ... }`).

7. **`07-auto-copy.cpp`**
   - Important rule: `auto` drops references and top-level `const`, potentially triggering copies.
   - Contrasts `auto`, `const auto&`, and `decltype(foo())`.

8. **`08-class-default.cpp`**
   - Uses `=default` special members and deletes copy operations with `=delete`.

## Overall observations

- The examples are compact and educational, with inline comments showing compile-time errors and why they happen.
- Some files allocate memory (`new Widget`) without cleanup because they are tiny demos; in production code prefer RAII (`std::unique_ptr`).
- Method `show()` could be marked `const` in several classes to better model read-only behavior.
- `#include <cstdlib>` appears unused in most files and can be removed to reduce noise.

## Suggested modernization (optional)

- Replace diagnostic `typeid(...).name()` output with `std::is_same` checks for portable, readable type assertions.
- Add a simple CMake target per chapter for reproducible builds.
