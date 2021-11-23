# Windows

## Visual Studio

### Check MSVC version
[Finding version of Microsoft C++ compiler from command-line (for makefiles)](https://stackoverflow.com/questions/1233312/finding-version-of-microsoft-c-compiler-from-command-line-for-makefiles)

Go to `Tools` - `Command Line` - `Developer Command Prompt`, type `cl.exe`, the result will be:
```
**********************************************************************
** Visual Studio 2019 Developer Command Prompt v16.11.5
** Copyright (c) 2021 Microsoft Corporation
**********************************************************************

C:\Users\xxx>cl.exe
Microsoft (R) C/C++ Optimizing Compiler Version 19.29.30136 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
```

So current MSVC version is 19.29.
