add_rules("mode.debug", "mode.release")

target("little_world_client")
    add_rules("qt.widgetapp")
    add_frameworks("QtMultimedia")
    add_headerfiles("client/*.h")
    add_files("client/*.cc")
    add_files("core/*.cc")
    add_files("client/mainwindow.ui")
    add_files("client/mainwindow.h")

    after_build(function (target)
        os.cp("client/res", target:targetdir())
    end)