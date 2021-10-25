file(REMOVE_RECURSE
  "../../../liblights_ispc.a"
  "../../../liblights_ispc.pdb"
  "ambient_light.dev.o"
  "ambient_light_ispc.h"
  "directional_light.dev.o"
  "directional_light_ispc.h"
  "light.dev.o"
  "light_ispc.h"
  "point_light.dev.o"
  "point_light_ispc.h"
  "quad_light.dev.o"
  "quad_light_ispc.h"
  "spot_light.dev.o"
  "spot_light_ispc.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/lights_ispc.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
