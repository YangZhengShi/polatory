find_package(pybind11 CONFIG REQUIRED)

set(TARGET pola)

add_library(${TARGET} MODULE main.cpp)

target_link_libraries(${TARGET} PRIVATE
    polatory
    pybind11::module
)

set_target_properties(${TARGET} PROPERTIES
    PREFIX "${PYTHON_MODULE_PREFIX}"
    SUFFIX "${PYTHON_MODULE_EXTENSION}"
)

if(MSVC)
    polatory_get_prebuilt_boost_dlls(BOOST_DLLS)
    polatory_target_contents(${TARGET} ${POLATORY_DLLS} ${BOOST_DLLS})
endif()
