PROJECT(vsvm)

ADD_EXECUTABLE(vsl vsl.cpp MriSvm.cpp SearchLight.cpp libsvm-dense/svm.cpp)
ADD_EXECUTABLE(vsvm vsvm.cpp PCA.cpp MriSvm.cpp libsvm-dense/svm.cpp SearchLight.cpp)
ADD_EXECUTABLE(vsvr vsvr.cpp PCA.cpp MriSvm.cpp libsvm-dense/svm.cpp SearchLight.cpp)

TARGET_LINK_LIBRARIES(vsl ${VIAIO_LIBRARY}  ${LIPSIA_LIBRARY} ${GSL_GSL_LIBRARY} ${GSL_CBLAS_LIBRARY})

TARGET_LINK_LIBRARIES(vsvm ${VIAIO_LIBRARY} ${GSL_GSL_LIBRARY})
TARGET_LINK_LIBRARIES(vsvr ${VIAIO_LIBRARY} ${LIPSIA_LIBRARY} ${GSL_GSL_LIBRARY} ${GSL_CBLAS_LIBRARY})


INSTALL(TARGETS vsvm vsvr
	RUNTIME DESTINATION bin
	COMPONENT RuntimeLibraries)
