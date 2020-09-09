cmake_minimum_required (VERSION 3.12)
project (mailcore2
		LANGUAGES 
		C CXX) 

if(APPLE)
  set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
  set(CMAKE_EXE_LINKER_FLAGS "-lc++ -stdlib=libc++")
  
  set(additional_lib_searchpath
    "${CMAKE_CURRENT_SOURCE_DIR}/Externals/ctemplate-osx/lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/Externals/libetpan-osx/lib"
  )
  
  execute_process(COMMAND xcrun --sdk macosx --show-sdk-path OUTPUT_VARIABLE sdkpath)
  string(STRIP "${sdkpath}" sdkpath)
  set(additional_includes
    "${CMAKE_CURRENT_SOURCE_DIR}/Externals/ctemplate-osx/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/Externals/libetpan-osx/include"
    /usr/include/tidy
    /usr/include/libxml2
    "${sdkpath}/usr/include/tidy"
    "${sdkpath}/usr/include/libxml2"
  )
  
  set(mac_libraries iconv)
  
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(CMAKE_CXX_FLAGS "-std=gnu++0x")
  
  set(additional_includes
    /usr/include/tidy
    /usr/include/libxml2
  )
  
  set(icu_libraries icudata icui18n icuio icule iculx icutest icutu icuuc)
  set(linux_libraries ${icu_libraries} pthread uuid)
elseif(WIN32)
  set(CMAKE_CXX_STANDARD 11)
  add_compile_definitions(_HAS_CONDITIONAL_EXPLICIT=0)
  set(BUILD_SHARED_LIBS ON)
  set(additional_includes
    "${CMAKE_CURRENT_SOURCE_DIR}/Externals/include"
  )
  set(additional_lib_searchpath
    "${CMAKE_CURRENT_SOURCE_DIR}/Externals/lib64"
  )
endif()

message(STATUS "Additional includes: ${additional_includes}")
message(STATUS "Additional lib search path: ${additional_lib_searchpath}")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  find_package(PkgConfig)
  pkg_check_modules (GLIB2 glib-2.0)
ENDIF()

IF(APPLE)
    find_library(FOUNDATIONFRAMEWORK NAMES Foundation)
    find_library(SECURITYFRAMEWORK NAMES Security)
    find_library(CORESERVICESFRAMEWORK NAMES CoreServices)
ENDIF()

if(NOT APPLE)
  

  # detect icu

  find_path(ICU4C_INCLUDE_DIR
    NAMES unicode/utf8.h
    PATHS ${additional_includes}
  )

  if(WIN32)
    find_library(ICU4C_UC_LIBRARY
      NAMES icuuc
      PATHS ${additional_lib_searchpath}
    )
    find_library(ICU4C_IN_LIBRARY
      NAMES icuin
      PATHS ${additional_lib_searchpath}
    )

    if(NOT ICU4C_INCLUDE_DIR OR NOT ICU4C_UC_LIBRARY OR NOT ICU4C_IN_LIBRARY)
      message(FATAL_ERROR "ERROR: Could not find ICU4C")
    else()
      message(STATUS "Found ICU4C")
    endif()

  else()
    find_library(ICU4C_LIBRARY
      NAMES icudata icui18n icuio icule iculx icutest icutu icuuc
      PATHS ${additional_lib_searchpath}
    )

    if(NOT ICU4C_INCLUDE_DIR OR NOT ICU4C_LIBRARY)
      message(FATAL_ERROR "ERROR: Could not find ICU4C")
    else()
      message(STATUS "Found ICU4C")
    endif()
  endif() # WIN32

  include_directories(${ICU4C_INCLUDE_DIR})
endif()

if(ANDROID)
  message(STATUS "Android platform")
