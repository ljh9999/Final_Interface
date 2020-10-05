add_library(svip_action SHARED svip_action.cpp)
ADD_LIBRARY(wrapper
        SHARED
        svip_action.cpp
        ../src/md5.cpp
        )


