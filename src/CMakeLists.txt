#############################
# CMake Standard Library root/src
#############################


set(AMM_STANDARD_CODE amm/AMM_Standard.cxx amm/AMM_Standard.h amm/AMM_StandardPubSubTypes.cxx amm/AMM_StandardPubSubTypes.h)
set(AMM_EXTENDED_CODE amm/AMM_Extended.cxx amm/AMM_Extended.h amm/AMM_ExtendedPubSubTypes.cxx amm/AMM_ExtendedPubSubTypes.h)
set(DATAMODEL_SOURCES ${AMM_STANDARD_CODE} ${AMM_EXTENDED_CODE})

set(DDS_MANAGER dds_manager)
set(DDS_MANAGER_SOURCES amm/DDSManager.h amm/DDS_Listeners.cpp amm/ListenerInterface.h)
set(DDS_TYPE_SOURCES amm/TopicNames.h amm/AmmDataType.h)
set(UTILITY_SOURCES amm/Utility.cpp amm/Utility.h)


function(my_export_target _target _include_dir)
   file(
      WRITE "${CMAKE_CURRENT_BINARY_DIR}/${_target}Config.cmake"
      "
            include(\"\$\{CMAKE_CURRENT_LIST_DIR\}/${_target}Targets.cmake\")
            set_property(
                TARGET ${_target}
                APPEND PROPERTY
                    INTERFACE_INCLUDE_DIRECTORIES \"${_include_dir}\"
            )
        "
   )

   export(TARGETS ${_target} FILE "${CMAKE_CURRENT_BINARY_DIR}/${_target}Targets.cmake")
   export(PACKAGE ${_target})
endfunction(my_export_target)

if (MSVC)
    add_library("amm_std" STATIC ${DATAMODEL_SOURCES} ${DDS_TYPE_SOURCES} ${DDS_MANAGER_SOURCES} ${UTILITY_SOURCES})
    set_target_properties("amm_std" PROPERTIES PUBLIC_HEADER
            "amm_std.h;amm/AmmDataType.h;amm/DDSManager.h;amm/DDS_Listeners.h;amm/ListenerInterface.h;amm/TopicNames.h;amm/AMM_Standard.h;amm/AMM_StandardPubSubTypes.h;amm/AMM_Extended.h;amm/AMM_ExtendedPubSubTypes.h;amm/Utility.h;amm/BaseLogger.cpp;amm/BaseLogger.h")
    install(TARGETS amm_std
       EXPORT ${PROJECT_NAME}
       LIBRARY DESTINATION "lib"
       PUBLIC_HEADER DESTINATION "include")
else ()
    add_library("amm_std" SHARED ${DATAMODEL_SOURCES} ${DDS_TYPE_SOURCES} ${DDS_MANAGER_SOURCES} ${UTILITY_SOURCES})
    set_target_properties("amm_std" PROPERTIES PUBLIC_HEADER
            "amm_std.h;amm/AmmDataType.h;amm/DDSManager.h;amm/DDS_Listeners.h;amm/ListenerInterface.h;amm/TopicNames.h;amm/AMM_Standard.h;amm/AMM_StandardPubSubTypes.h;amm/AMM_Extended.h;amm/AMM_ExtendedPubSubTypes.h;amm/Utility.h;amm/BaseLogger.cpp;amm/BaseLogger.h")
    install(TARGETS amm_std
            EXPORT ${PROJECT_NAME}
            LIBRARY DESTINATION "lib"
            PUBLIC_HEADER DESTINATION "include/amm")
endif ()
my_export_target(amm_std "${HEADER_DIR}")

target_link_libraries(
        amm_std
        PUBLIC fastrtps
        PUBLIC fastcdr
        ${Boost_LIBRARIES}
)

target_include_directories(amm_std PUBLIC ${PROJECT_SOURCE_DIR}/src)




