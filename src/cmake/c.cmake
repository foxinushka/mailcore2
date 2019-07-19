file(GLOB c_files 
	c/abstract/*.cpp
	c/basetypes/*.cpp
	c/imap/*.cpp
	c/provider/*.cpp
	c/rfc822/*.cpp
	c/smtp/*.cpp
	c/utils/*.cpp
)

set(c_includes
  "${CMAKE_CURRENT_SOURCE_DIR}/c"
  "${CMAKE_CURRENT_SOURCE_DIR}/c/abstract"
  "${CMAKE_CURRENT_SOURCE_DIR}/c/basetypes"
  "${CMAKE_CURRENT_SOURCE_DIR}/c/imap"
  "${CMAKE_CURRENT_SOURCE_DIR}/c/rfc822"
  "${CMAKE_CURRENT_SOURCE_DIR}/c/utils"
)
