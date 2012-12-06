SkFunTips

----------------------------------
what is SkFunTips?

SkFunTips is a text post-process tool ,
which makes your text attractive and fun.
just like this:
S |__|e |__|  |__|e |__|r |__|j |__|
k |__|x |__|t |__|s |__|a |__|u |__|
F |__|t |__|o |__|  |__|c |__|s |__|
u |__|  |__|o |__|y |__|t |__|t |__|
n |__|p |__|l |__|o |__|i |__|  |__|
T |__|o |__|  |__|u |__|v |__|l |__|
i |__|s |__|, |__|r |__|e |__|i |__|
p |__|t |__|w |__|  |__|  |__|k |__|
s |__|- |__|h |__|t |__|a |__|e |__|
  |__|p |__|i |__|e |__|n |__|  |__|
i |__|r |__|c |__|x |__|d |__|t |__|
s |__|o |__|h |__|t |__|  |__|h |__|
  |__|c |__|  |__|  |__|f |__|i |__|
a |__|e |__|m |__|a |__|u |__|s |__|
  |__|s |__|a |__|t |__|n |__|: |__|
t |__|s |__|k |__|t |__|. |__||__|

or this:

                                                                          
                                                                                
                                                                                
                                                                                
            @ @   @   @ @             @ @ @ @ @ @                               
          @     @ @     @               @       @                               
          @             @   @ @ @       @   @     @ @     @ @                   
            @ @ @       @     @         @ @ @       @       @                   
                  @     @ @ @           @   @       @       @                   
                  @     @   @           @           @       @                   
          @ @     @     @     @         @           @     @ @                   
          @   @ @     @ @   @ @ @     @ @ @           @ @   @ @                 
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                      @ @ @ @ @ @ @       @                                     
                      @     @     @                                             
        @ @   @ @           @         @ @ @       @ @   @ @                     
          @ @     @         @             @         @ @     @                   
          @       @         @             @         @       @                   
          @       @         @             @         @       @                   
          @       @         @             @         @       @                   
        @ @ @   @ @ @     @ @ @       @ @ @ @ @     @ @ @ @                     
                                                    @                           
                                                  @ @ @                         
                                                                                

																				
by just a simple click, you can also use this tool to 
generate a picture or gif animation quickly.

how to compile :
CMake,qt4(core and gui),giflib5,boost(header-only) is required
extract source to a folder(suppose skfuntips)
and make a sibling build folder(suppose skfuntips-build)
chdir to skfuntips-build,run

cmake ../skfuntips 

then type make to compile

finally ,copy generated *.qm files to bin/(for i18n)

tips:giflib4 has a bug which can not generate correct 1-bit depth gif.
giflib5(which breaks v4 API) is required. most distro only has 
giflib4-devel lib, and you need to compile giflib5 yourself
https://sourceforge.net/projects/giflib/files/giflib-5.x/

then tell cmake to find giflib5 in your install dir

cmake ../skipfuntips -DGIF_INCLUDE_DIR=/usr/local/include -DGIF_LIBRARY=/usr/local/libgif.a
(replace /usr/local to your install dir)

used 3rd library
encdet https://github.com/spiritloose/encdet
encdet is a CJK charset detect library from Mozilla-firefox
its automake based build system is not windows-friendly
I write a simple CMake script for it and include its source here


how to customize:

src/KeywordsDB.txt for internal keywordsDB,
every words(per line) will be used as 'keywords' in keywords process

src/HighlightDB.txt for internal highlightDB,
every regexp(per line) will be used for text result highlight
this function can warn you that you don't want some words in result text