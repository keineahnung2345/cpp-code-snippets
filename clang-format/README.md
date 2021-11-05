# clang-format
It can be used to format C/C++ code.

## Installation

### On Mac
On Mac, type the following to install:
```sh
npm install -g clang-format
```
After installation, check help message:
```sh
clang-format -h
```

### On Windows

Go to [LLVM Snapshot Builds](https://llvm.org/builds/) and click the hyperlink Windows installer (64-bit).
Then optionally add `...\LLVM\bin` into your environment path.

If you already have visual studio installed, then there should be a `clang-format.exe` in `C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\Llvm\x64\bin\clang-format.exe`.

## Coding style, style options
[Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)

There are `LLVM`, `Google`, `Chromium`, `Mozilla`, `WebKit`, `Microsoft`.

## Dump config file

[Format C/C++ Code Using Clang-Format](https://leimao.github.io/blog/Clang-Format-Quick-Tutorial/)
```sh
clang-format -style=google -dump-config > .clang-format
```

## Use it in a project
[Setting IndentWidth doesn't work in clang-format](https://stackoverflow.com/questions/26740500/setting-indentwidth-doesnt-work-in-clang-format)

Under your project root directory, create the file `.clang-format` with following contents:

```
BasedOnStyle:  Chromium
Standard:        Cpp11
IndentWidth:     4   
TabWidth:        4   
UseTab:          Never 
```

## Use it from command line
[How to call clang-format over a cpp project folder?](https://stackoverflow.com/questions/28896909/how-to-call-clang-format-over-a-cpp-project-folder)

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
or:
```sh
find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;
```

## Use it with VSCode
Open each C/C++ file and press <kbd>Shift</kbd> + <kbd>Option</kbd> + <kbd>F</kbd>.
