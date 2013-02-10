//
//  LevelGround.m
//  Shrooms
//
//  Created by Philip Brechler on 10.02.13.
//
//

#import "LevelGround.h"

@implementation LevelGround

@synthesize  mCurStep;

@synthesize groundImage;

- (id)initWithParts:(NSArray *)parts slots:(NSArray *)slots speed:(float)speed{
    self = [super init];
    if (self){

        self.levelParts = [NSArray arrayWithArray:parts];
        mSpeed = speed;
        image1 = [[SPImage alloc]initWithContentsOfFile:[self.levelParts objectAtIndex:0]];
        [self addChild:image1 atIndex:0];
        
        image2 = [[SPImage alloc]initWithContentsOfFile:[self.levelParts objectAtIndex:1]];
        currentPart = 1;
        image2.x = image1.x+image1.width;
		[self addChild:image2 atIndex:0];
        
        [self addEventListener:@selector(onEnterFrame:) atObject:self forType:SP_EVENT_TYPE_ENTER_FRAME];
        running = YES;

    }
    return self;
}

- (void)onEnterFrame:(SPEnterFrameEvent *)event {
    if (running){
        mCurStep += mSpeed;
        image1.x -= floor(mCurStep);
        image2.x -= floor(mCurStep);
        if (image1.x <= -image1.width) {
            image1.x = image2.x+image2.width;
        }
        if (image2.x <= -image2.width) {
            image2.x = image1.x+image1.width;
        }
        mCurStep -= floor(mCurStep);
    }
}
@end
