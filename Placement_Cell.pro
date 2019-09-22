#-------------------------------------------------
#
# Project created by QtCreator 2017-07-20T15:33:32
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Placement_Cell
TEMPLATE = app


SOURCES += main.cpp\
        welcome.cpp \
    student_login.cpp \
    student_registration.cpp \
    studentmain.cpp \
    cv_builder.cpp \
    take_test.cpp \
    question.cpp \
    student_report.cpp \
    questionreasoning.cpp \
    questionverbal.cpp \
    viewcv.cpp \
    faq1.cpp \
    report.cpp \
    companydetails.cpp \
    faq_ans.cpp

HEADERS  += welcome.h \
    student_login.h \
    student_registration.h \
    studentmain.h \
    cv_builder.h \
    take_test.h \
    question.h \
    student_report.h \
    questionreasoning.h \
    questionverbal.h \
    viewcv.h \
    faq1.h \
    report.h \
    companydetails.h \
    faq_ans.h

FORMS    += welcome.ui \
    student_login.ui \
    student_registration.ui \
    studentmain.ui \
    cv_builder.ui \
    take_test.ui \
    question.ui \
    student_report.ui \
    questionreasoning.ui \
    questionverbal.ui \
    viewcv.ui \
    faq1.ui \
    report.ui \
    faq_ans.ui

RESOURCES += \
    pictures.qrc
