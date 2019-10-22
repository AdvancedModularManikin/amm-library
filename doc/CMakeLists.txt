find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_IN Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    message(STATUS "DOXYGEN_IN is ${DOXYGEN_IN}")
    message(STATUS "DOXYGEN_OUT is ${DOXYGEN_OUT}")
    message(STATUS "CMAKE_CURRENT_BINARY_DIR is ${CMAKE_CURRENT_BINARY_DIR}")
    message(STATUS "CMAKE_BINARY_DIR is ${CMAKE_BINARY_DIR}")

    # DOXYGEN_IN is Doxyfile.in
    # DOXYGEN_OUT is /Users/gene/Development/C++/mydownloadgtestintoproject/build/doc/Doxyfile
    # CMAKE_CURRENT_BINARY_DIR is /Users/gene/Development/C++/mydownloadgtestintoproject/build/doc
    # CMAKE_BINARY_DIR is /Users/gene/Development/C++/mydownloadgtestintoproject/build

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            VERBATIM
            )
    message(STATUS "Running doxygen")

    # Install the project's documentation
    install(DIRECTORY ${CMAKE_BINARY_DIR}/doc/html/ DESTINATION share/doc)

else (DOXYGEN_FOUND)

    message(FATAL_ERROR "Doxygen needs to be installed to generate documentation!")

endif (DOXYGEN_FOUND)