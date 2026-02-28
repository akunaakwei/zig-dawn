const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const linkage = b.option(std.builtin.LinkMode, "linkage", "Linkage type for the library") orelse .static;
    const dawn_enable_d3d11 = b.option(bool, "DAWN_ENABLE_D3D11", "Enable compilation of the D3D11 backend") orelse false;
    const dawn_enable_d3d12 = b.option(bool, "DAWN_ENABLE_D3D12", "Enable compilation of the D3D12 backend") orelse false;
    const dawn_enable_d3d = dawn_enable_d3d11 or dawn_enable_d3d12;
    const dawn_enable_metal = b.option(bool, "DAWN_ENABLE_METAL", "Enable compilation of the Metal backend") orelse false;
    const dawn_enable_null = b.option(bool, "DAWN_ENABLE_NULL", "Enable compilation of the Null backend") orelse true;
    const dawn_enable_webgpu_on_webgpu = b.option(bool, "DAWN_ENABLE_WEBGPU_ON_WEBGPU", "Enable compilation of the WebGPU backend") orelse false;
    const dawn_enable_desktop_gl = b.option(bool, "DAWN_ENABLE_DESKTOP_GL", "Enable compilation of the OpenGL backend") orelse false;
    const dawn_enable_opengles = b.option(bool, "DAWN_ENABLE_OPENGLES", "Enable compilation of the OpenGL ES backend") orelse false;
    const dawn_enable_opengl = dawn_enable_desktop_gl or dawn_enable_opengles;
    const dawn_enable_vulkan = b.option(bool, "DAWN_ENABLE_VULKAN", "Enable compilation of the VULKAN backend") orelse false;
    const dawn_enable_spriv_validation = b.option(bool, "DAWN_ENABLE_SPIRV_VALIDATION", "Enable validation of the SPIR-V") orelse false;
    const dawn_force_system_component_load = b.option(bool, "DAWN_FORCE_SYSTEM_COMPONENT_LOAD", "Force system component fallback") orelse false;
    const dawn_use_x11 = b.option(bool, "DAWN_USE_X11", "Enable support for X11 surface") orelse false;
    const dawn_use_wayland = b.option(bool, "DAWN_USE_WAYLAND", "Enable support for Wayland surface") orelse false;
    const dawn_use_windows_ui = b.option(bool, "DAWN_USE_WINDOWS_UI", "Enable support for Windows UI surface") orelse false;

    const tint_build_spirv_reader = b.option(bool, "TINT_BUILD_SPV_READER", "Build the SPIR-V input reader") orelse dawn_enable_vulkan;
    const tint_build_wgsl_reader = b.option(bool, "TINT_BUILD_WGSL_READER", "Build the WGSL input reader") orelse true;
    const tint_build_glsl_writer = b.option(bool, "TINT_BUILD_GLSL_WRITER", "Build the GLSL output writer") orelse dawn_enable_opengl;
    const tint_build_glsl_validator = b.option(bool, "TINT_BUILD_GLSL_VALIDATOR", "Build the GLSL output validator") orelse false;
    const tint_build_hlsl_writer = b.option(bool, "TINT_BUILD_HLSL_WRITER", "Build the HLSL output writer") orelse dawn_enable_d3d12;
    const tint_build_msl_writer = b.option(bool, "TINT_BUILD_MSL_WRITER", "Build the MSL output writer") orelse dawn_enable_metal;
    const tint_build_spirv_writer = b.option(bool, "TINT_BUILD_SPV_WRITER", "Build the SPIR-V output writer") orelse dawn_enable_vulkan;
    const tint_build_wgsl_writer = b.option(bool, "TINT_BUILD_WGSL_WRITER", "Build the WGSL output writer") orelse true;
    const tint_build_null_writer = b.option(bool, "TINT_BUILD_NULL_WRITER", "Build the NULL output writer") orelse dawn_enable_null;
    const tint_build_syntax_tree_writer = b.option(bool, "TINT_BUILD_SYNTAX_TREE_WRITER", "Build the syntax tree writer") orelse false;

    const dawn_dep = b.dependency("dawn", .{});
    const abseil_dep = b.dependency("abseil", .{
        .target = target,
        .optimize = optimize,
    });
    const abseil = abseil_dep.artifact("abseil");

    const maybe_spirv_headers_dep = if (dawn_enable_vulkan) b.lazyDependency("spirv_headers", .{}) else null;
    const maybe_spirv_tools_dep = if (dawn_enable_vulkan) b.lazyDependency("spirv_tools", .{
        .target = target,
        .optimize = optimize,
    }) else null;
    const maybe_vulkan_headers_dep = if (dawn_enable_vulkan) b.lazyDependency("vulkan_headers", .{}) else null;
    const maybe_vulkan_utility_dep = if (dawn_enable_vulkan) b.lazyDependency("vulkan_utility", .{
        .target = target,
        .optimize = optimize,
    }) else null;

    const flags = .{
        "-std=c++20",
        if (optimize == .Debug) "-DDAWN_ENABLE_ASSERTS=1" else "-DDAWN_ENABLE_ASSERTS=0",
        if (dawn_enable_d3d11) "-DDAWN_ENABLE_BACKEND_D3D11=1" else "",
        if (dawn_enable_d3d12) "-DDAWN_ENABLE_BACKEND_D3D12=1" else "",
        if (dawn_enable_metal) "-DDAWN_ENABLE_BACKEND_METAL=1" else "",
        if (dawn_enable_null) "-DDAWN_ENABLE_BACKEND_NULL=1" else "",
        if (dawn_enable_webgpu_on_webgpu) "-DDAWN_ENABLE_BACKEND_WEBGPU=1" else "",
        if (dawn_enable_opengl) "-DDAWN_ENABLE_BACKEND_OPENGL=1" else "",
        if (dawn_enable_desktop_gl) "-DDAWN_ENABLE_BACKEND_DESKTOP_GL=1" else "",
        if (dawn_enable_opengles) "-DDAWN_ENABLE_BACKEND_OPENGLES=1" else "",
        if (dawn_enable_vulkan) "-DDAWN_ENABLE_BACKEND_VULKAN=1" else "",
        if (dawn_use_wayland) "-DDAWN_USE_WAYLAND=1" else "",
        if (dawn_use_x11) "-DDAWN_USE_X11=1" else "",
        if (dawn_use_windows_ui) "-DDAWN_USE_WINDOWS_UI=1" else "",
        if (dawn_force_system_component_load) "-DDAWN_FORCE_SYSTEM_COMPONENT_LOAD=1" else "",
        if (tint_build_spirv_reader) "-DTINT_BUILD_SPV_READER=1" else "-DTINT_BUILD_SPV_READER=0",
        if (tint_build_wgsl_reader) "-DTINT_BUILD_WGSL_READER=1" else "-DTINT_BUILD_WGSL_READER=0",
        if (tint_build_glsl_writer) "-DTINT_BUILD_GLSL_WRITER=1" else "-DTINT_BUILD_GLSL_WRITER=0",
        if (tint_build_glsl_validator) "-DTINT_BUILD_GLSL_VALIDATOR=1" else "-DTINT_BUILD_GLSL_VALIDATOR=0",
        if (tint_build_hlsl_writer) "-DTINT_BUILD_HLSL_WRITER=1" else "-DTINT_BUILD_HLSL_WRITER=0",
        if (tint_build_msl_writer) "-DTINT_BUILD_MSL_WRITER=1" else "-DTINT_BUILD_MSL_WRITER=0",
        if (tint_build_spirv_writer) "-DTINT_BUILD_SPV_WRITER=1" else "-DTINT_BUILD_SPV_WRITER=0",
        if (tint_build_wgsl_writer) "-DTINT_BUILD_WGSL_WRITER=1" else "-DTINT_BUILD_WGSL_WRITER=0",
        if (tint_build_null_writer) "-DTINT_BUILD_NULL_WRITER=1" else "-DTINT_BUILD_NULL_WRITER=0",
        if (tint_build_syntax_tree_writer) "-DTINT_BUILD_SYNTAX_TREE_WRITER=1" else "-DTINT_BUILD_SYNTAX_TREE_WRITER=0",
    };

    const tint_utils = b.addLibrary(.{
        .name = "tint_utils",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    tint_utils.linkLibrary(abseil);
    tint_utils.addIncludePath(dawn_dep.path("."));
    inline for (tint_bytes_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "bytes", src })),
            .flags = &flags,
        });
    }
    inline for (tint_command_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "command", src })),
            .flags = &flags,
        });
    }
    inline for (tint_containers_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "containers", src })),
            .flags = &flags,
        });
    }
    inline for (tint_diagnostic_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "diagnostic", src })),
            .flags = &flags,
        });
    }
    switch (target.result.os.tag) {
        .linux, .ios, .macos, .tvos, .visionos, .watchos => tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "file", "tmpfile_posix.cc" })),
            .flags = &flags,
        }),
        .windows => tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "file", "tmpfile_windows.cc" })),
            // on mingw some macros are defined in sys/stat.h and share.h
            .flags = &(flags ++ .{ "-includesys/stat.h", "-includeshare.h" }),
        }),
        else => tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "file", "tmpfile_other.cc" })),
            .flags = &flags,
        }),
    }
    inline for (tint_ice_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "ice", src })),
            .flags = &flags,
        });
    }
    inline for (tint_macros_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "macros", src })),
            .flags = &flags,
        });
    }
    inline for (tint_math_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "math", src })),
            .flags = &flags,
        });
    }
    inline for (tint_memory_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "memory", src })),
            .flags = &flags,
        });
    }
    inline for (tint_rtti_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "rtti", src })),
            .flags = &flags,
        });
    }
    inline for (tint_strconv_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "strconv", src })),
            .flags = &flags,
        });
    }
    inline for (tint_symbol_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "symbol", src })),
            .flags = &flags,
        });
    }
    switch (target.result.os.tag) {
        .linux => tint_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/tint/utils/system"),
            .files = &.{ "env_other.cc", "executable_path_linux.cc", "terminal_posix.cc" },
            .flags = &flags,
        }),
        .ios, .macos, .tvos, .visionos, .watchos => tint_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/tint/utils/system"),
            .files = &.{ "env_other.cc", "executable_file_mac.cc", "terminal_posix.cc" },
            .flags = &flags,
        }),
        .windows => tint_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/tint/utils/system"),
            .files = &.{ "env_windows.cc", "executable_path_windows.cc", "terminal_windows.cc" },
            .flags = &flags,
        }),
        else => tint_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/tint/utils/system"),
            .files = &.{ "env_other.cc", "terminal_other.cc" },
            .flags = &flags,
        }),
    }
    inline for (tint_text_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "text", src })),
            .flags = &flags,
        });
    }
    switch (target.result.os.tag) {
        .linux, .ios, .macos, .tvos, .visionos, .watchos => tint_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/tint/utils/text"),
            .files = &.{"styled_text_printer_posix.cc"},
            .flags = &flags,
        }),

        .windows => tint_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/tint/utils/text"),
            .files = &.{"styled_text_printer_windows.cc"},
            .flags = &flags,
        }),
        else => tint_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/tint/utils/text"),
            .files = &.{"styled_text_printer_other.cc"},
            .flags = &flags,
        }),
    }
    inline for (tint_text_generator_sources) |src| {
        tint_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "utils", "text_generator", src })),
            .flags = &flags,
        });
    }
    tint_utils.addCSourceFiles(.{
        .root = dawn_dep.path("src/tint/utils"),
        .files = &.{
            "reflection.cc",
            "result.cc",
        },
        .flags = &flags,
    });

    const tint_core = b.addLibrary(.{
        .name = "tint_core",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    tint_core.linkLibrary(tint_utils);
    tint_core.addIncludePath(dawn_dep.path("."));
    inline for (tint_core_constant_sources) |src| {
        tint_core.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "core", "constant", src })),
            .flags = &flags,
        });
    }
    inline for (tint_core_intrinsic_sources) |src| {
        tint_core.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "core", "intrinsic", src })),
            .flags = &flags,
        });
    }
    inline for (tint_core_ir_sources) |src| {
        tint_core.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "core", "ir", src })),
            .flags = &flags,
        });
    }
    inline for (tint_core_type_sources) |src| {
        tint_core.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "core", "type", src })),
            .flags = &flags,
        });
    }
    tint_core.addCSourceFiles(.{
        .root = dawn_dep.path("src/tint/lang/core"),
        .files = &.{
            "binary_op.cc",
            "enums.cc",
            "number.cc",
            "unary_op.cc",
        },
        .flags = &flags,
    });

    const tint_wgsl = b.addLibrary(.{
        .name = "tint_wgsl",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    tint_wgsl.linkLibrary(tint_utils);
    tint_wgsl.addIncludePath(dawn_dep.path("."));
    inline for (tint_wgsl_ast_sources) |src| {
        tint_wgsl.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "ast", src })),
            .flags = &flags,
        });
    }
    inline for (tint_wgsl_inspector_sources) |src| {
        tint_wgsl.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "inspector", src })),
            .flags = &flags,
        });
    }
    inline for (tint_wgsl_intrinsic_sources) |src| {
        tint_wgsl.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "intrinsic", src })),
            .flags = &flags,
        });
    }
    inline for (tint_wgsl_ir_sources) |src| {
        tint_wgsl.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "ir", src })),
            .flags = &flags,
        });
    }
    // inline for (tint_wgsl_ls_sources) |src| {
    //     tint_wgsl.addCSourceFile(.{
    //         .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "ls", src })),
    //         .flags = &flags,
    //     });
    // }
    inline for (tint_wgsl_program_sources) |src| {
        tint_wgsl.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "program", src })),
            .flags = &flags,
        });
    }
    inline for (tint_wgsl_reader_sources) |src| {
        tint_wgsl.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "reader", src })),
            .flags = &flags,
        });
    }
    inline for (tint_wgsl_resolver_sources) |src| {
        tint_wgsl.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "resolver", src })),
            .flags = &flags,
        });
    }
    inline for (tint_wgsl_sem_sources) |src| {
        tint_wgsl.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "sem", src })),
            .flags = &flags,
        });
    }
    inline for (tint_wgsl_writer_sources) |src| {
        tint_wgsl.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "wgsl", "writer", src })),
            .flags = &flags,
        });
    }
    tint_wgsl.addCSourceFiles(.{
        .root = dawn_dep.path("src/tint/lang/wgsl"),
        .files = &.{
            "enums.cc",
            "feature_status.cc",
            "reserved_words.cc",
        },
        .flags = &flags,
    });

    const tint_hlsl = b.addLibrary(.{
        .name = "tint_hlsl",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    tint_hlsl.linkLibrary(tint_utils);
    tint_hlsl.addIncludePath(dawn_dep.path("."));
    tint_hlsl.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "hlsl", "intrinsic" })),
        .files = &tint_hlsl_intrinsic_sources,
        .flags = &flags,
    });
    tint_hlsl.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "hlsl", "ir" })),
        .files = &tint_hlsl_ir_sources,
        .flags = &flags,
    });
    tint_hlsl.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "hlsl", "type" })),
        .files = &tint_hlsl_type_sources,
        .flags = &flags,
    });
    tint_hlsl.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "hlsl", "validate" })),
        .files = &tint_hlsl_validate_sources,
        .flags = &flags,
    });

    if (tint_build_hlsl_writer) {
        tint_hlsl.addCSourceFiles(.{
            .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "hlsl", "writer" })),
            .files = &tint_hlsl_writer_sources,
            .flags = &flags,
        });
    }

    const tint_spirv = b.addLibrary(.{
        .name = "tint_spirv",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    tint_spirv.linkLibrary(tint_utils);
    tint_spirv.addIncludePath(dawn_dep.path("."));
    if (maybe_spirv_headers_dep) |spirv_headers_dep| {
        tint_spirv.addIncludePath(spirv_headers_dep.path("include"));
    }
    if (maybe_spirv_tools_dep) |spirv_tools_dep| {
        tint_spirv.addIncludePath(spirv_tools_dep.namedLazyPath("root"));
        tint_spirv.linkLibrary(spirv_tools_dep.artifact("spvtools"));
    }
    tint_spirv.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "spirv", "intrinsic" })),
        .files = &tint_spirv_intrinsic_sources,
        .flags = &flags,
    });
    tint_spirv.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "spirv", "ir" })),
        .files = &tint_spirv_ir_sources,
        .flags = &flags,
    });
    if (tint_build_spirv_reader) {
        tint_spirv.addCSourceFiles(.{
            .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "spirv", "reader" })),
            .files = &tint_spirv_reader_sources,
            .flags = &flags,
        });
    }
    tint_spirv.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "spirv", "type" })),
        .files = &tint_spirv_type_sources,
        .flags = &flags,
    });
    tint_spirv.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "spirv", "validate" })),
        .files = &tint_spirv_validate_sources,
        .flags = &flags,
    });
    if (tint_build_spirv_writer) {
        tint_spirv.addCSourceFiles(.{
            .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "spirv", "writer" })),
            .files = &tint_spirv_writer_sources,
            .flags = &flags,
        });
    }
    tint_spirv.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "spirv" })),
        .files = &.{
            "builtin_fn.cc",
        },
        .flags = &flags,
    });

    const tint_null = b.addLibrary(.{
        .name = "tint_null",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    tint_null.linkLibrary(tint_utils);
    tint_null.addIncludePath(dawn_dep.path("."));
    tint_null.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "tint", "lang", "null", "writer" })),
        .files = &tint_null_writer_sources,
        .flags = &flags,
    });

    const tint_api = b.addLibrary(.{
        .name = "tint_api",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    tint_api.linkLibrary(tint_utils);
    tint_api.addIncludePath(dawn_dep.path("."));
    tint_api.addCSourceFiles(.{
        .root = dawn_dep.path("src/tint/api"),
        .files = &.{"tint.cc"},
        .flags = &flags,
    });
    tint_api.addCSourceFiles(.{
        .root = dawn_dep.path("src/tint/api/common"),
        .files = &.{"vertex_pulling_config.cc"},
        .flags = &flags,
    });
    tint_api.addCSourceFiles(.{
        .root = dawn_dep.path("src/tint/api/helpers"),
        .files = &.{"generate_bindings.cc"},
        .flags = &flags,
    });

    const tint_exe = b.addExecutable(.{
        .name = "tint",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    tint_exe.linkLibrary(tint_utils);
    tint_exe.linkLibrary(tint_api);
    tint_exe.linkLibrary(tint_core);
    tint_exe.linkLibrary(tint_wgsl);
    if (maybe_spirv_tools_dep) |spirv_tools_dep| {
        tint_exe.linkLibrary(tint_spirv);
        tint_exe.linkLibrary(spirv_tools_dep.artifact("spvtools"));
    }
    tint_exe.linkLibrary(tint_null);
    tint_exe.addIncludePath(dawn_dep.path("."));
    tint_exe.addCSourceFiles(.{
        .root = dawn_dep.path("src/tint/cmd"),
        .files = &.{
            "common/helper.cc",
            "tint/main.cc",
        },
        .flags = &flags,
    });
    b.installArtifact(tint_exe);

    const dawn_common = b.addLibrary(.{
        .name = "dawn_common",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    dawn_common.linkLibrary(abseil);
    dawn_common.addIncludePath(dawn_dep.path("."));
    dawn_common.addIncludePath(dawn_dep.path("include"));
    dawn_common.addIncludePath(dawn_dep.path("src"));
    dawn_common.addIncludePath(dawn_dep.path("src/dawn/partition_alloc"));
    dawn_common.addIncludePath(b.path("include"));
    dawn_common.addIncludePath(b.path("src"));
    inline for (dawn_common_sources) |src| {
        dawn_common.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "common", src })),
            .flags = &flags,
        });
    }
    switch (target.result.os.tag) {
        .ios, .tvos, .visionos, .watchos => dawn_common.addCSourceFile(.{
            .file = dawn_dep.path("src/dawn/common/IOSurfaceUtils.cpp"),
            .flags = &flags,
        }),
        .macos => dawn_common.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/common"),
            .files = &.{ "IOSurfaceUtils.cpp", "SystemUtils_mac.mm" },
            .flags = &flags,
        }),
        .windows => dawn_common.addCSourceFile(.{
            .file = dawn_dep.path("src/dawn/common/WindowsUtils.cpp"),
            .flags = &flags,
        }),
        else => {},
    }
    dawn_common.addCSourceFile(.{
        .file = b.path("src/dawn/common/GPUInfo_autogen.cpp"),
        .flags = &flags,
    });

    const wgpu_utils = b.addLibrary(.{
        .name = "dawn_wgpu_utils",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    wgpu_utils.linkLibrary(abseil);
    wgpu_utils.linkLibrary(dawn_common);
    wgpu_utils.addIncludePath(dawn_dep.path("."));
    wgpu_utils.addIncludePath(dawn_dep.path("include"));
    wgpu_utils.addIncludePath(dawn_dep.path("src"));
    wgpu_utils.addIncludePath(dawn_dep.path("src/dawn/partition_alloc"));
    wgpu_utils.addIncludePath(b.path("include"));
    wgpu_utils.addIncludePath(b.path("src"));
    if (maybe_spirv_tools_dep) |spirv_toosl_dep| {
        wgpu_utils.linkLibrary(spirv_toosl_dep.artifact("spvtools"));
    }
    inline for (dawn_wgpu_utils_sources) |src| {
        wgpu_utils.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "utils", src })),
            .flags = &flags,
        });
    }
    wgpu_utils.addCSourceFile(.{
        .file = b.path("src/dawn/utils/ComboLimits.cpp"),
        .flags = &flags,
    });

    const platform = b.addLibrary(.{
        .name = "dawn_platform",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    platform.linkLibrary(dawn_common);
    platform.addIncludePath(dawn_dep.path("."));
    platform.addIncludePath(dawn_dep.path("include"));
    platform.addIncludePath(dawn_dep.path("src"));
    platform.addIncludePath(dawn_dep.path("src/dawn/partition_alloc"));
    platform.addIncludePath(b.path("include"));
    platform.addIncludePath(b.path("src"));
    inline for (dawn_platform_sources) |src| {
        platform.addCSourceFile(.{
            .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "platform", src })),
            .flags = &flags,
        });
    }

    const native_utils = b.addLibrary(.{
        .name = "dawn_native_utils",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    native_utils.linkLibrary(abseil);
    native_utils.addIncludePath(dawn_dep.path("."));
    native_utils.addIncludePath(dawn_dep.path("include"));
    native_utils.addIncludePath(dawn_dep.path("src"));
    native_utils.addIncludePath(dawn_dep.path("src/dawn/partition_alloc"));
    native_utils.addIncludePath(b.path("include"));
    native_utils.addIncludePath(b.path("src"));

    native_utils.addCSourceFiles(.{
        .root = b.path("src/dawn/native"),
        .files = &native_utils_sources,
        .flags = &flags,
    });

    const system_utils = b.addLibrary(.{
        .name = "system_utils",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    system_utils.linkLibrary(abseil);
    system_utils.addIncludePath(dawn_dep.path("."));
    system_utils.addIncludePath(dawn_dep.path("include"));
    system_utils.addIncludePath(dawn_dep.path("src"));
    system_utils.addIncludePath(dawn_dep.path("src/dawn/partition_alloc"));
    system_utils.addIncludePath(b.path("include"));
    system_utils.addIncludePath(b.path("src"));
    system_utils.addCSourceFiles(.{
        .root = dawn_dep.path("src/dawn/utils"),
        .files = &.{
            "CommandLineParser.cpp",
            "SystemHandle.cpp",
            "SystemUtils.cpp",
        },
        .flags = &flags,
    });
    if (target.result.os.tag == .windows) {
        system_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/utils"),
            .files = &.{
                "WindowsDebugLogger.cpp",
            },
            .flags = &flags,
        });
    } else {
        system_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/utils"),
            .files = &.{
                "EmptyDebugLogger.cpp",
            },
            .flags = &flags,
        });
    }
    switch (target.result.os.tag) {
        .windows => system_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/utils"),
            .files = &.{
                "WindowsTimer.cpp",
            },
            .flags = &flags,
        }),
        .linux => system_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/utils"),
            .files = &.{
                "PosixTimer.cpp",
            },
            .flags = &flags,
        }),
        .macos, .ios, .watchos, .tvos => system_utils.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/utils"),
            .files = &.{
                "OSXTimer.cpp",
                "ObjCUtils.mm",
            },
            .flags = &flags,
        }),
        else => {},
    }

    const proc = b.addLibrary(.{
        .name = "dawn_proc",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    proc.addIncludePath(dawn_dep.path("."));
    proc.addIncludePath(dawn_dep.path("include"));
    proc.addIncludePath(dawn_dep.path("src"));
    proc.addIncludePath(dawn_dep.path("src/dawn/partition_alloc"));
    proc.addIncludePath(b.path("include"));
    proc.addIncludePath(b.path("src"));
    proc.addCSourceFiles(.{
        .root = b.path("src/dawn"),
        .files = &.{
            "dawn_proc.cpp",
            "dawn_thread_dispatch_proc.cpp",
        },
        .flags = &flags,
    });

    const native = b.addLibrary(.{
        .name = "dawn_native",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    native.linkLibrary(abseil);
    native.linkLibrary(tint_core);
    native.linkLibrary(tint_api);
    native.linkLibrary(tint_wgsl);
    if (dawn_enable_d3d) {
        native.linkLibrary(tint_hlsl);
    }
    if (dawn_enable_vulkan) {
        native.linkLibrary(tint_spirv);
    }
    if (dawn_enable_null) {
        native.linkLibrary(tint_null);
    }
    native.linkLibrary(dawn_common);
    native.linkLibrary(platform);
    native.linkLibrary(native_utils);
    native.linkLibrary(proc);
    native.linkLibrary(wgpu_utils);
    native.linkLibrary(system_utils);
    if (target.result.os.tag == .windows) {
        native.linkSystemLibrary("user32");
        native.linkSystemLibrary("delayimp");
    }
    native.addIncludePath(dawn_dep.path("."));
    native.addIncludePath(dawn_dep.path("include"));
    native.addIncludePath(dawn_dep.path("src"));
    native.addIncludePath(dawn_dep.path("src/dawn/partition_alloc"));
    native.addIncludePath(b.path("include"));
    native.addIncludePath(b.path("src"));
    if (maybe_spirv_tools_dep) |spirv_tools_dep| {
        native.linkLibrary(spirv_tools_dep.artifact("spvtools"));
    }
    if (maybe_vulkan_headers_dep) |vulkan_headers_dep| {
        native.addIncludePath(vulkan_headers_dep.path("include"));
    }
    if (maybe_vulkan_utility_dep) |vulkan_utility_dep| {
        native.linkLibrary(vulkan_utility_dep.artifact("VulkanUtility"));
    }

    native.addCSourceFiles(.{
        .root = dawn_dep.path("src/dawn/native"),
        .files = &.{"DawnNative.cpp"},
        .flags = &flags,
    });
    native.addCSourceFiles(.{
        .root = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "native" })),
        .files = &dawn_sources,
        .flags = &flags,
    });

    if (dawn_use_x11) {
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"X11Functions.cpp"},
            .flags = &flags,
        });
    }
    if (target.result.abi.isAndroid()) {
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"AHBFunctions.cpp"},
            .flags = &flags,
        });
    }

    if (dawn_enable_d3d) {
        inline for (dawn_d3d_sources) |src| {
            native.addCSourceFile(.{
                .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "native", src })),
                .flags = &flags,
            });
        }
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"d3d/D3DBackend.cpp"},
            .flags = &flags,
        });
    }

    if (dawn_enable_d3d11) {
        native.linkSystemLibrary("dxguid");
        inline for (dawn_d3d11_sources) |src| {
            native.addCSourceFile(.{
                .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "native", src })),
                .flags = &flags,
            });
        }
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"d3d11/D3D11Backend.cpp"},
            .flags = &flags,
        });
    }

    if (dawn_enable_d3d12) {
        native.linkSystemLibrary("dxguid");
        inline for (dawn_d3d12_sources) |src| {
            native.addCSourceFile(.{
                .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "native", src })),
                .flags = &flags,
            });
        }
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"d3d12/D3D12Backend.cpp"},
            .flags = &flags,
        });
    }

    if (dawn_enable_metal) {
        native.linkFramework("IOSurface");
        native.linkFramework("Metal");
        native.linkFramework("QuartzCore");
        if (target.result.os.tag == .macos) {
            native.linkFramework("Cocoa");
            native.linkFramework("IOKit");
        }
        inline for (dawn_metal_sources) |src| {
            native.addCSourceFile(.{
                .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "native", src })),
                .flags = &flags,
            });
        }
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"metal/MetalBackend.mm"},
            .flags = &flags,
        });
    }

    if (dawn_enable_null) {
        inline for (dawn_null_sources) |src| {
            native.addCSourceFile(.{
                .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "native", src })),
                .flags = &flags,
            });
        }
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"null/NullBackend.cpp"},
            .flags = &flags,
        });
    }

    if (dawn_enable_webgpu_on_webgpu) {
        inline for (dawn_webgpu_sources) |src| {
            native.addCSourceFile(.{
                .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "native", src })),
                .flags = &flags,
            });
        }
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"webgpu/WebGPUBackend.cpp"},
            .flags = &flags,
        });
    }

    if ((dawn_enable_opengl or dawn_enable_vulkan) and dawn_enable_spriv_validation) {
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"SpirvValidation.cpp"},
            .flags = &flags,
        });
    }

    if (dawn_enable_opengl) {
        inline for (dawn_opengl_sources) |src| {
            native.addCSourceFile(.{
                .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "native", src })),
                .flags = &flags,
            });
        }
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"opengl/OpenGLBackend.cpp"},
            .flags = &flags,
        });
    }

    if (dawn_enable_vulkan) {
        inline for (dawn_vulkan_sources) |src| {
            native.addCSourceFile(.{
                .file = dawn_dep.path(b.pathJoin(&.{ "src", "dawn", "native", src })),
                .flags = &flags,
            });
        }
        native.addCSourceFiles(.{
            .root = dawn_dep.path("src/dawn/native"),
            .files = &.{"vulkan/VulkanBackend.cpp"},
            .flags = &flags,
        });

        if (target.result.os.tag == .linux or target.result.abi.isAndroid()) {
            native.addCSourceFiles(.{
                .root = dawn_dep.path("src/dawn/native"),
                .files = &.{"vulkan/external_semaphore/SemaphoreServiceImplementationFD.cpp"},
                .flags = &flags,
            });

            if (target.result.abi.isAndroid()) {
                native.addCSourceFiles(.{
                    .root = dawn_dep.path("src/dawn/native"),
                    .files = &.{"vulkan/external_memory/MemoryServiceImplementationAHardwareBuffer.cpp"},
                    .flags = &flags,
                });
            }

            if (target.result.os.tag == .linux) {
                native.addCSourceFiles(.{
                    .root = dawn_dep.path("src/dawn/native"),
                    .files = &.{
                        "vulkan/external_memory/MemoryServiceImplementationDmaBuf.cpp",
                        "vulkan/external_memory/MemoryServiceImplementationOpaqueFD.cpp",
                    },
                    .flags = &flags,
                });
            }
        }
    }
    native.installHeadersDirectory(b.path("include"), ".", .{});
    // b.installArtifact(native);

    const webgpu_dawn = b.addLibrary(.{
        .name = "webgpu_dawn",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
        .linkage = linkage,
    });
    webgpu_dawn.linkLibrary(native);
    webgpu_dawn.addIncludePath(b.path("include"));
    webgpu_dawn.addIncludePath(b.path("src"));
    webgpu_dawn.addIncludePath(dawn_dep.path("include"));
    webgpu_dawn.addIncludePath(dawn_dep.path("src"));
    webgpu_dawn.addCSourceFiles(.{
        .root = b.path("src/dawn/native"),
        .files = &.{"webgpu_dawn_native_proc.cpp"},
        .flags = &flags,
    });
    webgpu_dawn.installHeader(b.path("webgpu-headers/webgpu.h"), "webgpu/webgpu.h");
    b.installArtifact(webgpu_dawn);

    const translate_webgpu = b.addTranslateC(.{
        .root_source_file = b.path("include/dawn/webgpu.h"),
        .target = target,
        .optimize = optimize,
    });
    translate_webgpu.addIncludePath(b.path("include"));
    translate_webgpu.addIncludePath(dawn_dep.path("include"));

    const webgpu_mod = translate_webgpu.addModule("webgpu");
    webgpu_mod.linkLibrary(webgpu_dawn);

    const glfw_dep = b.dependency("glfw", .{
        .target = target,
        .optimize = optimize,
    });
    const glfw = glfw_dep.artifact("glfw3");

    const dawn_glfw = b.addLibrary(.{
        .name = "dawn_glfw",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    dawn_glfw.linkLibrary(glfw);
    dawn_glfw.addIncludePath(dawn_dep.path("include"));
    dawn_glfw.addIncludePath(dawn_dep.path("src"));
    dawn_glfw.addIncludePath(b.path("include"));
    dawn_glfw.addCSourceFiles(.{
        .root = dawn_dep.path("src/dawn/glfw"),
        .files = &.{
            "utils.cpp",
        },
        .flags = &flags,
    });

    const sample_utils = b.addLibrary(.{
        .name = "sample_utils",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    sample_utils.linkLibrary(glfw);
    sample_utils.linkLibrary(dawn_glfw);
    sample_utils.linkLibrary(abseil);
    sample_utils.addIncludePath(dawn_dep.path("."));
    sample_utils.addIncludePath(dawn_dep.path("include"));
    sample_utils.addIncludePath(dawn_dep.path("src"));
    sample_utils.addIncludePath(dawn_dep.path("src/dawn/partition_alloc"));
    sample_utils.addIncludePath(b.path("include"));
    sample_utils.addIncludePath(b.path("src"));
    sample_utils.addCSourceFiles(.{
        .root = dawn_dep.path("src/dawn/samples"),
        .files = &.{"SampleUtils.cpp"},
        .flags = &flags,
    });

    const hello_triangle = b.addExecutable(.{
        .name = "HelloTriangle",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libcpp = true,
        }),
    });
    hello_triangle.linkLibrary(sample_utils);
    hello_triangle.linkLibrary(native);
    hello_triangle.linkLibrary(glfw);
    hello_triangle.linkLibrary(abseil);
    hello_triangle.addIncludePath(dawn_dep.path("."));
    hello_triangle.addIncludePath(dawn_dep.path("include"));
    hello_triangle.addIncludePath(dawn_dep.path("src"));
    hello_triangle.addIncludePath(dawn_dep.path("src/dawn/partition_alloc"));
    hello_triangle.addIncludePath(b.path("include"));
    hello_triangle.addIncludePath(b.path("src"));
    hello_triangle.addCSourceFiles(.{
        .root = dawn_dep.path("src/dawn/samples"),
        .files = &.{"HelloTriangle.cpp"},
        .flags = &flags,
    });
    const hello_triangle_install = b.addInstallArtifact(hello_triangle, .{});

    const sample_step = b.step("sample", "build samples");
    sample_step.dependOn(&hello_triangle_install.step);

    const json_generator_cmd = b.addSystemCommand(&.{"python3"});
    json_generator_cmd.addFileArg(dawn_dep.path("generator/dawn_json_generator.py"));
    json_generator_cmd.addPrefixedDirectoryArg("--template-dir=", dawn_dep.path("generator/templates"));
    json_generator_cmd.addPrefixedFileArg("--dawn-json=", dawn_dep.path("src/dawn/dawn.json"));
    json_generator_cmd.addPrefixedFileArg("--wire-json=", dawn_dep.path("src/dawn/dawn_wire.json"));
    json_generator_cmd.addArg("--targets=headers,dawn_headers,cpp_headers,webgpu_headers,native_utils,dawn_utils,proc,webgpu_dawn_native_proc");
    json_generator_cmd.addPrefixedDirectoryArg("--output-dir=", b.path("."));

    const gpu_info_generator_cmd = b.addSystemCommand(&.{"python3"});
    gpu_info_generator_cmd.addFileArg(dawn_dep.path("generator/dawn_gpu_info_generator.py"));
    gpu_info_generator_cmd.addPrefixedFileArg("--gpu-info-json=", dawn_dep.path("src/dawn/gpu_info.json"));
    gpu_info_generator_cmd.addPrefixedDirectoryArg("--template-dir=", dawn_dep.path("generator/templates"));
    gpu_info_generator_cmd.addPrefixedDirectoryArg("--output-dir=", b.path("."));

    const version_wf = b.addWriteFiles();
    const version_generator_cmd = b.addSystemCommand(&.{"python3"});
    version_generator_cmd.addFileArg(dawn_dep.path("generator/dawn_version_generator.py"));
    version_generator_cmd.addPrefixedDirectoryArg("--template-dir=", dawn_dep.path("generator/templates"));
    version_generator_cmd.addPrefixedDirectoryArg("--output-dir=", b.path("."));
    version_generator_cmd.addPrefixedDirectoryArg("--version-file=", version_wf.add("version", "8f8a423b832b3f573c2281e005e3d24252259db2"));
    version_generator_cmd.addPrefixedDirectoryArg("--dawn-dir=", dawn_dep.path("."));

    const gen_step = b.step("gen", "run the code generators");
    gen_step.dependOn(&json_generator_cmd.step);
    gen_step.dependOn(&gpu_info_generator_cmd.step);
    gen_step.dependOn(&version_generator_cmd.step);
}

const tint_bytes_sources = .{
    "buffer_reader.cc",
    "reader.cc",
};

const tint_command_sources = .{
    "args.cc",
    "cli.cc",
};

const tint_containers_sources = .{
    "containers.cc",
};

const tint_diagnostic_sources = .{
    "diagnostic.cc",
    "formatter.cc",
    "source.cc",
};

const tint_ice_sources = .{
    "debugger.cc",
    "ice.cc",
};

const tint_macros_sources = .{
    "macros.cc",
};

const tint_math_sources = .{
    "math.cc",
};

const tint_memory_sources = .{
    "memory.cc",
};

const tint_rtti_sources = .{
    "castable.cc",
    "switch.cc",
};

const tint_strconv_sources = .{
    "float_to_string.cc",
    "parse_num.cc",
};

const tint_symbol_sources = .{
    "generation_id.cc",
    "symbol.cc",
    "symbol_table.cc",
};

const tint_text_sources = .{
    "base64.cc",
    "color_mode.cc",
    "string.cc",
    "string_stream.cc",
    "styled_text.cc",
    "styled_text_printer.cc",
    "styled_text_printer_ansi.cc",
    "styled_text_theme.cc",
    "unicode.cc",
};

const tint_text_generator_sources = .{
    "text_generator.cc",
};

const tint_core_constant_sources = .{
    "composite.cc",
    "eval.cc",
    "invalid.cc",
    "manager.cc",
    "node.cc",
    "scalar.cc",
    "splat.cc",
    "string.cc",
    "value.cc",
};

const tint_core_intrinsic_sources = .{
    "ctor_conv.cc",
    "data.cc",
    "table.cc",
};

const tint_core_ir_sources = .{
    "access.cc",
    "binary.cc",
    "bitcast.cc",
    "block.cc",
    "block_param.cc",
    "break_if.cc",
    "builder.cc",
    "builtin_call.cc",
    "call.cc",
    "clone_context.cc",
    "const_param_validator.cc",
    "constant.cc",
    "constexpr_if.cc",
    "construct.cc",
    "continue.cc",
    "control_instruction.cc",
    "convert.cc",
    "core_binary.cc",
    "core_builtin_call.cc",
    "core_unary.cc",
    "disassembler.cc",
    "discard.cc",
    "evaluator.cc",
    "exit.cc",
    "exit_if.cc",
    "exit_loop.cc",
    "exit_switch.cc",
    "function.cc",
    "function_param.cc",
    "if.cc",
    "instruction.cc",
    "instruction_result.cc",
    "let.cc",
    "load.cc",
    "load_vector_element.cc",
    "loop.cc",
    "member_builtin_call.cc",
    "module.cc",
    "multi_in_block.cc",
    "next_iteration.cc",
    "operand_instruction.cc",
    "override.cc",
    "phony.cc",
    "reflection.cc",
    "return.cc",
    "store.cc",
    "store_vector_element.cc",
    "switch.cc",
    "swizzle.cc",
    "terminate_invocation.cc",
    "terminator.cc",
    "unary.cc",
    "unreachable.cc",
    "unused.cc",
    "user_call.cc",
    "validator.cc",
    "value.cc",
    "var.cc",
    "analysis/for_loop_analysis.cc",
    "analysis/integer_range_analysis.cc",
    "analysis/loop_analysis.cc",
    "analysis/subgroup_matrix.cc",
    // "binary/decode.cc",
    // "binary/encode.cc",
    "transform/array_length_from_immediate.cc",
    "transform/array_length_from_uniform.cc",
    "transform/bgra8unorm_polyfill.cc",
    "transform/binary_polyfill.cc",
    "transform/binding_remapper.cc",
    "transform/block_decorated_structs.cc",
    "transform/builtin_polyfill.cc",
    "transform/builtin_scalarize.cc",
    "transform/change_immediate_to_uniform.cc",
    "transform/combine_access_instructions.cc",
    "transform/conversion_polyfill.cc",
    "transform/dead_code_elimination.cc",
    "transform/decompose_access.cc",
    "transform/demote_to_helper.cc",
    "transform/direct_variable_access.cc",
    "transform/multiplanar_external_texture.cc",
    "transform/prepare_immediate_data.cc",
    "transform/preserve_padding.cc",
    "transform/prevent_infinite_loops.cc",
    "transform/remove_continue_in_switch.cc",
    "transform/remove_terminator_args.cc",
    "transform/remove_uniform_vector_component_loads.cc",
    "transform/rename_conflicts.cc",
    "transform/resource_table.cc",
    "transform/resource_table_helper.cc",
    "transform/robustness.cc",
    "transform/shader_io.cc",
    "transform/signed_integer_polyfill.cc",
    "transform/single_entry_point.cc",
    "transform/std140.cc",
    "transform/substitute_overrides.cc",
    "transform/value_to_let.cc",
    "transform/vectorize_scalar_matrix_constructors.cc",
    "transform/vertex_pulling.cc",
    "transform/zero_init_workgroup_memory.cc",
    "type/array_count.cc",
};

const tint_core_type_sources = .{
    "abstract_float.cc",
    "abstract_int.cc",
    "abstract_numeric.cc",
    "array.cc",
    "array_count.cc",
    "atomic.cc",
    "binding_array.cc",
    "bool.cc",
    "buffer.cc",
    "builtin_structs.cc",
    "depth_multisampled_texture.cc",
    "depth_texture.cc",
    "external_texture.cc",
    "f16.cc",
    "f32.cc",
    "function.cc",
    "i32.cc",
    "i8.cc",
    "input_attachment.cc",
    "invalid.cc",
    "manager.cc",
    "matrix.cc",
    "memory_view.cc",
    "multisampled_texture.cc",
    "node.cc",
    "numeric_scalar.cc",
    "pointer.cc",
    "reference.cc",
    "resource_table.cc",
    "resource_type.cc",
    "sampled_texture.cc",
    "sampler.cc",
    "sampler_kind.cc",
    "scalar.cc",
    "storage_texture.cc",
    "string.cc",
    "struct.cc",
    "subgroup_matrix.cc",
    "swizzle_view.cc",
    "texel_buffer.cc",
    "texture.cc",
    "texture_dimension.cc",
    "type.cc",
    "u16.cc",
    "u32.cc",
    "u64.cc",
    "u8.cc",
    "unique_node.cc",
    "vector.cc",
    "void.cc",
};

const tint_wgsl_ast_sources = .{
    "accessor_expression.cc",
    "alias.cc",
    "assignment_statement.cc",
    "attribute.cc",
    "binary_expression.cc",
    "binding_attribute.cc",
    "blend_src_attribute.cc",
    "block_statement.cc",
    "bool_literal_expression.cc",
    "break_if_statement.cc",
    "break_statement.cc",
    "builder.cc",
    "builtin_attribute.cc",
    "call_expression.cc",
    "call_statement.cc",
    "case_selector.cc",
    "case_statement.cc",
    "color_attribute.cc",
    "compound_assignment_statement.cc",
    "const.cc",
    "const_assert.cc",
    "continue_statement.cc",
    "diagnostic_attribute.cc",
    "diagnostic_control.cc",
    "diagnostic_directive.cc",
    "diagnostic_rule_name.cc",
    "discard_statement.cc",
    "enable.cc",
    "expression.cc",
    "extension.cc",
    "float_literal_expression.cc",
    "for_loop_statement.cc",
    "function.cc",
    "group_attribute.cc",
    "id_attribute.cc",
    "identifier.cc",
    "identifier_expression.cc",
    "if_statement.cc",
    "increment_decrement_statement.cc",
    "index_accessor_expression.cc",
    "input_attachment_index_attribute.cc",
    "int_literal_expression.cc",
    "interpolate_attribute.cc",
    "invariant_attribute.cc",
    "let.cc",
    "literal_expression.cc",
    "location_attribute.cc",
    "loop_statement.cc",
    "member_accessor_expression.cc",
    "module.cc",
    "must_use_attribute.cc",
    "node.cc",
    "override.cc",
    "parameter.cc",
    "phony_expression.cc",
    "pipeline_stage.cc",
    "requires.cc",
    "return_statement.cc",
    "stage_attribute.cc",
    "statement.cc",
    "struct.cc",
    "struct_member.cc",
    "struct_member_align_attribute.cc",
    "struct_member_size_attribute.cc",
    "subgroup_size_attribute.cc",
    "switch_statement.cc",
    "templated_identifier.cc",
    "type_decl.cc",
    "unary_op_expression.cc",
    "var.cc",
    "variable.cc",
    "variable_decl_statement.cc",
    "while_statement.cc",
    "workgroup_attribute.cc",
};

const tint_wgsl_inspector_sources = .{
    "entry_point.cc",
    "inspector.cc",
    "resource_binding.cc",
    "scalar.cc",
};

const tint_wgsl_intrinsic_sources = .{
    "ctor_conv.cc",
    "data.cc",
};

const tint_wgsl_ir_sources = .{
    "atomic_vec2u_to_from_u64.cc",
    "builtin_call.cc",
    "unary.cc",
};

const tint_wgsl_ls_sources = .{
    "cancel_request.cc",
    "change_configuration.cc",
    "change_watched_files.cc",
    "completions.cc",
    "definition.cc",
    "diagnostics.cc",
    "document.cc",
    "file.cc",
    "hover.cc",
    "initialize.cc",
    "inlay_hints.cc",
    "references.cc",
    "rename.cc",
    "sem_tokens.cc",
    "serve.cc",
    "server.cc",
    "set_trace.cc",
    "signature_help.cc",
    "symbols.cc",
    "utils.cc",
};

const tint_wgsl_program_sources = .{
    "program.cc",
    "program_builder.cc",
};

const tint_wgsl_reader_sources = .{
    "reader.cc",
    "lower/lower.cc",
    "parser/classify_template_args.cc",
    "parser/lexer.cc",
    "parser/parser.cc",
    "parser/token.cc",
    "program_to_ir/program_to_ir.cc",
};

const tint_wgsl_resolver_sources = .{
    "dependency_graph.cc",
    "incomplete_type.cc",
    "resolve.cc",
    "resolver.cc",
    "sem_helper.cc",
    "uniformity.cc",
    "unresolved_identifier.cc",
    "validator.cc",
};

const tint_wgsl_sem_sources = .{
    "accessor_expression.cc",
    "array.cc",
    "array_count.cc",
    "behavior.cc",
    "block_statement.cc",
    "break_if_statement.cc",
    "builtin_enum_expression.cc",
    "builtin_fn.cc",
    "call.cc",
    "call_target.cc",
    "expression.cc",
    "for_loop_statement.cc",
    "function.cc",
    "function_expression.cc",
    "if_statement.cc",
    "index_accessor_expression.cc",
    "info.cc",
    "load.cc",
    "loop_statement.cc",
    "materialize.cc",
    "member_accessor_expression.cc",
    "module.cc",
    "node.cc",
    "statement.cc",
    "struct.cc",
    "switch_statement.cc",
    "type_expression.cc",
    "value_constructor.cc",
    "value_conversion.cc",
    "value_expression.cc",
    "variable.cc",
    "while_statement.cc",
};

const tint_wgsl_writer_sources = .{
    "output.cc",
    "writer.cc",
    "ast_printer/ast_printer.cc",
    "ir_to_program/ir_to_program.cc",
    "raise/ptr_to_ref.cc",
    "raise/raise.cc",
    "raise/value_to_let.cc",
};

const tint_hlsl_intrinsic_sources = .{
    "data.cc",
};

const tint_hlsl_ir_sources = .{
    "builtin_call.cc",
    "member_builtin_call.cc",
    "ternary.cc",
};

const tint_hlsl_type_sources = .{
    "byte_address_buffer.cc",
    "int8_t4_packed.cc",
    "rasterizer_ordered_texture_2d.cc",
    "uint8_t4_packed.cc",
};

const tint_hlsl_validate_sources = .{
    "validate.cc",
};

const tint_hlsl_writer_sources = .{
    "writer.cc",
    "common/option_helpers.cc",
    "common/options.cc",
    "common/output.cc",
    "helpers/generate_bindings.cc",
    "printer/printer.cc",
    "raise/binary_polyfill.cc",
    "raise/builtin_polyfill.cc",
    "raise/change_immediate_to_uniform.cc",
    "raise/decompose_storage_access.cc",
    "raise/decompose_uniform_access.cc",
    "raise/localize_struct_array_assignment.cc",
    "raise/pixel_local.cc",
    "raise/promote_initializers.cc",
    "raise/raise.cc",
    "raise/replace_default_only_switch.cc",
    "raise/replace_non_indexable_mat_vec_stores.cc",
    "raise/shader_io.cc",
};

const tint_spirv_intrinsic_sources = .{
    "data.cc",
};

const tint_spirv_ir_sources = .{
    "binary.cc",
    "builtin_call.cc",
    "copy_logical.cc",
    "literal_operand.cc",
};

const tint_spirv_reader_sources = .{
    "reader.cc",
    "common/common.cc",
    "lower/atomics.cc",
    "lower/builtins.cc",
    "lower/decompose_strided_array.cc",
    "lower/decompose_strided_matrix.cc",
    "lower/lower.cc",
    "lower/shader_io.cc",
    "lower/texture.cc",
    "lower/transpose_row_major.cc",
    "lower/vector_element_pointer.cc",
    "parser/parser.cc",
};

const tint_spirv_type_sources = .{
    "explicit_layout_array.cc",
    "image.cc",
    "sampled_image.cc",
};

const tint_spirv_validate_sources = .{
    "validate.cc",
};

const tint_spirv_writer_sources = .{
    "writer.cc",
    "analysis/relaxed_precision_decorations.cc",
    "common/binary_writer.cc",
    "common/function.cc",
    "common/instruction.cc",
    "common/module.cc",
    "common/operand.cc",
    "common/option_helper.cc",
    "common/output.cc",
    "printer/printer.cc",
    "raise/builtin_polyfill.cc",
    "raise/case_switch_to_if_else.cc",
    "raise/expand_implicit_splats.cc",
    "raise/fork_explicit_layout_types.cc",
    "raise/handle_matrix_arithmetic.cc",
    "raise/keep_binding_array_as_pointer.cc",
    "raise/merge_return.cc",
    "raise/pass_matrix_by_pointer.cc",
    "raise/raise.cc",
    "raise/remove_unreachable_in_loop_continuing.cc",
    "raise/resource_table_helper.cc",
    "raise/shader_io.cc",
    "raise/unary_polyfill.cc",
    "raise/var_for_dynamic_index.cc",
};

const tint_null_writer_sources = .{
    "writer.cc",
    "common/options.cc",
    "common/output.cc",
    "raise/raise.cc",
};

const dawn_sources = .{
    "Adapter.cpp",
    "ApplyClearColorValueWithDrawHelper.cpp",
    "AsyncTask.cpp",
    "AttachmentState.cpp",
    "BackendConnection.cpp",
    "BindGroup.cpp",
    "BindGroupLayout.cpp",
    "BindGroupLayoutInternal.cpp",
    "BindingInfo.cpp",
    "BlitBufferToDepthStencil.cpp",
    "BlitBufferToTexture.cpp",
    "BlitColorToColorWithDraw.cpp",
    "BlitDepthToDepth.cpp",
    "BlitTextureToBuffer.cpp",
    "Blob.cpp",
    "BlobCache.cpp",
    "BuddyAllocator.cpp",
    "BuddyMemoryAllocator.cpp",
    "Buffer.cpp",
    "CacheKey.cpp",
    "CacheRequest.cpp",
    "CachedObject.cpp",
    "CallbackTaskManager.cpp",
    "CommandAllocator.cpp",
    "CommandBuffer.cpp",
    "CommandBufferStateTracker.cpp",
    "CommandEncoder.cpp",
    "CommandValidation.cpp",
    "Commands.cpp",
    "CompilationMessages.cpp",
    "ComputePassEncoder.cpp",
    "ComputePipeline.cpp",
    "CopyTextureForBrowserHelper.cpp",
    "CreatePipelineAsyncEvent.cpp",
    "Device.cpp",
    "DeviceGuard.cpp",
    "DynamicUploader.cpp",
    "EncodingContext.cpp",
    "Error.cpp",
    "ErrorData.cpp",
    "ErrorInjector.cpp",
    "ErrorScope.cpp",
    "EventManager.cpp",
    "ExecutionQueue.cpp",
    "ExternalTexture.cpp",
    "Features.cpp",
    "Format.cpp",
    "ImmediateConstantsLayout.cpp",
    "ImmediateConstantsTracker.cpp",
    "IndirectDrawMetadata.cpp",
    "IndirectDrawValidationEncoder.cpp",
    "Instance.cpp",
    "InternalPipelineStore.cpp",
    "Limits.cpp",
    "ObjectBase.cpp",
    "ObjectContentHasher.cpp",
    "PassResourceUsageTracker.cpp",
    "PerStage.cpp",
    "PhysicalDevice.cpp",
    "Pipeline.cpp",
    "PipelineCache.cpp",
    "PipelineLayout.cpp",
    "PooledResourceMemoryAllocator.cpp",
    "ProgrammableEncoder.cpp",
    "QueryHelper.cpp",
    "QuerySet.cpp",
    "Queue.cpp",
    "RenderBundle.cpp",
    "RenderBundleEncoder.cpp",
    "RenderEncoderBase.cpp",
    "RenderPassEncoder.cpp",
    "RenderPassWorkaroundsHelper.cpp",
    "RenderPipeline.cpp",
    "ResourceMemoryAllocation.cpp",
    "ResourceTable.cpp",
    "RingBufferAllocator.cpp",
    "Sampler.cpp",
    "ScratchBuffer.cpp",
    "ShaderModule.cpp",
    "ShaderModuleParseRequest.cpp",
    "SharedBufferMemory.cpp",
    "SharedFence.cpp",
    "SharedResourceMemory.cpp",
    "SharedTextureMemory.cpp",
    "Subresource.cpp",
    "Surface.cpp",
    "SwapChain.cpp",
    "SystemEvent.cpp",
    "TexelBufferView.cpp",
    "Texture.cpp",
    "TintUtils.cpp",
    "Toggles.cpp",
    "ValidationUtils.cpp",
    "WaitListEvent.cpp",
    "dawn_platform.cpp",
    "stream/BlobSource.cpp",
    "stream/ByteVectorSink.cpp",
    "stream/Stream.cpp",
    "utils/WGPUHelpers.cpp",
    "webgpu_absl_format.cpp",
};

const dawn_d3d_sources = .{
    "d3d/BackendD3D.cpp",
    "d3d/BlobD3D.cpp",
    "d3d/D3DError.cpp",
    "d3d/DeviceD3D.cpp",
    "d3d/KeyedMutex.cpp",
    "d3d/PhysicalDeviceD3D.cpp",
    "d3d/PlatformFunctions.cpp",
    "d3d/QueueD3D.cpp",
    "d3d/ShaderUtils.cpp",
    "d3d/SharedFenceD3D.cpp",
    "d3d/SharedTextureMemoryD3D.cpp",
    "d3d/SwapChainD3D.cpp",
    "d3d/UtilsD3D.cpp",
};

const dawn_d3d11_sources = .{
    "d3d11/BackendD3D11.cpp",
    "d3d11/BindGroupD3D11.cpp",
    "d3d11/BindGroupLayoutD3D11.cpp",
    "d3d11/BindGroupTrackerD3D11.cpp",
    "d3d11/BufferD3D11.cpp",
    "d3d11/CommandBufferD3D11.cpp",
    "d3d11/CommandRecordingContextD3D11.cpp",
    "d3d11/ComputePipelineD3D11.cpp",
    "d3d11/DeviceD3D11.cpp",
    "d3d11/DeviceInfoD3D11.cpp",
    "d3d11/PhysicalDeviceD3D11.cpp",
    "d3d11/PipelineLayoutD3D11.cpp",
    "d3d11/PlatformFunctionsD3D11.cpp",
    "d3d11/QuerySetD3D11.cpp",
    "d3d11/QueueD3D11.cpp",
    "d3d11/RenderPipelineD3D11.cpp",
    "d3d11/SamplerD3D11.cpp",
    "d3d11/ShaderModuleD3D11.cpp",
    "d3d11/SharedFenceD3D11.cpp",
    "d3d11/SharedTextureMemoryD3D11.cpp",
    "d3d11/SwapChainD3D11.cpp",
    "d3d11/TextureD3D11.cpp",
    "d3d11/UtilsD3D11.cpp",
};

const dawn_d3d12_sources = .{
    "d3d12/BackendD3D12.cpp",
    "d3d12/BindGroupD3D12.cpp",
    "d3d12/BindGroupLayoutD3D12.cpp",
    "d3d12/BufferD3D12.cpp",
    "d3d12/CPUDescriptorHeapAllocationD3D12.cpp",
    "d3d12/CommandBufferD3D12.cpp",
    "d3d12/CommandRecordingContext.cpp",
    "d3d12/ComputePipelineD3D12.cpp",
    "d3d12/D3D12Info.cpp",
    "d3d12/DeviceD3D12.cpp",
    "d3d12/GPUDescriptorHeapAllocationD3D12.cpp",
    "d3d12/HeapAllocatorD3D12.cpp",
    "d3d12/HeapD3D12.cpp",
    "d3d12/PageableD3D12.cpp",
    "d3d12/PhysicalDeviceD3D12.cpp",
    "d3d12/PipelineLayoutD3D12.cpp",
    "d3d12/PlatformFunctionsD3D12.cpp",
    "d3d12/QuerySetD3D12.cpp",
    "d3d12/QueueD3D12.cpp",
    "d3d12/RenderPassBuilderD3D12.cpp",
    "d3d12/RenderPipelineD3D12.cpp",
    "d3d12/ResidencyManagerD3D12.cpp",
    "d3d12/ResourceAllocatorManagerD3D12.cpp",
    "d3d12/ResourceHeapAllocationD3D12.cpp",
    "d3d12/SamplerD3D12.cpp",
    "d3d12/SamplerHeapCacheD3D12.cpp",
    "d3d12/ShaderModuleD3D12.cpp",
    "d3d12/ShaderVisibleDescriptorAllocatorD3D12.cpp",
    "d3d12/SharedBufferMemoryD3D12.cpp",
    "d3d12/SharedFenceD3D12.cpp",
    "d3d12/SharedTextureMemoryD3D12.cpp",
    "d3d12/StagingDescriptorAllocatorD3D12.cpp",
    "d3d12/StreamImplD3D12.cpp",
    "d3d12/SwapChainD3D12.cpp",
    "d3d12/TextureCopySplitter.cpp",
    "d3d12/TextureD3D12.cpp",
    "d3d12/UtilsD3D12.cpp",
};

const dawn_metal_sources = .{
    "Surface_metal.mm",
    "metal/BackendMTL.mm",
    "metal/BindGroupLayoutMTL.mm",
    "metal/BindGroupMTL.mm",
    "metal/BufferMTL.mm",
    "metal/CommandBufferMTL.mm",
    "metal/CommandRecordingContext.mm",
    "metal/ComputePipelineMTL.mm",
    "metal/DeviceMTL.mm",
    "metal/MultiDrawEncoder.mm",
    "metal/PhysicalDeviceMTL.mm",
    "metal/PipelineLayoutMTL.mm",
    "metal/QuerySetMTL.mm",
    "metal/QueueMTL.mm",
    "metal/RenderPipelineMTL.mm",
    "metal/SamplerMTL.mm",
    "metal/ShaderModuleMTL.mm",
    "metal/SharedFenceMTL.mm",
    "metal/SharedTextureMemoryMTL.mm",
    "metal/SwapChainMTL.mm",
    "metal/TextureMTL.mm",
    "metal/UtilsMetal.mm",
};

const dawn_null_sources = .{
    "null/DeviceNull.cpp",
};

const dawn_webgpu_sources = .{
    "webgpu/BackendWGPU.cpp",
    "webgpu/BindGroupLayoutWGPU.cpp",
    "webgpu/BindGroupWGPU.cpp",
    "webgpu/BufferWGPU.cpp",
    "webgpu/CaptureContext.cpp",
    "webgpu/CommandBufferWGPU.cpp",
    "webgpu/ComputePipelineWGPU.cpp",
    "webgpu/DeviceWGPU.cpp",
    "webgpu/PhysicalDeviceWGPU.cpp",
    "webgpu/PipelineLayoutWGPU.cpp",
    "webgpu/QuerySetWGPU.cpp",
    "webgpu/QueueWGPU.cpp",
    "webgpu/RecordableObject.cpp",
    "webgpu/RenderPipelineWGPU.cpp",
    "webgpu/SamplerWGPU.cpp",
    "webgpu/Serialization.cpp",
    "webgpu/ShaderModuleWGPU.cpp",
    "webgpu/TextureWGPU.cpp",
    "webgpu/ToWGPU.cpp",
};

const dawn_opengl_sources = .{
    "opengl/BackendGL.cpp",
    "opengl/BindGroupGL.cpp",
    "opengl/BindGroupLayoutGL.cpp",
    "opengl/BufferGL.cpp",
    "opengl/CommandBufferGL.cpp",
    "opengl/ComputePipelineGL.cpp",
    "opengl/ContextEGL.cpp",
    "opengl/DeviceGL.cpp",
    "opengl/DisplayEGL.cpp",
    "opengl/EGLFunctions.cpp",
    "opengl/GLFormat.cpp",
    "opengl/OpenGLFunctions.cpp",
    "opengl/OpenGLVersion.cpp",
    "opengl/PersistentPipelineStateGL.cpp",
    "opengl/PhysicalDeviceGL.cpp",
    "opengl/PipelineGL.cpp",
    "opengl/PipelineLayoutGL.cpp",
    "opengl/QuerySetGL.cpp",
    "opengl/QueueGL.cpp",
    "opengl/RenderPipelineGL.cpp",
    "opengl/SamplerGL.cpp",
    "opengl/ShaderModuleGL.cpp",
    "opengl/SharedFenceEGL.cpp",
    "opengl/SharedFenceGL.cpp",
    "opengl/SharedTextureMemoryEGL.cpp",
    "opengl/SharedTextureMemoryGL.cpp",
    "opengl/SwapChainEGL.cpp",
    "opengl/TextureGL.cpp",
    "opengl/UtilsEGL.cpp",
    "opengl/UtilsGL.cpp",
};

const dawn_vulkan_sources = .{
    "vulkan/BackendVk.cpp",
    "vulkan/BindGroupLayoutVk.cpp",
    "vulkan/BindGroupVk.cpp",
    "vulkan/BufferVk.cpp",
    "vulkan/CommandBufferVk.cpp",
    "vulkan/CommandRecordingContextVk.cpp",
    "vulkan/ComputePipelineVk.cpp",
    "vulkan/DescriptorSetAllocator.cpp",
    "vulkan/DeviceVk.cpp",
    "vulkan/FencedDeleter.cpp",
    "vulkan/FramebufferCache.cpp",
    "vulkan/MemoryTypeSelector.cpp",
    "vulkan/PhysicalDeviceVk.cpp",
    "vulkan/PipelineCacheVk.cpp",
    "vulkan/PipelineLayoutVk.cpp",
    "vulkan/PipelineVk.cpp",
    "vulkan/QuerySetVk.cpp",
    "vulkan/QueueVk.cpp",
    "vulkan/RenderPassCache.cpp",
    "vulkan/RenderPipelineVk.cpp",
    "vulkan/ResolveTextureLoadingUtilsVk.cpp",
    "vulkan/ResourceHeapVk.cpp",
    "vulkan/ResourceMemoryAllocatorVk.cpp",
    "vulkan/ResourceTableVk.cpp",
    "vulkan/SamplerVk.cpp",
    "vulkan/ShaderModuleVk.cpp",
    "vulkan/SharedFenceVk.cpp",
    "vulkan/SharedTextureMemoryVk.cpp",
    "vulkan/StreamImplVk.cpp",
    "vulkan/SwapChainVk.cpp",
    "vulkan/TextureVk.cpp",
    "vulkan/UtilsVulkan.cpp",
    "vulkan/VulkanError.cpp",
    "vulkan/VulkanExtensions.cpp",
    "vulkan/VulkanFunctions.cpp",
    "vulkan/VulkanInfo.cpp",
    "vulkan/external_memory/MemoryService.cpp",
    "vulkan/external_memory/MemoryServiceImplementation.cpp",
    "vulkan/external_semaphore/SemaphoreService.cpp",
    "vulkan/external_semaphore/SemaphoreServiceImplementation.cpp",
};

const dawn_common_sources = .{
    "AlignedAlloc.cpp",
    "Assert.cpp",
    "Defer.cpp",
    "DynamicLib.cpp",
    "FutureUtils.cpp",
    "GPUInfo.cpp",
    "Log.cpp",
    "Math.cpp",
    "RefCounted.cpp",
    "Result.cpp",
    "Sha3.cpp",
    "SlabAllocator.cpp",
    "StringViewUtils.cpp",
    "SystemUtils.cpp",
    "ThreadLocal.cpp",
    "WeakRefSupport.cpp",
};

const dawn_platform_sources = .{
    "DawnPlatform.cpp",
    "WorkerThread.cpp",
    "metrics/HistogramMacros.cpp",
    "tracing/EventTracer.cpp",
};

const dawn_wgpu_utils_sources = .{
    "ComboRenderBundleEncoderDescriptor.cpp",
    "ComboRenderPipelineDescriptor.cpp",
    "TextureUtils.cpp",
    "WGPUHelpers.cpp",
};

const native_utils_sources = .{
    "ChainUtils_autogen.cpp",
    "ProcTable.cpp",
    "wgpu_structs_autogen.cpp",
    "ValidationUtils_autogen.cpp",
    "webgpu_absl_format_autogen.cpp",
    "webgpu_StreamImpl_autogen.cpp",
    "ObjectType_autogen.cpp",
};
