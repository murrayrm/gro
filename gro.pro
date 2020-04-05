# gro.pro - Qt project file for gro
#
# Created by QtCreator 2012-05-23T09:21:54
# Modified 4 Apr 2020, Richard M. Murray
#
# This is the project file for the `gro` application.  To create the
# makefiles required to compile `gro`, run `qmake` followed by `make`.
# A number of variables can be used to modify the compilation:
#
#   CONFIG=nogui	Create the command line version of gro
#   CHIPMUNK=<dir>	Set path to Chipmunk2D directory
#   CCL=<dir>		Set path to CCL directory
#   OUT_PWD=<dir>	Installation directory (?)
#
# The default locations for chipmunk and CCL are ../chipmunk and ../ccl.

# Turn off warnings
CONFIG += warn_off

# Add paths to linking commands
defined(CHIPMUNK, var) {
  LIBS += -L$$CHIPMUNK
  DEPENDPATH += $$CHIPMUNK
  INCLUDEPATH += $$CHIPMUNK/include/chipmunk
}
defined(CCL, var) {
  LIBS += -L$$CCL
  PRE_TARGETDEPS += $$CCL/libccl.a
  INCLUDEPATH += $$CCL
}

contains ( CONFIG, nogui ) {
  QMAKE_CXXFLAGS += -DNOGUI #-std=gnu99
}

win32 {
  QMAKE_CXXFLAGS += -O3 -DWIN -DNDEBUG
  contains ( CONFIG, nogui ) {
    CONFIG += console
  }
  CONFIG -= app_bundle
}

macx {
  QMAKE_CXXFLAGS += -fast
}

defined(OUT_PWD, var) {
  makelinks.commands += echo Making links in $$OUT_PWD;
  makelinks.commands += ln -s -f examples $${OUT_PWD}/examples;
  makelinks.commands += ln -s -f include $${OUT_PWD}/include;
}

QMAKE_EXTRA_TARGETS += makelinks
POST_TARGETDEPS += makelinks

contains ( CONFIG, nogui ) {
  QT -= core gui
  TARGET = grong
  TEMPLATE = app
} else {
  QT += core gui widgets
  TARGET = gro
  TEMPLATE = app
}

ICON = groicon.icns

SOURCES += main.cpp\
    gui.cpp \
    GroThread.cpp \
    GroWidget.cpp \
    Messages.cpp \
    Programs.cpp \
    Signal.cpp \
    Themes.cpp \
    Utility.cpp \
    World.cpp \
    EColi.cpp \
    Gro.cpp \
    GroPainter.cpp \
    Cell.cpp \
    reaction.cpp \
    #Yeast.cpp

HEADERS  += gui.h \
    GroThread.h \
    GroWidget.h \
    Defines.h \
    Programs.h \
    Utility.h \
    Micro.h \
    GroPainter.h \
    Theme.h \
    EColi.h \
    Cell.h \
    ui_gui.h \
    Yeast.h

contains ( CONFIG, nogui ) {
  SOURCES -= GroThread.cpp GroWidget.cpp GroPainter.cpp gui.cpp Themes.cpp
  HEADERS -= gui.h GroThread.h GroWidget.h GroPainter.h
}

!contains ( CONFIG, nogui ) {
  FORMS    += gui.ui
}

macx|linux {
  LIBS += -lccl -lchipmunk
}

OTHER_FILES += \
    examples/wave.gro \
    examples/skin.gro \
    examples/morphogenesis.gro \
    examples/inducer.gro \
    examples/growth.gro \
    examples/gfp.gro \
    examples/game.gro \
    examples/foreach.gro \
    examples/edge.gro \
    examples/dilution.gro \
    examples/chemotaxis.gro \
    examples/bandpass.gro \
    include/gro.gro \
    include/standard.gro \
    icons/stop.png \
    icons/step.png \
    icons/start.png \
    icons/reload.png \
    icons/open.png \
    examples/signal_demo.gro \
    examples/maptocells.gro \
    examples/game.gro \
    changelog.txt \
    error.tiff \
    examples/signal_grid.gro \
    examples/coupled_oscillator.gro \
    examples/spots.gro \
    examples/spatial_oscillations.gro \
    examples/symbiosis.gro \
    LICENSE.txt \
    examples/yeast_example.gro \
    .gitignore \
    doc/compile_mac.md \
    doc/compile_linux.md \
    README.md \
    examples/geometry.gro \
    examples/barriers.gro \
    examples/signal_dump.gro

!contains ( CONFIG, nogui ) {
  RESOURCES += icons.qrc
}

QMAKE_CLEAN += Makefile moc_GroPainter.cpp
