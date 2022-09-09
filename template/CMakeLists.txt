add_library(template MODULE Pass.cpp)

llvm_map_components_to_libnames(llvm_libs core support ipo)

target_link_libraries(template ${llvm_libs})
