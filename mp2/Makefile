EXENAME = testscene
EXENAME2 = testimage


OBJS = testscene.o scene.o image.o png.o rgbapixel.o 
OBJS2 = testimage.o image.o rgbapixel.o png.o  


CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

$(EXENAME2) : $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o $(EXENAME2)

testscene.o: testscene.cpp scene.o png.o rgbapixel.o image.o
	$(CXX) $(CXXFLAGS) testscene.cpp	

scene.o : scene.cpp scene.h image.h 
	$(CXX) $(CXXFLAGS) scene.cpp

testimage.o : testimage.cpp image.o png.o rgbapixel.o
	$(CXX) $(CXXFLAGS) testimage.cpp

image.o : image.cpp image.h png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) image.cpp

png.o : png.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) rgbapixel.cpp

clean :
	-rm -f *.o $(EXENAME) $(EXENAME2)
