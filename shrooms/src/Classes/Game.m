//
//  Game.m
//  AppScaffold
//

#import "Game.h" 
#import "Level1.h"
@implementation Game


- (id)initWithWidth:(float)width height:(float)height
{
    if ((self = [super initWithWidth:width height:height]))
    {
        mContents = [[SPSprite alloc] init];
		mContents.x = 0;
        [mContents setWidth:self.width];
        [mContents setHeight:self.height];
		[self addChild:mContents];
		[mContents release];
        
        currentScene = [[Level1 alloc]init];
        [self addChild:currentScene];

    }
    return self;
}


- (void)oneFingerTouch {
    [currentScene oneFingerTouched];
}

- (void)swipeUp {
    [currentScene swipeUp];
}

@end
