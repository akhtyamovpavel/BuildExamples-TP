load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

cmake(
    name='inicpp',
    lib_source='@inicpp//:all',
    out_shared_libs=['libinicpp.so'],
    out_include_dir='include/inicpp',
    generate_args=["-DINICPP_BUILD_SHARED=ON"],
)

genrule(
    name='copy_configs',
    srcs=['//examples:configs'],
    outs=['examples/config.ini'],
    output_to_bindir=1,
    cmd='mkdir -p examples && cp $(locations //examples:configs) $@'
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

