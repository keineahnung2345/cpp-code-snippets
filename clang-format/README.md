# clang-format
It can be used to format C/C++ code.

## Installation
In Mac, type the following to install:
```sh
npm install -g clang-format
```
After installation, check help message:
```sh
clang-format -h
```

## coding style
[Clang 10 documentation - Configurable Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html#configurable-format-style-options)

There are `LLVM`, `Google`, `Chromium`, `Mozilla`, `WebKit`, `Microsoft`.

## Use it in a project
Under your project root directory, create the file `.clang-format` with following contents:

```
BasedOnStyle:  Chromium
Standard:        Cpp11
IndentWidth:     4   
TabWidth:        4   
UseTab:          Never 
```

## Use it from command line
Formatting one file:
```sh
clang-format -i -style=Chromium <file_to_be_formatted>
```
Formatting as `.clang-format` specifies:
```sh
clang-format -i -style=file <file_to_be_formatted>
```
Note that the `file` in `-style=file` just means `file` itself, it doesn't represent some other thing!

Formatting multiple files at a time:
```sh
find . -name *.cu -o -name *.h | xargs clang-format -i -style=file
```

## Use it with VSCode
Open each C/C++ file and press <kbd>Shift</kbd> + <kbd>Option</kbd> + <kbd>F</kbd>.
