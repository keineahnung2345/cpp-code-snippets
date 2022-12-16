# thread

## Run a non-blocking process

[Asynchronous CreateProcess?](https://stackoverflow.com/questions/7507975/asynchronous-createprocess)

Just put that process into anoter thread.

```cpp
std::thread t([](std::string sApplicationName, std::string sCommandLine) {
    startup(NULL, charToWchart(sCommandLine.c_str()).get());
}, std::string(""), exe_path);
t.detach();
```

## 'invoke': no matching overloaded function found

Trying to run this function:
```cpp
int startup(LPCTSTR lpApplicationName, LPTSTR lpCommandLine);
```

With the following code:
```cpp
std::thread t(startup, NULL,  charToWchart(exe_path.c_str()).get());
t.detach();
```

It shows the following error messages.
```
Error	C2672	'invoke': no matching overloaded function found	<Your Project>	C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include\thread	55	
Error	C2893	Failed to specialize function template 'unknown-type std::invoke(_Callable &&,_Ty1 &&,_Types2 &&...) noexcept(<expr>)'	<Your Project>	C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include\thread	51	
Error	C2780	'unknown-type std::invoke(_Callable &&) noexcept(<expr>)': expects 1 arguments - 3 provided	<Your Project>	C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include\thread	51	
```
Maybe it's because thread header cannot recognize LPCTSTR and LPTSTR.

Try define a wrapper of `startup`:
```cpp
void startup(std::string sApplicationName, std::string sCommandLine) {
    startup(NULL, charToWchart(sCommandLine.c_str()).get());
};
```

And call it with:
```cpp
std::thread t(startup, std::string(""), exe_path);
```

It shows the following error.
```
Error	C2661	'std::thread::thread': no overloaded function takes 3 arguments	<Your Project>	<Your File>	<Your Line Number>	
```
Maybe it's because thread library cannot distinugish between the two startup functions. Rename the wrapper function will solve the problem.

Also wrap it in a lambda function would lead to success:
```cpp
std::thread t([](std::string sApplicationName, std::string sCommandLine) {
    startup(NULL, charToWchart(sCommandLine.c_str()).get());
}, std::string(""), exe_path);
```
