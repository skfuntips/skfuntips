######################################################################
# Automatically generated by qmake (2.01a) ?? ??? 8 16:37:43 2012
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . \
              encdet \
              giflib \
              i18n \
              src \
              test \
              util \
              encdet\include \
              encdet\src \
              src\gui \
              src\param \
              src\processor \
              test\gui_test
INCLUDEPATH += F:/project/me/px/. . encdet/include giflib

# Input
HEADERS += giflib/gif_hash.h \
           giflib/gif_lib.h \
           giflib/gif_lib_private.h \
           src/CompositeResource.h \
           src/def.h \
           src/Gif.h \
           src/GifSaver.h \
           src/hangChuLi.h \
           src/haXi.h \
           src/HighlightDB.h \
           src/IParam.h \
           src/IProcessor.h \
           src/KeywordsDB.h \
           src/PinYinDB.h \
           src/ProcessorContainer.h \
           src/QtResource.h \
           src/Result.h \
           src/ResultHighlighter.h \
           src/ResultType.h \
           test/AnimatedGifSaver.h \
           test/test_function.h \
           encdet/include/encdet.h \
           encdet/src/CharDistribution.h \
           encdet/src/JpCntx.h \
           encdet/src/nsBig5Prober.h \
           encdet/src/nsCharSetProber.h \
           encdet/src/nsCodingStateMachine.h \
           encdet/src/nscore.h \
           encdet/src/nsEscCharsetProber.h \
           encdet/src/nsEUCJPProber.h \
           encdet/src/nsEUCKRProber.h \
           encdet/src/nsEUCTWProber.h \
           encdet/src/nsGB2312Prober.h \
           encdet/src/nsHebrewProber.h \
           encdet/src/nsLatin1Prober.h \
           encdet/src/nsMBCSGroupProber.h \
           encdet/src/nsPkgInt.h \
           encdet/src/nsSBCharSetProber.h \
           encdet/src/nsSBCSGroupProber.h \
           encdet/src/nsSJISProber.h \
           encdet/src/nsUniversalDetector.h \
           encdet/src/nsUTF8Prober.h \
           encdet/src/prmem.h \
           src/gui/CompositeResourceWidget.h \
           src/gui/FontWidget.h \
           src/gui/gongJu.h \
           src/gui/IntRangeWidget.h \
           src/gui/MainFrame.h \
           src/gui/ParamListWidget.h \
           src/gui/ParamWidget.h \
           src/gui/ProcessThread.h \
           src/gui/ProcessWidget.h \
           src/gui/ResultWidget.h \
           src/gui/SeedWidget.h \
           src/gui/SourceWidget.h \
           src/param/FontParam.h \
           src/param/IntRangeParam.h \
           src/param/SeedParam.h \
           src/processor/AverageInsertProcessor.h \
           src/processor/InsertProcessor.h \
           src/processor/KeywordsProcessor.h \
           src/processor/LevelProcessor.h \
           src/processor/LevelSeedProcessor.h \
           src/processor/PinYinProcessor.h \
           src/processor/ReverseProcessor.h \
           src/processor/ShuffleProcessor.h \
           src/processor/SimilarProcessor.h \
           src/processor/ToBigCharProcessor.h \
           src/processor/ToGifProcessor.h \
           src/processor/ToImageProcessor.h \
           src/processor/VerticalLayoutProcessor.h \
           test/gui_test/CeShiLabel.h \
           test/gui_test/moBan.h \
           encdet/src/JISFreq.tab \
           encdet/src/Big5Freq.tab \
           encdet/src/EUCKRFreq.tab \
           encdet/src/EUCTWFreq.tab \
           encdet/src/GB2312Freq.tab
FORMS += src/gui/AboutDialog.ui \
         src/gui/CompositeResourceWidget.ui \
         src/gui/FontWidget.ui \
         src/gui/IntRangeWidget.ui \
         src/gui/MainFrame.ui \
         src/gui/ParamListWidget.ui \
         src/gui/ProcessWidget.ui \
         src/gui/ResultWidget.ui \
         src/gui/SeedWidget.ui \
         src/gui/SourceWidget.ui
