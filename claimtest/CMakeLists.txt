#include_directories(${PROJECT_SOURCE_DIR})
#include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/libwallet   ${PROJECT_SOURCE_DIR}/claimtest ${PROJECT_SOURCE_DIR}/include )
link_directories(${PROJECT_BINARY_DIR}/lib)


#ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
message(STATUS "PROJECT_LIB_DIR="  ${PROJECT_BINARY_DIR}/lib )

find_package(OpenSSL)
if(NOT OPENSSL_FOUND)
  message(FATAL_ERROR "OpenSSL not found!")
endif(NOT OPENSSL_FOUND)

#FIND_PACKAGE(Boost COMPONENTS log boost_system boost_filesystem boost_program_options boost_thread  REQUIRED)
#if(NOT Boost_FOUND)
#  message(FATAL_ERROR "Boost log  not found!")
#endif(NOT Boost_FOUND)


message(STATUS "boost_LIB_DIR="  ${Boost_LIBRARIES})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(IMPORTLIB wallet secp256k1 ${OPENSSL_CRYPTO_LIBRARY} ${OPENSSL_SSL_LIBRARY}   ${Boost_LIBRARIES}
  boost_system boost_filesystem boost_program_options boost_thread   
  boost_log_setup db_cxx-4.8  pthread  m  
)
#secp256k1

file(GLOB CLAIM_HEADERS "*.h" )
file(GLOB CLAIM_SRC "*.cpp" )
#file(GLOB_RECURSE WALLET_SRC ${PROJECT_SOURCE_DIR}/claimtest/*.cpp)
add_executable(claimtest ${CLAIM_SRC} ${CLAIM_HEADERS})
target_link_libraries(claimtest ${IMPORTLIB})

