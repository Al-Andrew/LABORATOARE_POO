add_rules("mode.debug", "mode.release")

target("p4")
    set_kind("binary")
    add_files("src/p4.cpp")

target("p2")
    set_kind("binary")
    add_files("src/p2.cpp")

target("p3")
    set_kind("binary")
    add_files("src/p3.cpp")
