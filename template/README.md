# Template function

Template functions should be "defined" in header file, not "declared" in header and then "defined" in source file. 
One can check out the reason in [C++ template, linking error [duplicate]](https://stackoverflow.com/questions/1353973/c-template-linking-error).

In this demo, there are two modes to choose, one is `CORRECT` mode:
```sh
g++ main.cpp utils.cpp -I . -std=c++11 -DCORRECT
```
This will run successfully.

The other is wrong mode:
```sh
g++ main.cpp utils.cpp -I . -std=c++11
```
It will generate the following error message:
```
/tmp/ccw2QuNN.o: In function `main':
main.cpp:(.text+0x206): undefined reference to `std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > join<__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > >(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, __gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
main.cpp:(.text+0x2af): undefined reference to `std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > join<__gnu_cxx::__normal_iterator<float*, std::vector<float, std::allocator<float> > > >(__gnu_cxx::__normal_iterator<float*, std::vector<float, std::allocator<float> > >, __gnu_cxx::__normal_iterator<float*, std::vector<float, std::allocator<float> > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
collect2: error: ld returned 1 exit status
```

But according to [Why can templates only be implemented in the header file?](https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file), we can also use another method: by writing template function's implementation in `xxx.tpp` and then include it in `xxx.h`, see `ex3` for example.

Another useful link: [C++ template declarations vs. definitions](http://warp.povusers.org/programming/template_declarations.html).
