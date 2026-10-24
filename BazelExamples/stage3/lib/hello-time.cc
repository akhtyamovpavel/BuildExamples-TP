#include "lib/hello-time.h"

std::string format_build_tag(int lecture_num) {
    return "PromProg-1C-Lecture-" + std::to_string(lecture_num);
}
