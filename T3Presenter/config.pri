# Config.pri file version 2.0. Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR = $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        profile {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/bb/system)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/bb/system)

            LIBS += -lbbcascades \
                -lbbutility \
                -lbbsystem

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        } else {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/bb/system)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/bb/system)

            LIBS += -lbbcascades \
                -lbbutility \
                -lbbsystem

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }

    }

    CONFIG(release, debug|release) {
        !profile {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/bb/system)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/bb/system)

            LIBS += -lbbcascades \
                -lbbutility \
                -lbbsystem

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

simulator {
    CONFIG(debug, debug|release) {
        !profile {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/bb/system)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/bb/system)

            LIBS += -lbbcascades \
                -lbbutility \
                -lbbsystem

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

config_pri_assets {
    OTHER_FILES += \
        $$quote($$BASEDIR/assets/HostPresentationPage.qml) \
        $$quote($$BASEDIR/assets/JoinPresentationPage.qml) \
        $$quote($$BASEDIR/assets/MainMenuPage.qml) \
        $$quote($$BASEDIR/assets/PresentationEditPage.qml) \
        $$quote($$BASEDIR/assets/PresentationPage.qml)
}

config_pri_source_group1 {
    SOURCES += \
        $$quote($$BASEDIR/src/ApplicationUI.cpp) \
        $$quote($$BASEDIR/src/main.cpp) \
        $$quote($$BASEDIR/src/network/Client.cpp) \
        $$quote($$BASEDIR/src/network/NetworkControl.cpp) \
        $$quote($$BASEDIR/src/network/Server.cpp) \
        $$quote($$BASEDIR/src/source/Presentation.cpp) \
        $$quote($$BASEDIR/src/source/PresentationControl.cpp)

    HEADERS += \
        $$quote($$BASEDIR/src/ApplicationUI.hpp) \
        $$quote($$BASEDIR/src/network/Client.h) \
        $$quote($$BASEDIR/src/network/NetworkControl.h) \
        $$quote($$BASEDIR/src/network/Server.h) \
        $$quote($$BASEDIR/src/source/Presentation.hpp) \
        $$quote($$BASEDIR/src/source/PresentationControl.hpp)
}

CONFIG += precompile_header

PRECOMPILED_HEADER = $$quote($$BASEDIR/precompiled.h)

lupdate_inclusion {
    SOURCES += \
        $$quote($$BASEDIR/../src/*.c) \
        $$quote($$BASEDIR/../src/*.c++) \
        $$quote($$BASEDIR/../src/*.cc) \
        $$quote($$BASEDIR/../src/*.cpp) \
        $$quote($$BASEDIR/../src/*.cxx) \
        $$quote($$BASEDIR/../src/network/*.c) \
        $$quote($$BASEDIR/../src/network/*.c++) \
        $$quote($$BASEDIR/../src/network/*.cc) \
        $$quote($$BASEDIR/../src/network/*.cpp) \
        $$quote($$BASEDIR/../src/network/*.cxx) \
        $$quote($$BASEDIR/../src/source/*.c) \
        $$quote($$BASEDIR/../src/source/*.c++) \
        $$quote($$BASEDIR/../src/source/*.cc) \
        $$quote($$BASEDIR/../src/source/*.cpp) \
        $$quote($$BASEDIR/../src/source/*.cxx) \
        $$quote($$BASEDIR/../assets/*.qml) \
        $$quote($$BASEDIR/../assets/*.js) \
        $$quote($$BASEDIR/../assets/*.qs)

    HEADERS += \
        $$quote($$BASEDIR/../src/*.h) \
        $$quote($$BASEDIR/../src/*.h++) \
        $$quote($$BASEDIR/../src/*.hh) \
        $$quote($$BASEDIR/../src/*.hpp) \
        $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS = $$quote($${TARGET}_en.ts) \
    $$quote($${TARGET}.ts)
