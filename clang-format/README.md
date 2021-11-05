# clang-format
It can be used to format C/C++ code.

## Installation

### On Mac
On Mac, type the following to install:
```sh
npm install -g clang-format
```

### On Windows

Go to [LLVM Snapshot Builds](https://llvm.org/builds/) and click the hyperlink Windows installer (64-bit).
Then optionally add `...\LLVM\bin` into your environment path.

If you already have visual studio installed, then there should be a `clang-format.exe` in `C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\Llvm\x64\bin\clang-format.exe`.


After installation, check help message:
```sh
clang-format -h
```
Check version:
```sh
clang-format -version
```
## Coding style, style options
[Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)

There are `LLVM`, `Google`, `Chromium`, `Mozilla`, `WebKit`, `Microsoft`.

### Disabling Formatting on a Piece of Code
[Disabling Formatting on a Piece of Code](https://clang.llvm.org/docs/ClangFormatStyleOptions.html#disabling-formatting-on-a-piece-of-code)

Just add `// clang-format off` and `// clang-format on` around that piece of code.

```cpp
int formatted_code;
// clang-format off
    void    unformatted_code  ;
// clang-format on
void formatted_code_again;
```

### Categorize the headers
[How to create category for external headers in clang-format?](https://stackoverflow.com/questions/55792370/how-to-create-category-for-external-headers-in-clang-format)

### Dummy .clang-format

[How to ignore files or directories with clang-format 3.9](https://stackoverflow.com/questions/50647960/how-to-ignore-files-or-directories-with-clang-format-3-9)

clang-format will ignore its located directory.

`SortIncludes: Never` doesn't work, it should be changed to `SortIncludes: false`.

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

## Use it with Visual Studio
[ClangFormat Support in Visual Studio 2017](https://devblogs.microsoft.com/cppblog/clangformat-support-in-visual-studio-2017-15-7-preview-1/)

Put `.clang-format` under your project root directory. 

Enable clang-format:
Go to `Tools > Options > Text Editor > C/C++ > Formatting` and check `Enable ClangFormat support`.

Hot key:
Format Document: <kbd>Ctrl</kbd> + <kbd>K</kbd>, <kbd>Ctrl</kbd> + <kbd>D</kbd>.
Format Selection: <kbd>Ctrl</kbd> + <kbd>K</kbd>, <kbd>Ctrl</kbd> + <kbd>F</kbd>.

To format all files at once, install the plugin [Format All Files](https://marketplace.visualstudio.com/items?itemName=munyabe.FormatAllFiles).

## Example

[My .clangformat](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/clang-format/.clang-format) conform to [C++ Programming Style Guidelines](https://geosoft.no/development/cppstyle.html)
