set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Build gtest's sample programs." FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendors/benchmark)
set_property(TARGET benchmark PROPERTY FOLDER "Vendors")

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vendors/benchmark/include)

if(WITH_CUDA)
	file(GLOB Files ${CMAKE_CURRENT_SOURCE_DIR}/*.cu)
	source_group(Source ${HELLO_SRCS} )
	CUDA_ADD_EXECUTABLE(tensor_benchmark ${Files})
	add_dependencies(tensor_benchmark benchmark)
	target_link_libraries(tensor_benchmark benchmark)
else()
	file(GLOB Files ${CMAKE_CURRENT_SOURCE_DIR}/*.cu)
	set_source_files_properties(${Files} PROPERTIES LANGUAGE CXX)
	add_executable(tensor_benchmark ${Files})
	add_dependencies(tensor_benchmark benchmark)
	target_link_libraries(tensor_benchmark benchmark)
	set_target_properties(tensor_benchmark PROPERTIES LINKER_LANGUAGE CXX)
endif()
