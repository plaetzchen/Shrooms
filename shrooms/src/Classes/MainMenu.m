//
//  MainMenu.m
//  Shrooms
//
//  Created by Philip Brechler on 10.02.13.
//
//

#import "MainMenu.h"

@implementation MainMenu

- (id)init {
    self = [super init];
    if (self){
        forest1 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"forest3.png"] speed:0.1 direction:BE_PARALLAX_DIRECTION_LEFT];
		[self addChild:forest1 atIndex:0];
        
        forest2 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"forest2.png"] speed:0.2 direction:BE_PARALLAX_DIRECTION_LEFT];
		[self addChild:forest2 atIndex:1];
        
        forest3 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"forest1.png"] speed:0.5 direction:BE_PARALLAX_DIRECTION_LEFT];
		[self addChild:forest3 atIndex:2];
        
        grass = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"shrooms-ground-0.png"] speed:1 direction:BE_PARALLAX_DIRECTION_LEFT];
		[self addChild:grass atIndex:3];
        
        CGRect screenFrame = [[UIScreen mainScreen] bounds];
        
        startButton = [[SPImage alloc]initWithContentsOfFile:@"btn-new_game.png"];
        startButton.x = (screenFrame.size.height/2)-(startButton.width/2);
        startButton.y = self.height*0.15;
        [self addChild:startButton atIndex:4];
        
        highscoreButton = [[SPImage alloc]initWithContentsOfFile:@"btn-highscore.png"];
        highscoreButton.x = (screenFrame.size.height/2)-(highscoreButton.width/2);
        highscoreButton.y = self.height*0.4;
        [self addChild:highscoreButton atIndex:4];
        
        credits = [[SPImage alloc]initWithContentsOfFile:@"credits.png"];
        credits.x = screenFrame.size.height-credits.width;
        credits.y = self.height - credits.height;
        [self addChild:credits atIndex:4];
        [startButton addEventListener:@selector(newgame:) atObject:self forType:SP_EVENT_TYPE_TOUCH];
    }
    return self;
}

- (void)newgame:(SPTouchEvent*)event {
    [[NSNotificationCenter defaultCenter] postNotificationName:@"newGamePressed" object:nil];
}

@end
