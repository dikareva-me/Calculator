cmake_minimum_required(VERSION 3.8)

project(Calc_ver2)

set(SOURCES
        main.cpp
        calc.cpp
	alloper.cpp
	parser.cpp
)

set(HEADERS
        calc.h
	alloper.h
	parser.h
	command.h
	div.h
	mult.h
	plus.h
	unary_minus.h
	minus.h
)

add_executable(${SOURCES} ${HEADERS})

set_property(TARGET Calc_ver2 PROPERTY CXX_STANDARD 20)