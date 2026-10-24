#include "main/lib_impl.h"
#include "generated_stamp.h"

std::string get_stamped_banner() {
    return std::string("SymbolicMacro[") + GENERATED_BUILD_STAMP + "]";
}
