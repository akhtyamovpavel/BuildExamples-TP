cc_library(
    name="first_class",
    srcs = ["src/FirstClass.cpp"],
    hdrs = ["src/FirstClass.h"],
    linkstatic = False,
)


cc_binary(
    name = "first_class_main",
    srcs = ["src/main.cpp"],
    deps = [
        ":first_class"
    ],
    linkstatic = True,
)

cc_binary(
    name = "first_class_main_second",
    srcs = ["src/main2.cpp"],
    deps = [
        ":first_class"
    ],
)
