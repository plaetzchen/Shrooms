//
//  PointInPolygonChecker.h
//  Shrooms
//
//  Created by Jörg Bühmann on 09.02.13.
//
//

#import <Foundation/Foundation.h>

@interface PointInPolygonChecker : NSObject

@property (nonatomic, retain) NSArray* pointList;

-(id)initWithArray:(NSArray*) arrayOfPointDicts;

-(BOOL) checkIfPointInPolygon:(SPPoint *) point;
@end
