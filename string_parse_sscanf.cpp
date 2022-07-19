#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

// https://stackoverflow.com/questions/41692561/parsing-a-string-with-scanf
// https://stackoverflow.com/questions/8141208/sscanf-with-delimiter-in-c
// https://edisonx.pixnet.net/blog/post/75487541

int main(void) {
    float x = 0.0f, y = 0.0f;
    char  name[30], date[30], suffix[30];

    name[0] = date[0] = suffix[0] = '\0';

    // if delimeter is ' '
    string my_string = "myname 20220330-153848 x0.20 y0.00 mysuffix.txt";
    sscanf(my_string.c_str(), "%s %s x%f y%f %s", name, date, &x, &y, suffix);
    cout << name << ", " << date << ", " << x << ", " << y << ", " << suffix
         << endl;

    x = 0.0f, y = 0.0f;
    name[0] = date[0] = suffix[0] = '\0';

    // if delimeter is '_'
    my_string = "myname_20220330-153848_x0.20_y0.00_mysuffix.txt";
    sscanf(my_string.c_str(), "%[^_]_%[^_]_x%f_y%f_%s", name, date, &x, &y,
           suffix);
    cout << name << ", " << date << ", " << x << ", " << y << ", " << suffix
         << endl;
    return 0;
}

/*
myname, 20220330-153848, 0.2, 0, mysuffix.txt
myname, 20220330-153848, 0.2, 0, mysuffix.txt
*/
