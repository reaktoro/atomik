
# CMake-Based Project Using Atomik

## Introduction

This example demonstrates how CMake's command `find_package` can be used to
resolve the dependency of an executable `app` on **Atomik**, a C++17 library
implementing basic chemical concepts.

The source file `main.cpp` includes the header-file `Atomik/Atomik.hpp`
and uses class `ChemicalFormula` to parse the chemical formula `CaCO3`.

The `CMakeLists.txt` file uses the command:

```cmake
find_package(Atomik REQUIRED)
```

to find the **Atomik** package. The executable target `app` is then linked
against the imported target `Atomik::Atomik`:

```cmake
target_link_libraries(app Atomik::Atomik)
```

## Building and Executing the Application

To build the application, do:

```bash
cd cmake-project
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Atomik/install/dir
make
```

To execute the application, do:

```bash
./app
```

Note: If **Atomik** has been installed system-wide, then the CMake argument
`CMAKE_PREFIX_PATH` should not be needed. Otherwise, you will need to specify
where **Atomik** is installed in your machine. For example:

```cmake
cmake .. -DCMAKE_PREFIX_PATH=$HOME/local
```

assuming directory `$HOME/local` is where **Atomik** was installed to, which
should then contain the following directory:

```
$HOME/local/include/Atomik/
```

where the **Atomik** header files are located.
