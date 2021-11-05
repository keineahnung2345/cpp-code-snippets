# EditorConfig

[EditorConfig](https://editorconfig.org/) is used to format codes. It's supported by visual studio natively.

## Use with Visual Studio

### Dump .editorconfig

[Code styles in EditorConfig files](https://docs.microsoft.com/en-us/visualstudio/ide/code-styles-and-code-cleanup?view=vs-2019#code-styles-in-editorconfig-files)

Go to `Tools > Options > Text Editor > C/C++ > Code Style > General`. Click `Generate .editorconfig file from settings`.

### Add .editorconfig into a solution/project

[Add an EditorConfig file to a project](https://docs.microsoft.com/en-us/visualstudio/ide/create-portable-custom-editor-options?view=vs-2019#add-an-editorconfig-file-to-a-project)

For C/C++, `Solution/Project > Add > Existing Item...`, choose the dumped `.editorconfig` file.

### Formatting
Code Cleanup (<kbd>Ctrl</kbd>+<kbd>K</kbd>, <kbd>Ctrl<kbd>+</kbd>E</kbd>), which applies any white space settings, such as indent style, and selected code style settings, such as how to sort using directives.

Edit > Advanced > Format Document (or <kbd>Ctrl</kbd>+<kbd>K</kbd>, <kbd>Ctrl</kbd>+<kbd>D</kbd> in the default profile), which only applies white space settings, such as indent style.

## Style options
[C++ EditorConfig formatting conventions](https://docs.microsoft.com/en-us/visualstudio/ide/cpp-editorconfig-properties?view=vs-2019)

## Examples

Some C++ editorconfig examples:

[My .editorconfig](https://github.com/keineahnung2345/cpp-code-snippets/blob/master/editorconfig/.editorconfig)  conform to [C++ Programming Style Guidelines](https://geosoft.no/development/cppstyle.html)

[[Day-15] Editor Config自訂編輯與設定](https://ithelp.ithome.com.tw/articles/10193754)

[buoto/.editorconfig](https://gist.github.com/buoto/7e2cff6c17c108658fc751df845b1040)

[tats-u/.editorconfig](https://gist.github.com/tats-u/9cbc335b2578d3c6c36fa23a08228ed0)
