cc_library(
    name="first_class",
    srcs = ["src/FirstClass.cpp"],
    hdrs = ["src/FirstClass.h"],
)


filegroup(
    name = 'libfirst_class',
    srcs = [':first_class'],
    output_group = 'dynamic_library'
)


cc_binary(
    name = "first_class_main",
    srcs = ["src/main.cpp"],
    deps = [
        ":first_class"
    ],
)
