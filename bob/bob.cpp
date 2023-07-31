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

    std::string upper(const std::string &s) {
        std::string result;
        result.resize(s.length());
        for (size_t i = 0; i < s.length(); i++) {
            result[i] = ::toupper(s[i]);
        }
        return result;
    }

    std::string lower(const std::string &s) {
        std::string result;
        result.resize(s.length());
        for (size_t i = 0; i < s.length(); i++) {
            result[i] = ::tolower(s[i]);
        }
        return result;
    }

    std::string hey(std::string message) {
        std::string s = trim(message);
        std::string upper_s = upper(s);
        std::string lower_s = lower(s);

        bool question = s.find('?') == s.length() - 1;
        bool yelling = (s == upper_s) && (s != lower_s);

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
