
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/dict.cpp
		   COMMAND rootcint -f dict.cpp -c -I${CMAKE_CURRENT_SOURCE_DIR} -I${ALIROOT_INCLUDES} AliAnalysisTaskPt.h LinkDef.h)
add_library(PtTask SHARED AliAnalysisTaskPt.cxx ${CMAKE_CURRENT_BINARY_DIR}/dict.cpp)
target_link_libraries(PtTask ${LIBS})
