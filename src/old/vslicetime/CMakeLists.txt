PROJECT(vslicetime)

ADD_EXECUTABLE(vslicetime vslicetime.c)
TARGET_LINK_LIBRARIES(vslicetime lipsia ${VIA_LIBRARY})


INSTALL(TARGETS vslicetime
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
