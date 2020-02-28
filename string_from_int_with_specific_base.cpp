#include <algorithm>
#include <cassert>
#include <climits>
#include <iomanip>
#include <iostream>
#include <locale>

//https://stackoverflow.com/questions/6478745/custom-stream-manipulator-for-streaming-integers-in-any-base

namespace StreamManip {

// Define a base manipulator type, its what the built in stream manipulators
// do when they take parameters, only they return an opaque type.
struct BaseManip
{
    int mBase;

    BaseManip(int base) : mBase(base)
    {
        assert(base >= 2);
        assert(base <= 36);
    }

    static int getIWord()
    {
        // call xalloc once to get an index at which we can store data for this
        // manipulator.
        static int iw = std::ios_base::xalloc();
        return iw;
    }

    void apply(std::ostream& os) const
    {
        // store the base value in the manipulator.
        os.iword(getIWord()) = mBase;
    }
};

// We need this so we can apply our custom stream manipulator to the stream.
std::ostream& operator<<(std::ostream& os, const BaseManip& bm)
{
    bm.apply(os);
    return os;
}

// convience function, so we can do std::cout << base(16) << 100;
BaseManip base(int b)
{
    return BaseManip(b);
}

// A custom number output facet.  These are used by the std::locale code in
// streams.  The num_put facet handles the output of numberic values as characters
// in the stream.  Here we create one that knows about our custom manipulator.
struct BaseNumPut : std::num_put<char>
{
    // These absVal functions are needed as std::abs doesnt support 
    // unsigned types, but the templated doPutHelper works on signed and
    // unsigned types.
    unsigned long int absVal(unsigned long int a) const
    {
        return a;
    }

    unsigned long long int absVal(unsigned long long int a) const
    {
        return a;
    }

    template <class NumType>
    NumType absVal(NumType a) const
    {
        return std::abs(a);
    }

    template <class NumType>
    iter_type doPutHelper(iter_type out, std::ios_base& str, char_type fill, NumType val) const
    {
        // Read the value stored in our xalloc location.
        const int base = str.iword(BaseManip::getIWord());

        // we only want this manipulator to affect the next numeric value, so
        // reset its value.
        str.iword(BaseManip::getIWord()) = 0;

        // normal number output, use the built in putter.
        if (base == 0 || base == 10)
        {
            return std::num_put<char>::do_put(out, str, fill, val);
        }

        // We want to conver the base, so do it and output.
        // Base conversion code lifted from Nawaz's answer

        int digits[CHAR_BIT * sizeof(NumType)];
        int i = 0;
        NumType tempVal = absVal(val);

        while (tempVal != 0)
        {
            digits[i++] = tempVal % base;
            tempVal /= base;
        }

        // Get the format flags.
        const std::ios_base::fmtflags flags = str.flags();

        // Add the padding if needs by (i.e. they have used std::setw).
        // Only applies if we are right aligned, or none specified.
        if (flags & std::ios_base::right || 
            !(flags & std::ios_base::internal || flags & std::ios_base::left))
        {
            std::fill_n(out, str.width() - i, fill);
        }

        if (val < 0)
        {
            *out++ = '-';
        }

        // Handle the internal adjustment flag.
        if (flags & std::ios_base::internal)
        {
            std::fill_n(out, str.width() - i, fill);
        }

        char digitCharLc[] = "0123456789abcdefghijklmnopqrstuvwxyz";
        char digitCharUc[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        const char *digitChar = (str.flags() & std::ios_base::uppercase)
            ? digitCharUc
            : digitCharLc;

        while (i)
        {
            // out is an iterator that accepts characters
            *out++ = digitChar[digits[--i]];
        }

        // Add the padding if needs by (i.e. they have used std::setw).
        // Only applies if we are left aligned.
        if (str.flags() & std::ios_base::left)
        {
            std::fill_n(out, str.width() - i, fill);
        }

        // clear the width
        str.width(0);

        return out;
    }

    // Overrides for the virtual do_put member functions.

    iter_type do_put(iter_type out, std::ios_base& str, char_type fill, long val) const
    {
        return doPutHelper(out, str, fill, val);
    }

    iter_type do_put(iter_type out, std::ios_base& str, char_type fill, unsigned long val) const
    {
        return doPutHelper(out, str, fill, val);
    }
};

} // namespace StreamManip

int main()
{
    // Create a local the uses our custom num_put
    std::locale myLocale(std::locale(), new StreamManip::BaseNumPut());

    // Set our locacle to the global one used by default in all streams created 
    // from here on in.  Any streams created in this app will now support the
    // StreamManip::base modifier.
    std::locale::global(myLocale);

    // imbue std::cout, so it uses are custom local.
    std::cout.imbue(myLocale);
    std::cerr.imbue(myLocale);

    // Output some stuff.
    std::cout << std::setw(50) << StreamManip::base(2) << std::internal << -255 << std::endl;
    std::cout << StreamManip::base(4) << 255 << std::endl;
    std::cout << StreamManip::base(8) << 255 << std::endl;
    std::cout << StreamManip::base(10) << 255 << std::endl;
    std::cout << std::uppercase << StreamManip::base(16) << 255 << std::endl;

    return 0;
}

/*
-                                          11111111
3333
377
255
FF
*/
