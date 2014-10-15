/**
 * @file filler.cpp
 * Implementation of functions in the filler namespace. Heavily based on
 * old MP4 by CS225 Staff, Fall 2010.
 * 
 * @author Chase Geigle
 * @date Fall 2012
 */
#include "filler.h"



//dfs <->stack




animation filler::dfs::fillSolid( PNG & img, int x, int y, 
        RGBAPixel fillColor, int tolerance, int frameFreq ) {
    


    solidColorPicker filler = solidColorPicker( fillColor );
    return fill(img, x, y, filler, tolerance, frameFreq);
}

animation filler::dfs::fillGrid( PNG & img, int x, int y, 
        RGBAPixel gridColor, int gridSpacing, int tolerance, int frameFreq ) {
    


    gridColorPicker filler = gridColorPicker( gridColor,  gridSpacing);
    return fill(img, x, y, filler, tolerance, frameFreq);
}

animation filler::dfs::fillGradient( PNG & img, int x, int y, 
        RGBAPixel fadeColor1, RGBAPixel fadeColor2, int radius, 
        int tolerance, int frameFreq ) {
    


    gradientColorPicker filler = gradientColorPicker(  fadeColor1, fadeColor2,  radius,  x,  y );
    return fill(img, x, y, filler, tolerance, frameFreq);
}

animation filler::dfs::fill( PNG & img, int x, int y, 
        colorPicker & fillColor, int tolerance, int frameFreq ) {
    
    return filler::fill<Stack>(img, x, y, fillColor, tolerance, frameFreq);
}





//bfs <-> queue



animation filler::bfs::fillSolid( PNG & img, int x, int y, 
        RGBAPixel fillColor, int tolerance, int frameFreq ) {
    

    solidColorPicker filler = solidColorPicker( fillColor );
    return fill(img, x, y, filler, tolerance, frameFreq);
}

animation filler::bfs::fillGrid( PNG & img, int x, int y, 
        RGBAPixel gridColor, int gridSpacing, int tolerance, int frameFreq ) {
    


    gridColorPicker filler = gridColorPicker( gridColor,  gridSpacing);
    return fill(img, x, y, filler, tolerance, frameFreq);
}

animation filler::bfs::fillGradient( PNG & img, int x, int y, 
        RGBAPixel fadeColor1, RGBAPixel fadeColor2, int radius, 
        int tolerance, int frameFreq ) {
    


    gradientColorPicker filler = gradientColorPicker(fadeColor1, fadeColor2,  radius,  x,  y );
    return fill(img, x, y, filler, tolerance, frameFreq);

}

animation filler::bfs::fill( PNG & img, int x, int y, 
        colorPicker & fillColor, int tolerance, int frameFreq ) {
    
    return filler::fill<Queue>(img, x, y, fillColor, tolerance, frameFreq);;
}




//now for the hard one :(

