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
//        mContents = [[SPSprite alloc] init];
//		mContents.x = 0;
//        [mContents setWidth:self.width];
//        [mContents setHeight:self.height];
//		[self addChild:mContents];
//		[mContents release];
        
        MainMenu *menuScene = [[MainMenu alloc]init];
        [self showScene:menuScene];
        [menuScene release];
        
        SPSound *music = [SPSound soundWithContentsOfFile:@"GIANT_SQUID_MARCH_ON_WASHINGTON_-_00_-_1_-_fade__intro_.mp3"];
        mMusicChannel = [[music createChannel] retain];
        mMusicChannel.loop = YES;
        [music play];

        
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
    
    Level1 *levelScene = [[Level1 alloc]init];
    [self showScene:levelScene];
    [levelScene release];
}

- (void)showScene:(Scene *)scene {
    if ([self containsChild:currentScene]) {
        [self removeChild:currentScene];
    }
    [self addChild:scene];
    currentScene = scene;
}

@end
