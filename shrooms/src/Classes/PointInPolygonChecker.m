//
//  PointInPolygonChecker.m
//  Shrooms
//
//  Created by Jörg Bühmann on 09.02.13.
//
//
/*  Based^W copied from the article on http://alienryderflex.com/polygon/
*   Doesn't include the optimizations
*/

#import "PointInPolygonChecker.h"

@interface PointInPolygonChecker(){
}

@property (nonatomic) int    polySides;
@property (nonatomic) SPPoint *testpoint;

@end

@implementation PointInPolygonChecker

-(id) init{
    self = [super init];
    if (self) {

    }
    return self;
}

-(id)initWithArray:(NSArray*) arrayOfPointDicts
{
    self = [self init];
    if (self) {
        self.pointList = arrayOfPointDicts;
        self.polySides = self.pointList.count;
    }
    return self;
}



-(BOOL) checkIfPointInPolygon:(SPPoint *) point
{
    self.testpoint = point;
    int numberOfPoints = [self.pointList count];
    float x[numberOfPoints];
    float y[numberOfPoints];
    NSDictionary* dict;
    for (int i = 0; i < self.pointList.count; i++) {
        dict = [self.pointList objectAtIndex:i];
        x[i] = [dict[@"x"] floatValue];
        y[i] = [dict[@"y"] floatValue];
    }

    
    return [self pointInPolygonWitX:x andY:y];
}


//  Globals which should be set before calling this function:
//
//  int    polySides  =  how many corners the polygon has
//  float  polyX[]    =  horizontal coordinates of corners
//  float  polyY[]    =  vertical coordinates of corners
//  float  x, y       =  point to be tested
//
//  (Globals are used in this example for purposes of speed.  Change as
//  desired.)
//
//  The function will return YES if the point x,y is inside the polygon, or
//  NO if it is not.  If the point is exactly on the edge of the polygon,
//  then the function may return YES or NO.
//
//  Note that division by zero is avoided because the division is protected
//  by the "if" clause which surrounds it.

-(BOOL) pointInPolygonWitX:(float*) polyX andY: (float*) polyY{
    float x = self.testpoint.x;
    float y = self.testpoint.y;
    
    
    int   i, j=_polySides-1 ;
    bool  oddNodes=NO      ;
    
    for (i=0; i<_polySides; i++) {
        if (polyY[i]<y && polyY[j]>=y
            ||  polyY[j]<y && polyY[i]>=y) {
            if (polyX[i]+(y-polyY[i])/(polyY[j]-polyY[i])*(polyX[j]-polyX[i])<x) {
                oddNodes=!oddNodes; }}
        j=i; }
    
    return oddNodes; }



@end
