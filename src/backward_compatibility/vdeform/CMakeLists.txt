PROJECT(vdeform)

ADD_EXECUTABLE(vdeform vdeform.C)
TARGET_LINK_LIBRARIES(vdeform lipsia ${VIA_LIBRARY})

INSTALL(TARGETS vdeform
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
