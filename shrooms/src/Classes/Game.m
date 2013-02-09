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
		mContents.rotation = SP_D2R(90);
		mContents.x = 320;
		[self addChild:mContents];
		[mContents release];
//		sky = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"sky.png"]
//                                                    speed:0.4
//                                                direction:BE_PARALLAX_DIRECTION_LEFT];
//		[mContents addChild:sky];
//		forest1 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"mountainsback.png"]
//                                                           speed:2
//                                                       direction:BE_PARALLAX_DIRECTION_LEFT];
//		[mContents addChild:forest1];
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
        

        
    }
    return self;
}

- (void)oneFingerTouch {
    SPQuad *oneQuad = [[SPQuad alloc]initWithWidth:50 height:50 color:SP_COLOR(255, 0, 0)];
    [self addChild:oneQuad];
}

- (void)swipeUp {
    SPQuad *oneQuad = [[SPQuad alloc]initWithWidth:50 height:50 color:SP_COLOR(0, 255, 0)];
    [self addChild:oneQuad];}


@end
