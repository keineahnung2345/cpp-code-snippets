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

## Use it with VSCode
Under your project root directory, create a file: `.clang-format` with the following contents:

```
BasedOnStyle:  Chromium
Standard:        Cpp11
IndentWidth:     4   
TabWidth:        4   
UseTab:          Never 
```

Then open each C/C++ file and press <kbd>Shift</kbd> + <kbd>Option</kbd> + <kbd>F</kbd>.
