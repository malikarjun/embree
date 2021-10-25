file(REMOVE_RECURSE
  "../../../libnoise_ispc.a"
  "../../../libnoise_ispc.pdb"
  "noise.dev.o"
  "noise_ispc.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/noise_ispc.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
