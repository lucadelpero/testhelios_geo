set(OSM_DIR ${CMAKE_CURRENT_LIST_DIR})

set(HEADER_FILES_OSM)

file(GLOB_RECURSE ALL_EXE ${CMAKE_CURRENT_SOURCE_DIR}/test_geo.cpp)

MESSAGE( STATUS "ALL_EXE:         " ${ALL_EXE} )

# Build executable for each test
foreach(EXE_FILE ${ALL_EXE})
    get_filename_component(EXE_FILE_NAME ${EXE_FILE} NAME_WE)
    add_executable(${EXE_FILE_NAME} ${HEADER_FILES_OSM} ${EXE_FILE} ${ALL_CPP})
    target_include_directories(${EXE_FILE_NAME} SYSTEM PUBLIC ${BLIPPAR_INCLUDE_DIRS})
    set(OSM_LINK_LIBS helios_mapping nucleus_all ${BLIPPAR_LIBRARIES})
    target_link_libraries(${EXE_FILE_NAME} ${OSM_LINK_LIBS})
endforeach(EXE_FILE)
