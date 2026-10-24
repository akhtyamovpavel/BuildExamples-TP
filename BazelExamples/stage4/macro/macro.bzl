# Слайд 11 Block 03.3: Symbolic Macros (Bazel 8+)
def _my_macro_impl(name, visibility, deps, create_test):
    native.cc_library(
        name = name + "_cc_lib",
        srcs = ["lib_impl.cc"],
        hdrs = ["lib_impl.h"],
        deps = deps,
        visibility = visibility,
    )
    if create_test:
        native.cc_test(
            name = name + "_test",
            size = "small",
            srcs = ["my_test.cc"],
            deps = [":" + name + "_cc_lib"] + deps,
        )

my_macro = macro(
    attrs = {
        "deps": attr.label_list(
            mandatory = True,
            doc = "The dependencies passed to the inner cc_library and cc_test targets",
        ),
        "create_test": attr.bool(
            default = False,
            configurable = False,
            doc = "If true, creates a test target",
        ),
    },
    implementation = _my_macro_impl,
)
