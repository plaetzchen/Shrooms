//
//  Game.m
//  AppScaffold
//

#import "Game.h" 
#import "MainMenu.h"
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
        
        currentScene = [[MainMenu alloc]init];
        [self addChild:currentScene];
        
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(newgame:) name:@"newGamePressed" object:nil];

    }
    return self;
}


- (void)oneFingerTouch {
    [currentScene oneFingerTouched];
}

- (void)swipeUp {
    [currentScene swipeUp];
}

- (void)newgame:(NSNotification*)event {
    [self removeAllChildren];
    currentScene = [[Level1 alloc]init];
    [self addChild:currentScene];
}
@end
