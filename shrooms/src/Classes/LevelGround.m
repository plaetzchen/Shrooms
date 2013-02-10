//
//  LevelGround.m
//  Shrooms
//
//  Created by Philip Brechler on 10.02.13.
//
//

#import "LevelGround.h"

@implementation LevelGround

@synthesize groundImage;

- (id)initWithParts:(NSArray *)parts slots:(NSArray *)slots {
    self = [super init];
    if (self){
        
        for (int i=0; i<parts.count; ++i)
        {
            SPImage *image = [parts objectAtIndex:i];
            image.x = i * 1440;
            image.y = 0;
            [self addChild:image];
        }
        
    }
    return self;
}
@end
