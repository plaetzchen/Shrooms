//
//  Level1.m
//  Shrooms
//
//  Created by Philip Brechler on 09.02.13.
//
//

#import "Level1.h"

@implementation Level1

- (id)init {
    self = [super init];
    if (self){
        forest1 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"bg.png"] speed:0.8 direction:BE_PARALLAX_DIRECTION_LEFT];
		[self addChild:forest1];
        
        grass = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"level-ground-1.png"] speed:10 direction:BE_PARALLAX_DIRECTION_LEFT];
        
        [self addChild:grass];
        
        bear = [[Bear alloc]init];
        [bear setY:self.height*0.4];
        [bear setScaleX:0.5f];
        [bear setScaleY:0.5f];
        [self addChild:bear];
        [self addEventListener:@selector(onAddedToStage:) atObject:self forType:SP_EVENT_TYPE_ADDED_TO_STAGE];
        [self addEventListener:@selector(onRemovedFromStage:) atObject:self forType:SP_EVENT_TYPE_REMOVED_FROM_STAGE];
    }
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
@end
