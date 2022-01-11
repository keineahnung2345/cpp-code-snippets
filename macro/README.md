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
