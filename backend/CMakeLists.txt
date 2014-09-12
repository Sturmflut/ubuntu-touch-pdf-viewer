include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(
    PDFViewerbackend_SRCS
    modules/PDFViewer/backend.cpp
    modules/PDFViewer/PDFComponent.cpp
)

add_library(PDFViewerbackend MODULE
    ${PDFViewerbackend_SRCS}
)

set_target_properties(PDFViewerbackend PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY PDFViewer)

qt5_use_modules(PDFViewerbackend Gui Qml Quick)
TARGET_LINK_LIBRARIES(PDFViewerbackend poppler-qt5)

# Copy qmldir file to build dir for running in QtCreator
add_custom_target(PDFViewerbackend-qmldir ALL
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/modules/PDFViewer/qmldir ${CMAKE_CURRENT_BINARY_DIR}/PDFViewer
    DEPENDS ${QMLFILES}
)

# Install plugin file
install(TARGETS PDFViewerbackend DESTINATION ${QT_IMPORTS_DIR}/PDFViewer/)
install(FILES   modules/PDFViewer/qmldir DESTINATION ${QT_IMPORTS_DIR}/PDFViewer/)

