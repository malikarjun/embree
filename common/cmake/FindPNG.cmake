## ======================================================================== ##
## Copyright 2009-2015 Intel Corporation                                    ##
##                                                                          ##
## Licensed under the Apache License, Version 2.0 (the "License");          ##
## you may not use this file except in compliance with the License.         ##
## You may obtain a copy of the License at                                  ##
##                                                                          ##
##     http://www.apache.org/licenses/LICENSE-2.0                           ##
##                                                                          ##
## Unless required by applicable law or agreed to in writing, software      ##
## distributed under the License is distributed on an "AS IS" BASIS,        ##
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. ##
## See the License for the specific language governing permissions and      ##
## limitations under the License.                                           ##
## ======================================================================== ##

FIND_PATH( PNG_INCLUDE_DIR NAMES png.h )
FIND_LIBRARY( PNG_LIBRARIES NAMES libpng)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PNG DEFAULT_MSG PNG_INCLUDE_DIR PNG_LIBRARY)

MARK_AS_ADVANCED(PNG_INCLUDE_DIR)
MARK_AS_ADVANCED(PNG_LIBRARIES)

