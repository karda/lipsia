PROJECT(vtal)

ADD_EXECUTABLE(vtal vtal.c Tal.c Brainpeel.c)
TARGET_LINK_LIBRARIES(vtal lipsia ${VIA_LIBRARY})

SET_TARGET_PROPERTIES(vtal PROPERTIES
                      COMPILE_FLAGS -ansi)

INSTALL(TARGETS vtal
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
