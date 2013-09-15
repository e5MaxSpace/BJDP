TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    main.cpp \
    atm.cpp \
    account.cpp \
    electricitycard.cpp \
    command.cpp \
    depositecommand.cpp \
    withdrawcommand.cpp \
    buyelectricitycommand.cpp \
    atmaction.cpp

HEADERS += \
    atm.h \
    account.h \
    electricitycard.h \
    command.h \
    depositecommand.h \
    withdrawcommand.h \
    buyelectricitycommand.h \
    atmaction.h

OTHER_FILES += \
    ATM.pri

FORMS +=

