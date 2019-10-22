

macro (DEFINE_FastRTPS_SOURCES idlfilename)
  set(outsources)
  get_filename_component(it ${idlfilename} ABSOLUTE)
  get_filename_component(nfile ${idlfilename} NAME_WE)
  set(outsources ${outsources} ${CMAKE_CURRENT_BINARY_DIR}/gen/${nfile}.cxx ${CMAKE_CURRENT_BINARY_DIR}/gen/${nfile}.h)
  set(outsources ${outsources} ${CMAKE_CURRENT_BINARY_DIR}/gen/${nfile}PubSubTypes.cxx ${CMAKE_CURRENT_BINARY_DIR}/gen/${nfile}PubSubTypes.h)
endmacro (DEFINE_FastRTPS_SOURCES)

if (NOT FASTRTP_GEN_EXECUTABLE)
  find_program(FASTRTP_GEN_EXECUTABLE NAME fastrtpsgen
          DOC "FastRTPS code generator"
          PATH_SUFFIXES bin
          )
endif()

if (FASTRTP_GEN_EXECUTABLE)
  macro (FastRTPS_IDLGEN idlfilename)
    get_filename_component(it ${idlfilename} ABSOLUTE)
    get_filename_component(idlfilename ${idlfilename} NAME)
    DEFINE_FastRTPS_SOURCES(${ARGV})
    add_custom_command (
            OUTPUT ${outsources}
            COMMAND ${FASTRTP_GEN_EXECUTABLE}
            ARGS
            #-example x64Linux2.6gcc
            -replace -d ${CMAKE_CURRENT_SOURCE_DIR}/src/AMM ${idlfilename}
            DEPENDS ${it}
    )
  endmacro (FastRTPS_IDLGEN)
endif()

