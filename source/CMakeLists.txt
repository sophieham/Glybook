cmake_minimum_required(VERSION 3.5)

project(Glybook LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets Core Quick Sql REQUIRED)

if(ANDROID)
  add_library(Glybook SHARED
    main.cpp
    connection.cpp
    connection.h
    connection.ui

  )
else()
  add_executable(Glybook
    main.cpp
    dbconnection.cpp
    dbconnection.h
    connection.cpp
    connection.h
    connection.ui
    library.cpp
    library.h
    genre.cpp
    genre.h
    book.cpp
    book.h
    user.cpp
    user.h
    reservation.cpp
    reservation.h
    initialization.cpp
    initialization.h
    initialization.ui
    glybook.cpp
    glybook.h
    glybook.ui
    bookdialog.cpp
    bookdialog.h
    bookdialog.ui
    settings.cpp
    settings.h
    settings.ui
    myAccount.cpp
    myAccount.h
    myAccount.ui
    resource.qrc
    manageaccounts.cpp
    manageaccounts.h
    manageaccounts.ui
    accountdialog.cpp
    accountdialog.h
    accountdialog.ui
    accounthistory.cpp
    accounthistory.h
    accounthistory.ui
  )
endif()

target_link_libraries(Glybook PRIVATE Qt5::Widgets Qt5::Core Qt5::Quick Qt5::Sql)
