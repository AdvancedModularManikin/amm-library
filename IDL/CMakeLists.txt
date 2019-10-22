
if (COMMAND FastRTPS_IDLGEN)
    add_custom_target(generate_from_idl_standard COMMAND ${FASTRTP_GEN_EXECUTABLE} -replace -d ${PROJECT_SOURCE_DIR}/src/AMM ${PROJECT_SOURCE_DIR}/IDL/AMM_Standard.idl)
    add_custom_target(generate_from_idl_extended COMMAND ${FASTRTP_GEN_EXECUTABLE} -replace -d ${PROJECT_SOURCE_DIR}/src/AMM ${PROJECT_SOURCE_DIR}/IDL/AMM_Extended.idl)
endif()
