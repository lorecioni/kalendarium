project(Kalendarium)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(Kalendarium_SRCS main.cpp  Event.cpp EventCreator.cpp EventManager.cpp TablesContainer.cpp WeekModel.cpp MainGui.cpp ClockWidget.cpp  Address_Book/Contact.cpp Address_Book/ContactWidget.cpp Address_Book/AddWidget.cpp Address_Book/ListWidget.cpp Address_Book/Rubrica.cpp Address_Book/SearchWidget.cpp )
qt4_automoc(${Kalendarium_SRCS})
add_executable(Kalendarium ${Kalendarium_SRCS})
target_link_libraries(Kalendarium ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

add_subdirectory(Address_Book)