//
//  Game.m
//  AppScaffold
//

#import "Game.h" 

@implementation Game

@synthesize lastTimeTouched;

- (id)initWithWidth:(float)width height:(float)height
{
    if ((self = [super initWithWidth:width height:height]))
    {
        self.lastTimeTouched = [NSDate date];
        mContents = [[SPSprite alloc] init];
		mContents.x = 0;
        [mContents setWidth:self.width];
        [mContents setHeight:self.height];
		[self addChild:mContents];
		[mContents release];
        
//		sky = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"sky.png"]
//                                                    speed:0.4
//                                                direction:BE_PARALLAX_DIRECTION_LEFT];
//		[mContents addChild:sky];
		forest1 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"bg.png"] speed:1 direction:BE_PARALLAX_DIRECTION_LEFT];
		[mContents addChild:forest1];
        
//		forest2 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"mountainsfront.png"]
//                                                           speed:4
//                                                       direction:BE_PARALLAX_DIRECTION_LEFT];
//		[mContents addChild:forest2];
//        
//        forest3 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"mountainsfront.png"]
//                                                        speed:4
//                                                    direction:BE_PARALLAX_DIRECTION_LEFT];
//		[mContents addChild:forest3];
//        
//		grass = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"grass.png"]
//                                                      speed:10
//                                                  direction:BE_PARALLAX_DIRECTION_LEFT];
//		grass.y = 320-grass.height;
//		[mContents addChild:grass];
        
        bear = [[Bear alloc]init];
        [bear setY:self.height*0.2];
        [self addChild:bear];
        [self.juggler addObject:bear.bearMoving];

    }
    return self;
}


- (void)oneFingerTouch {
    [forest1 stop];
}

- (void)swipeUp {
    [forest1 start];
}

@end
