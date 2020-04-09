load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

cmake_external(
    name='inicpp',
    lib_source='@inicpp//:all',
    static_libraries=['libinicpp_static.a'],
    out_include_dir='include/inicpp',
)

genrule(
    name='copy_configs',
    srcs=['//examples:configs'],
    outs=['examples'],
    output_to_bindir=1,
    cmd='mkdir $@ && cp $(locations //examples:configs) $@'
)

cc_binary(
    name='main',
    srcs=['main.cpp'],
    deps = [
        ":inicpp",
    ],
    data=[
        ':copy_configs',
    ]

)

