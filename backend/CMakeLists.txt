include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(
    Pdfviewerbackend_SRCS
    modules/Pdfviewer/backend.cpp
    modules/Pdfviewer/PDFComponent.cpp
)

add_library(Pdfviewerbackend MODULE
    ${Pdfviewerbackend_SRCS}
)

set_target_properties(Pdfviewerbackend PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY Pdfviewer)

qt5_use_modules(Pdfviewerbackend Gui Qml Quick)

# Copy qmldir file to build dir for running in QtCreator
add_custom_target(Pdfviewerbackend-qmldir ALL
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/modules/Pdfviewer/qmldir ${CMAKE_CURRENT_BINARY_DIR}/Pdfviewer
    DEPENDS ${QMLFILES}
)

# Install plugin file
install(TARGETS Pdfviewerbackend DESTINATION ${QT_IMPORTS_DIR}/Pdfviewer/)
install(FILES   modules/Pdfviewer/qmldir DESTINATION ${QT_IMPORTS_DIR}/Pdfviewer/)

