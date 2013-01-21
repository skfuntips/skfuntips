qt4_add_resources(rcc r.qrc)

include_directories(${GIF_INCLUDE_DIR} ../encdet/include)

add_library(isp 
     IParam.h
     param/SeedParam.cpp
     param/IntRangeParam.cpp
     param/FontParam.cpp
     param/StringParam.cpp
     param/ImageListParam.cpp
     param/Frame.cpp
     IProcessor.h
     PinYinDB.cpp
     processor/AverageInsertProcessor.cpp
     Result.cpp
     KeywordsDB.cpp
     QtResource.cpp
     Gif.cpp
         processor/InsertProcessor.cpp
     processor/SimilarProcessor.cpp
     processor/ReverseProcessor.cpp
     processor/VerticalLayoutProcessor.cpp
     processor/KeywordsProcessor.cpp
     processor/ShuffleProcessor.cpp
     processor/PinYinProcessor.cpp
     processor/LevelSeedProcessor.cpp
     processor/LevelProcessor.cpp
     processor/ToImageProcessor.cpp
     processor/ToBigCharProcessor.cpp
     processor/EncryptProcessor.cpp
     processor/DeEncryptProcessor.cpp
     processor/OffsetProcessor.cpp
     CompositeResource.cpp
     processor/ToGifProcessor.cpp
     GifSaver.cpp
     ProcessorContainer.cpp
     CompositeResource.cpp
     hangChuLi.cpp
     HighlightDB.cpp
     ResultHighlighter.cpp
     ${rcc} 
     )


target_link_libraries(isp giflib encdet ${QT_LIBRARIES})
	 
add_subdirectory(cli)
add_subdirectory(gui)

get_target_property(srcs isp SOURCES)

set(abs_srcs)

foreach(rel IN LISTS srcs)
    get_filename_component(abs_path ${rel}
        ABSOLUTE)

    list(APPEND abs_srcs ${abs_path})

endforeach(rel)


set (FILES_TO_TRANSLATE ${FILES_TO_TRANSLATE} ${abs_srcs} PARENT_SCOPE)