else()


  # detect ctemplate

  find_path(CTEMPLATE_INCLUDE_DIR
    NAMES ctemplate/template.h
    PATHS ${additional_includes}
  )
  find_library(CTEMPLATE_LIBRARY
    NAMES ctemplate libctemplate
    PATHS ${additional_lib_searchpath}
  )

  if(NOT CTEMPLATE_INCLUDE_DIR OR NOT CTEMPLATE_LIBRARY)
    message(FATAL_ERROR "ERROR: Could not find ctemplate")
  else()
    message(STATUS "Found ctemplate")
  endif()
  include_directories(${CTEMPLATE_INCLUDE_DIR})


  # detect libetpan

  find_path(LIBETPAN_INCLUDE_DIR
    NAMES libetpan/libetpan.h
    PATHS ${additional_includes}
  )
  find_library(LIBETPAN_LIBRARY
    NAMES etpan libetpan
    PATHS ${additional_lib_searchpath}
  )

  if(NOT LIBETPAN_INCLUDE_DIR OR NOT LIBETPAN_LIBRARY)
    message(FATAL_ERROR "ERROR: Could not find libetpan")
  else()
    message(STATUS "Found libetpan")
  endif()

  include_directories(${LIBETPAN_INCLUDE_DIR})


  # detect tidy

  find_path(TIDY_INCLUDE_DIR
    NAMES tidy.h tidy/tidy.h
    PATHS ${additional_includes}
  )
  find_library(TIDY_LIBRARY
    NAMES tidy rdtidy
    PATHS ${additional_lib_searchpath}
  )

  if(NOT TIDY_INCLUDE_DIR OR NOT TIDY_LIBRARY)
    message(FATAL_ERROR "ERROR: Could not find tidy")
  else()
    message(STATUS "Found tidy")
  endif()

  include_directories(${TIDY_INCLUDE_DIR})


  # detect libxml2

  find_path(LIBXML_INCLUDE_DIR
    NAMES libxml/xmlreader.h libxml2/libxml/xmlreader.h
    PATHS ${additional_includes}
  )
  find_library(LIBXML_LIBRARY
    NAMES xml2 libxml2s
    PATHS ${additional_lib_searchpath}
  )

  if(NOT LIBXML_INCLUDE_DIR OR NOT LIBXML_LIBRARY)
    message(FATAL_ERROR "ERROR: Could not find libxml2")
  else()
    message(STATUS "Found libxml2")
  endif()

  if(WIN32 AND LIBXML_INCLUDE_DIR MATCHES ".*/include")
    set(LIBXML_INCLUDE_DIR "${LIBXML_INCLUDE_DIR}/libxml2")
    message(STATUS "Fixed libxml2 path: ${LIBXML_INCLUDE_DIR}")
  endif()

  include_directories(${LIBXML_INCLUDE_DIR})


  # detect zlib

  find_path(ZLIB_INCLUDE_DIR
    NAMES zlib.h
    PATHS ${additional_includes}
  )
  find_library(ZLIB_LIBRARY
    NAMES z zlib
    PATHS ${additional_lib_searchpath}
  )

  if(NOT ZLIB_INCLUDE_DIR OR NOT ZLIB_LIBRARY)
    message(FATAL_ERROR "ERROR: Could not find zlib")
  else()
    message(STATUS "Found zlib")
  endif()

  include_directories(${ZLIB_INCLUDE_DIR})


  if(WIN32)


    # detect OpenSSL

    find_path(OPENSSL_INCLUDE_DIR
      NAMES openssl/opensslv.h
      PATHS ${additional_includes}
    )
    find_library(OPENSSL_EAY_LIBRARY
      NAMES libeay32MD
      PATHS ${additional_lib_searchpath}
    )

    if(NOT OPENSSL_INCLUDE_DIR OR NOT OPENSSL_EAY_LIBRARY)
      message(FATAL_ERROR "ERROR: Could not find OpenSSL")
    else()
      message(STATUS "Found OpenSSL")
    endif()

    include_directories(${OPENSSL_INCLUDE_DIR})


    # detect dispatch

    find_path(DISPATCH_INCLUDE_DIR
      NAMES dispatch/dispatch.h
      HINTS ENV PATH
      PATHS ${additional_includes}
    )
    find_library(DISPATCH_LIBRARY
      NAMES dispatch
      PATHS ${additional_lib_searchpath}
    )
	find_library(DISPATCH_BLOCKS_LIBRARY
      NAMES BlocksRuntime
      PATHS ${additional_lib_searchpath}
    )

    if(NOT DISPATCH_INCLUDE_DIR OR NOT DISPATCH_LIBRARY)
      message(FATAL_ERROR "ERROR: Could not find dispatch")
    else()
      message(STATUS "Found dispatch")
    endif()

	if(NOT DISPATCH_BLOCKS_LIBRARY)
      message(FATAL_ERROR "ERROR: Could not find blocks runtime")
    else()
      message(STATUS "Found blocks runtime")
    endif()

    include_directories(${DISPATCH_INCLUDE_DIR})
    
  else()


    # detect uuid

    find_path(UUID_INCLUDE_DIR
      NAMES uuid/uuid.h
      PATHS ${additional_includes}
    )

    if(NOT UUID_INCLUDE_DIR)
      message(FATAL_ERROR "ERROR: Could not find uuid")
    else()
      message(STATUS "Found uuid")
    endif()

  endif() # WIN32

endif() # Android platform

add_subdirectory (src)
if (NOT WIN32)
  add_subdirectory (tests)
  add_subdirectory (unittest)
endif()
