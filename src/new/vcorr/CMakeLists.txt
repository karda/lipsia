PROJECT(vcorr)

ADD_EXECUTABLE(vcorr vcorr.c ROI.c MI.c KendallDist.c Correlation.c)
TARGET_LINK_LIBRARIES(vcorr lipsia ${VIAIO_LIBRARY} ${LIPSIA_LIBRARY}
                      ${GSL_GSL_LIBRARY} ${GSL_CBLAS_LIBRARY})


INSTALL(TARGETS vcorr
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
