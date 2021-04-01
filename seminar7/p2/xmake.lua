add_rules("mode.debug", "mode.release")

target("p2")
    --set_warnings("extra")
    set_kind("binary")
    add_files("src/*.cpp")