find_package(pybind11 CONFIG REQUIRED)

set(TARGET python_binding)

pybind11_add_module(${TARGET} MODULE python_binding.cpp)

target_link_libraries(${TARGET} PRIVATE polatory)

set_target_properties(${TARGET} PROPERTIES OUTPUT_NAME polatory)

if(MSVC)
    polatory_get_prebuilt_boost_dlls(BOOST_DLLS)
    polatory_target_contents(${TARGET} ${POLATORY_DLLS} ${BOOST_DLLS})
endif()
