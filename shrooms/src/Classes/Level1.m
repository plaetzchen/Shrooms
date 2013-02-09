//
//  Level1.m
//  Shrooms
//
//  Created by Philip Brechler on 09.02.13.
//
//

#import "Level1.h"

@implementation Level1

@synthesize collisionPoints;

- (id)init {
    self = [super init];
    if (self){
        forest1 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"bg.png"] speed:0.8 direction:BE_PARALLAX_DIRECTION_LEFT];
		[self addChild:forest1];
        
        grass = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"level-ground-1.png"] speed:1 direction:BE_PARALLAX_DIRECTION_LEFT];
        grass.y =- 160;
        [self addChild:grass];
        
        bear = [[Bear alloc]init];
        [bear setY:0];
        [bear setScaleX:0.5f];
        [bear setScaleY:0.5f];
        [self addChild:bear];
        [self addEventListener:@selector(onAddedToStage:) atObject:self forType:SP_EVENT_TYPE_ADDED_TO_STAGE];
        [self addEventListener:@selector(onRemovedFromStage:) atObject:self forType:SP_EVENT_TYPE_REMOVED_FROM_STAGE];
        
        self.collisionPoints = [NSArray arrayWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"level-ground-1" ofType:@"plist"]];
        
        currentPointIndex = 0;
        
    }
    
    [self addEventListener:@selector(onEnterFrame:) atObject:self forType:SP_EVENT_TYPE_ENTER_FRAME];
    return self;
}

- (void)onAddedToStage:(SPEvent *)event
{
    [self.stage.juggler addObject:bear.bearMoving];
}

- (void)onRemovedFromStage:(SPEvent *)event
{
    [self.stage.juggler removeObject:bear.bearMoving];
}

- (void)oneFingerTouched {
    [bear setRunning:YES];
    [forest1 start];
}

- (void)swipeUp {
    [bear jump];
    
}

- (void)onEnterFrame:(SPEnterFrameEvent *)event {

    NSDictionary* leftDict = self.collisionPoints[currentPointIndex];
    NSDictionary* rightDict = self.collisionPoints[currentPointIndex+1];
    CGPoint leftPoint = CGPointMake([leftDict[@"x"] floatValue], [leftDict[@"y"] floatValue]);
    CGPoint rightPoint = CGPointMake([rightDict[@"x"] floatValue], [rightDict[@"y"] floatValue]);

    CGPoint currentGrassPoint = CGPointMake(grass.bounds.x*-1,0);
    CGPoint bearFrontFootCheckPoint = CGPointMake(currentGrassPoint.x+bear.x+bear.width, bear.y+bear.height);
    
    CGFloat slope = ((rightPoint.y-leftPoint.y) / (rightPoint.x-leftPoint.x));
    CGFloat yOffSet = 0;
    if (slope == 0) {
        yOffSet = leftPoint.y;
    }
    else {
        yOffSet = leftPoint.y / (slope * leftPoint.x);
    }
    CGFloat yCheckPoint = bearFrontFootCheckPoint.x * slope + yOffSet;
    
    CGPoint checkPoint = CGPointMake(bearFrontFootCheckPoint.x, yCheckPoint);
    
    NSLog(@"slope: %f", slope);
    NSLog(@"BearFoot: %@", NSStringFromCGPoint(bearFrontFootCheckPoint));
    NSLog(@"Checkpoint: %@",NSStringFromCGPoint(checkPoint));
    
    CGFloat deltaBearFoot = bearFrontFootCheckPoint.y - checkPoint.y;
    
    if (deltaBearFoot < 0){
        NSLog(@"drüber");
    } else {
        NSLog(@"drunter");
    }
    
    if (currentPointIndex+2 == collisionPoints.count){
        currentPointIndex = 0;
    } else if (currentGrassPoint.x >= rightPoint.x){
        currentPointIndex++;
    }
}
@end
