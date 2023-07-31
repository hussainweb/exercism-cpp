#include <string>

namespace log_line {
    std::string message(std::string line) {
        size_t pos = line.find(':');
        if (pos == std::string::npos) {
            return "";
        }

        return line.substr(pos + 2);
    }

    std::string log_level(std::string line) {
        size_t pos = line.find(':');
        if (pos == std::string::npos) {
            return "";
        }

        return line.substr(1, pos - 2);
    }

    std::string reformat(std::string line) {
        return message(line) + " (" + log_level(line) + ")";
    }
} // namespace log_line