SOURCES += encdet/encdet.c \
           giflib/dgif_lib.c \
           giflib/egif_lib.c \
           giflib/gif_err.c \
           giflib/gif_font.c \
           giflib/gif_hash.c \
           giflib/gifalloc.c \
           giflib/quantize.c \
           src/CompositeResource.cpp \
           src/Gif.cpp \
           src/GifSaver.cpp \
           src/hangChuLi.cpp \
           src/HighlightDB.cpp \
           src/KeywordsDB.cpp \
           src/PinYinDB.cpp \
           src/ProcessorContainer.cpp \
           src/QtResource.cpp \
           src/Result.cpp \
           src/ResultHighlighter.cpp \
           test/all_cli.cpp \
           test/AnimatedGifSaver.cpp \
           test/gif_bao_cun_ce_shi.cpp \
           test/hang_duan_kai_ce_shi.cpp \
           test/main.cpp \
           test/qu_chu_huan_hang_ce_shi.cpp \
           test/test_function.cpp \
           test/zheng_shu_fan_wei_ce_shi.cpp \
           test/zheng_ze_ce_shi.cpp \
           test/zhong_zi_ce_shi.cpp \
           util/so.cpp \
           util/to_tl.cpp \
           encdet/src/CharDistribution.cpp \
           encdet/src/encdet.cpp \
           encdet/src/JpCntx.cpp \
           encdet/src/LangBulgarianModel.cpp \
           encdet/src/LangCyrillicModel.cpp \
           encdet/src/LangGreekModel.cpp \
           encdet/src/LangHebrewModel.cpp \
           encdet/src/LangHungarianModel.cpp \
           encdet/src/LangThaiModel.cpp \
           encdet/src/nsBig5Prober.cpp \
           encdet/src/nsCharSetProber.cpp \
           encdet/src/nsEscCharsetProber.cpp \
           encdet/src/nsEscSM.cpp \
           encdet/src/nsEUCJPProber.cpp \
           encdet/src/nsEUCKRProber.cpp \
           encdet/src/nsEUCTWProber.cpp \
           encdet/src/nsGB2312Prober.cpp \
           encdet/src/nsHebrewProber.cpp \
           encdet/src/nsLatin1Prober.cpp \
           encdet/src/nsMBCSGroupProber.cpp \
           encdet/src/nsMBCSSM.cpp \
           encdet/src/nsSBCharSetProber.cpp \
           encdet/src/nsSBCSGroupProber.cpp \
           encdet/src/nsSJISProber.cpp \
           encdet/src/nsUniversalDetector.cpp \
           encdet/src/nsUTF8Prober.cpp \
           src/gui/CompositeResourceWidget.cpp \
           src/gui/FontWidget.cpp \
           src/gui/gongJu.cpp \
           src/gui/IntRangeWidget.cpp \
           src/gui/main.cpp \
           src/gui/MainFrame.cpp \
           src/gui/ParamListWidget.cpp \
           src/gui/ParamWidget.cpp \
           src/gui/ProcessWidget.cpp \
           src/gui/ResultWidget.cpp \
           src/gui/SeedWidget.cpp \
           src/gui/SourceWidget.cpp \
           src/param/FontParam.cpp \
           src/param/IntRangeParam.cpp \
           src/param/SeedParam.cpp \
           src/processor/AverageInsertProcessor.cpp \
           src/processor/InsertProcessor.cpp \
           src/processor/KeywordsProcessor.cpp \
           src/processor/LevelProcessor.cpp \
           src/processor/LevelSeedProcessor.cpp \
           src/processor/PinYinProcessor.cpp \
           src/processor/ReverseProcessor.cpp \
           src/processor/ShuffleProcessor.cpp \
           src/processor/SimilarProcessor.cpp \
           src/processor/ToBigCharProcessor.cpp \
           src/processor/ToGifProcessor.cpp \
           src/processor/ToImageProcessor.cpp \
           src/processor/VerticalLayoutProcessor.cpp \
           test/gui_test/shu_ru_kong_jian_ce_shi.cpp \
           test/gui_test/zheng_shu_fan_wei_kong_jian_ce_shi.cpp \
           test/gui_test/zhong_zi_kong_jian_ce_shi.cpp \
           test/gui_test/zi_ti_kong_jian_ce_shi.cpp
RESOURCES += src/r.qrc
TRANSLATIONS += i18n/zh_CN.ts

OTHER_FILES += \
    android/AndroidManifest.xml \
    android/res/drawable/icon.png \
    android/res/drawable/logo.png \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/res/layout/splash.xml \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/version.xml
