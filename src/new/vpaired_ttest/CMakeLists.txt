PROJECT(vpaired_ttest)

ADD_EXECUTABLE(vpaired_ttest vpaired_ttest.c Gaussianize.c)
TARGET_LINK_LIBRARIES(vpaired_ttest lipsia ${VIAIO_LIBRARY})


INSTALL(TARGETS vpaired_ttest
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
