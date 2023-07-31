#include "bob.h"

namespace bob {
    const std::string WHITESPACE = " \n\r\t\f\v";

    std::string ltrim(const std::string &s)
    {
        size_t start = s.find_first_not_of(WHITESPACE);
        return (start == std::string::npos) ? "" : s.substr(start);
    }
    
    std::string rtrim(const std::string &s)
    {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }
    
    std::string trim(const std::string &s) {
        return rtrim(ltrim(s));
    }

    std::string hey(std::string message) {
        std::string s = trim(message);
        std::string upper;
        std::string lower;

        bool question = s.find('?') == s.length() - 1;
        upper.resize(s.length());
        std::transform(s.begin(), s.end(), upper.begin(), std::toupper);
        lower.resize(s.length());
        std::transform(s.begin(), s.end(), lower.begin(), std::tolower);
        bool yelling = (s == upper) && (s != lower);

        if (question && yelling) {
            return "Calm down, I know what I'm doing!";
        }
        if (yelling) {
            return "Whoa, chill out!";
        }
        if (s == "") {
            return "Fine. Be that way!";
        }
        if (question) {
            return "Sure.";
        }
        return "Whatever.";
    }
}  // namespace bob
