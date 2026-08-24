cmake_minimum_required(VERSION 3.15)
project(fxcraft LANGUAGES C ASM VERSION "05.00.0000")

include(GenerateG3A)
include(Fxconv)

set(SOURCES
  src/fxlibc_hal.c
  src/compression.c
  src/controls.c
  src/DMA_Transfer.c
  src/eninge.c
  src/fastBdisp.c
  src/lz4.c
  src/tlsf.c
  # ...
)
# Shared assets, fx-9860G-only assets and fx-CG-50-only assets
set(ASSETS
  # ...
)
set(ASSETS_fx
  # ...
)
set(ASSETS_cg
  # ...
)

configure_file(src/config.h.in include/config.h)
fxconv_declare_assets(${ASSETS} ${ASSETS_fx} ${ASSETS_cg} WITH_METADATA)

add_executable(fxcraft ${SOURCES} ${ASSETS} ${ASSETS_${FXSDK_PLATFORM}})
include_directories(fxcraft PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_BINARY_DIR}/include)
target_compile_options(fxcraft PRIVATE
  -fdata-sections -Ofast -fschedule-insns -w
  -flto=auto -fno-strict-aliasing -DNDEBUG
  -Wno-implicit-function-declaration
  -Wno-int-conversion
  -Wno-incompatible-pointer-types)

set(LINKER "${CMAKE_CURRENT_SOURCE_DIR}/prizm.ld")
target_link_options(fxcraft PRIVATE
  -L ${CMAKE_CURRENT_SOURCE_DIR} -T ${LINKER}
  -Wl,-print-memory-usage -Wl,-Map=map -Wl,-gc-sections)
target_link_libraries(fxcraft PRIVATE -lc -lgcc -lsyscall-${TARGET})

if("${FXSDK_PLATFORM_LONG}" STREQUAL fxCG50)
  generate_g3a(TARGET fxcraft OUTPUT "Minecraft-fx.g3a"
    NAME "Minecraft-fx" ICONS icon-uns.png icon-sel.png)
endif()
