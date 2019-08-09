if(NOT CMAKE_BUILD_TYPE STREQUAL Debug)
	find_library(GOOGLE_TCMALLOC_LIB tcmalloc)
	if(GOOGLE_TCMALLOC_LIB)
		message(STATUS "Found tcmalloc: ${GOOGLE_TCMALLOC_LIB}")
		set(GOOGLE_TCMALLOC_ENABLED 1)
	else()
		message(STATUS "Can't find tcmalloc - skipping")
	endif()
endif()

macro(link_helper target)
	if(GOOGLE_TCMALLOC_ENABLED)
		target_link_libraries(${target} ${GOOGLE_TCMALLOC_LIB})
	endif()
endmacro()

add_executable(lang-detect
	lang-detect.cpp
	../cld2/internal/cld_generated_cjk_delta_bi_4.cc
	../cld2/internal/cld_generated_cjk_uni_prop_80.cc
	../cld2/internal/cld_generated_score_quad_octa_1024_256.cc
	../cld2/internal/cld2_generated_cjk_compatible.cc
	../cld2/internal/cld2_generated_deltaoctachrome.cc
	../cld2/internal/cld2_generated_distinctoctachrome.cc
	../cld2/internal/cld2_generated_quadchrome_2.cc
	../cld2/internal/cldutil.cc
	../cld2/internal/cldutil_shared.cc
	../cld2/internal/compact_lang_det.cc
	../cld2/internal/compact_lang_det_hint_code.cc
	../cld2/internal/compact_lang_det_impl.cc
	../cld2/internal/debug.cc
	../cld2/internal/fixunicodevalue.cc
	../cld2/internal/generated_distinct_bi_0.cc
	../cld2/internal/generated_entities.cc
	../cld2/internal/generated_language.cc
	../cld2/internal/generated_ulscript.cc
	../cld2/internal/getonescriptspan.cc
	../cld2/internal/lang_script.cc
	../cld2/internal/offsetmap.cc
	../cld2/internal/scoreonescriptspan.cc
	../cld2/internal/tote.cc
	../cld2/internal/utf8statetable.cc
)
link_helper(lang-detect)

add_executable(lang-filter
	lang-filter.cpp
	../cld2/internal/cld_generated_cjk_delta_bi_4.cc
	../cld2/internal/cld_generated_cjk_uni_prop_80.cc
	../cld2/internal/cld_generated_score_quad_octa_1024_256.cc
	../cld2/internal/cld2_generated_cjk_compatible.cc
	../cld2/internal/cld2_generated_deltaoctachrome.cc
	../cld2/internal/cld2_generated_distinctoctachrome.cc
	../cld2/internal/cld2_generated_quadchrome_2.cc
	../cld2/internal/cldutil.cc
	../cld2/internal/cldutil_shared.cc
	../cld2/internal/compact_lang_det.cc
	../cld2/internal/compact_lang_det_hint_code.cc
	../cld2/internal/compact_lang_det_impl.cc
	../cld2/internal/debug.cc
	../cld2/internal/fixunicodevalue.cc
	../cld2/internal/generated_distinct_bi_0.cc
	../cld2/internal/generated_entities.cc
	../cld2/internal/generated_language.cc
	../cld2/internal/generated_ulscript.cc
	../cld2/internal/getonescriptspan.cc
	../cld2/internal/lang_script.cc
	../cld2/internal/offsetmap.cc
	../cld2/internal/scoreonescriptspan.cc
	../cld2/internal/tote.cc
	../cld2/internal/utf8statetable.cc
)
link_helper(lang-filter)

add_executable(lang-filter-raw
	lang-filter-raw.cpp
	../cld2/internal/cld_generated_cjk_delta_bi_4.cc
	../cld2/internal/cld_generated_cjk_uni_prop_80.cc
	../cld2/internal/cld_generated_score_quad_octa_1024_256.cc
	../cld2/internal/cld2_generated_cjk_compatible.cc
	../cld2/internal/cld2_generated_deltaoctachrome.cc
	../cld2/internal/cld2_generated_distinctoctachrome.cc
	../cld2/internal/cld2_generated_quadchrome_2.cc
	../cld2/internal/cldutil.cc
	../cld2/internal/cldutil_shared.cc
	../cld2/internal/compact_lang_det.cc
	../cld2/internal/compact_lang_det_hint_code.cc
	../cld2/internal/compact_lang_det_impl.cc
	../cld2/internal/debug.cc
	../cld2/internal/fixunicodevalue.cc
	../cld2/internal/generated_distinct_bi_0.cc
	../cld2/internal/generated_entities.cc
	../cld2/internal/generated_language.cc
	../cld2/internal/generated_ulscript.cc
	../cld2/internal/getonescriptspan.cc
	../cld2/internal/lang_script.cc
	../cld2/internal/offsetmap.cc
	../cld2/internal/scoreonescriptspan.cc
	../cld2/internal/tote.cc
	../cld2/internal/utf8statetable.cc
)
link_helper(lang-filter-raw)

install(TARGETS lang-detect RUNTIME DESTINATION bin)
install(TARGETS lang-filter RUNTIME DESTINATION bin)
install(TARGETS lang-filter-raw RUNTIME DESTINATION bin)
