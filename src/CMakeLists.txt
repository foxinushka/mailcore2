set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
if(WIN32)
  include(public-headers-win32)
else()
  include(public-headers)
endif()

include(core)
include(async)
include(objc)
include(LibFindMacros)

IF(APPLE)
  execute_process(COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/../scripts/get-mac.sh"
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../scripts")
ENDIF()

file(GLOB_RECURSE
  source_files
  *.h
  *.m
  *.c
)

SET_SOURCE_FILES_PROPERTIES(
  ${source_files}
  PROPERTIES LANGUAGE C
)

file(COPY
  ${public_headers}

  DESTINATION
  "${CMAKE_CURRENT_BINARY_DIR}/include/MailCore"
)

include_directories(
  "${CMAKE_CURRENT_BINARY_DIR}/include"
  ${async_includes}
  ${core_includes}
  ${objc_includes}
  ${additional_includes}
  ${GLIB2_INCLUDE_DIRS}
)

add_library(MailCore
  ${core_files}
  ${async_files}
  ${objc_files}
)

if(WIN32)
  target_compile_options(MailCore PRIVATE /GS- /Oy /Gw /Gy)
  target_link_options(MailCore PRIVATE /INCREMENTAL:NO)
  target_link_libraries(MailCore
                        PRIVATE
                          ${PTHREAD_LIBRARY}
                          ${LIBETPAN_LIBRARY}
                          ${CTEMPLATE_LIBRARY}
                          ${TIDY_LIBRARY}
                          ${LIBXML_LIBRARY}
                          ${OPENSSL_EAY_LIBRARY}
                          ${ZLIB_LIBRARY}
                          ${ICU4C_UC_LIBRARY}
                          ${ICU4C_IN_LIBRARY}
                          ws2_32
                          Crypt32
  )
endif()