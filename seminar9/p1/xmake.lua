add_rules("mode.debug", "mode.release")

target("p1")
    set_languages("c++17")
    set_kind("binary")
    add_files("src/*.cpp")
