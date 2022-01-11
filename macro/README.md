# macro

## ifdef with logical operators
[Using logical operators with macros](https://stackoverflow.com/questions/13711868/using-logical-operators-with-macros)
```cpp
#if defined(MACRO1) || defined(MACRO2)

#else

#endif
```

```cpp
#if !defined(MACRO1) && !defined(MACRO2)

#else

#endif
```

## check if its c++20 or more higher version
[How to determine the version of the C++ standard used by the compiler?](https://stackoverflow.com/questions/2324658/how-to-determine-the-version-of-the-c-standard-used-by-the-compiler)
```cpp
#if __cplusplus >= 202002L

#else

#endif
```
