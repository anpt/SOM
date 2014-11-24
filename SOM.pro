# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = SOM
CONFIG += c++11
CONFIG += sailfishapp

SOURCES += src/SOM.cpp \
    filehandler.cpp \
    src/QListHandler.cpp \
    src/todoHeader.cpp

OTHER_FILES += qml/SOM.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/SOM.changes.in \
    rpm/SOM.spec \
    rpm/SOM.yaml \
    translations/*.ts \
    SOM.desktop \
    qml/pages/files.qml \
    qml/pages/newTodo.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/SOM-de.ts

HEADERS += \
    filehandler.hpp \
    src/QListHandler.h \
    src/todoHeader.h

