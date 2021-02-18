add_rules("mode.debug", "mode.release")

target("p4")
    set_kind("binary")
    add_files("src/p4.cpp")

target("p1")
    set_languages("C")
    set_kind("binary")
    add_files("src/p1.cpp")