template <template <class T> class OrderingStructure>
animation filler::fill( PNG & img, int x, int y,
        colorPicker & fillColor, int tolerance, int frameFreq ) {
    /**
     * @todo You need to implement this function!
     *
     * This is the basic description of a flood-fill algorithm: Every fill
     * algorithm requires an ordering structure, which is passed to this
     * function via its template parameter. For a breadth-first-search
     * fill, that structure is a Queue, for a depth-first-search, that
     * structure is a Stack. To begin the algorithm, you simply place the
     * given point in the ordering structure. Then, until the structure is
     * empty, you do the following:
     *
     * 1.     Remove a point from the ordering structure. 
     *
     *        If it has not been processed before and if its color is
     *        within the tolerance distance (up to and **including**
     *        tolerance away in square-RGB-space-distance) to the original
     *        point's pixel color [that is, \f$(currentRed - OriginalRed)^2 +
              (currentGreen - OriginalGreen)^2 + (currentBlue -
              OriginalBlue)^2 \leq tolerance\f$], then: 
     *        1.    indicate somehow that it has been processed (do not mark it
     *              "processed" anywhere else in your code) 
     *        2.    change its color in the image using the appropriate
     *              colorPicker
     *        3.    add all of its neighbors to the ordering structure, and 
     *        4.    if it is the appropriate frame, send the current PNG to the
     *              animation (as described below).
     * 2.     When implementing your breadth-first-search and
     *        depth-first-search fills, you will need to explore neighboring
     *        pixels in some order.
     *
     *        While the order in which you examine neighbors does not matter
     *        for a proper fill, you must use the same order as we do for
     *        your animations to come out like ours! The order you should put
     *        neighboring pixels **ONTO** the queue or stack is as follows:
     *        **RIGHT(+x), DOWN(+y), LEFT(-x), UP(-y). IMPORTANT NOTE: *UP*
     *        here means towards the top of the image, so since an image has
     *        smaller y coordinates at the top, this is in the *negative y*
     *        direction. Similarly, *DOWN* means in the *positive y*
     *        direction.** To reiterate, when you are exploring (filling out)
     *        from a given pixel, you must first try to fill the pixel to
     *        it's RIGHT, then the one DOWN from it, then to the LEFT and
     *        finally UP. If you do them in a different order, your fill may
     *        still work correctly, but your animations will be different
     *        from the grading scripts!
     * 3.     For every k pixels filled, **starting at the kth pixel**, you
     *        must add a frame to the animation, where k = frameFreq. 
     *
     *        For example, if frameFreq is 4, then after the 4th pixel has
     *        been filled you should add a frame to the animation, then again
     *        after the 8th pixel, etc.  You must only add frames for the
     *        number of pixels that have been filled, not the number that
     *        have been checked. So if frameFreq is set to 1, a pixel should
     *        be filled every frame.
     */


    //declare ordering stuctures
    //one for x coordinate, one for y coordinate
    OrderingStructure <int> xCordStuct;
    OrderingStructure <int> yCordStruct;
    bool hasBeenChanged[img.width()][img.height()]; //declare a boolean 2d array for true or false to know if image is done.  
    //initialize the 2d array to fale
    for (int i = 0; i < img.width(); i++)
    {
        for (int j = 0; j < img.height(); j++)
        {
            hasBeenChanged[i][j] = false;
        }
    }



    //begin by pushing our starting point onto the stack
    xCordStuct.add(x);
    yCordStruct.add(y);


    //main while loop
    while(!xCordStuct.isEmpty() && !yCordStruct.isEmpty())//until the stack/queue (?) is empty
    {
        //begin by poping off what we want to work with
        int holder1 = xCordStuct.remove();
        int holder2 = yCordStruct.remove(); 

        int newTolerance = (img(holder1, holder2)->red - img(x,y)->red)^2 - (img(holder1, holder2)->green - img(x,y)->green)^2 - (img(holder1, holder2)->blue - img(x,y)->blue)^2;

        if(newTolerance <= tolerance && !hasBeenChanged[holder1][holder2] == true)
        {


            *img(holder1, holder2) = fillColor(holder1,holder2);
            hasBeenChanged[holder1][holder2] = true;


        }

        //check element to the right
        if(hasBeenChanged[holder1+1][holder2] == false)
        {
            xCordStuct.add(holder1+1);
            yCordStruct.add(holder2);
        }

        //now check element to the left
        if(hasBeenChanged[holder1-1][holder2] == false)
        {
            xCordStuct.add(holder1-1);
            yCordStruct.add(holder2);
        }
        //now check element above
        if(hasBeenChanged[holder1][holder2+1] == false)
        {
            xCordStuct.add(holder1);
            yCordStruct.add(holder2+1);
        }
        //now check element below
        if(hasBeenChanged[holder1][holder2-1] == false)
        {
            xCordStuct.add(holder1);
            yCordStruct.add(holder2-1);
        }



    }

    return animation();
}
