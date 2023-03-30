load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

cmake(
    name='inicpp',
    lib_source='@inicpp//:all',
    out_static_libs=['libinicpp.a'],
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

