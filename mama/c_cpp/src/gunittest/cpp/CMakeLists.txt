enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

get_target_property(MAMACPP_INCLUDES mamacpp INCLUDE_DIRECTORIES)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${MAMACPP_INCLUDES}
)

add_executable(UnitTestMamaCPP
	MainUnitTestCpp.cpp
	MamaDateTimeTest.cpp
	MamaMsgTest.cpp
	MamaOpenCloseTest.cpp
	MamaPriceTest.cpp
	MamaPublisherTest.cpp
	MamaSubscriptionTest.cpp
	MamaTimerTest.cpp
)
target_link_libraries(UnitTestMamaCPP ${GTEST_BOTH_LIBRARIES} mamacpp mama)

install(TARGETS UnitTestMamaCPP
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib)
if (WIN32 AND MSVC)
	install(FILES $<TARGET_PDB_FILE:UnitTestMamaCPP> DESTINATION bin OPTIONAL)
endif()